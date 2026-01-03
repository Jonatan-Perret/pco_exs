# Question 1: Exclusion mutuelle


Problème 1 : Soit la séquence d’instructions suivante :

            void fonction() {
                int nombre=0;
                for(int i=0;i<10;i++)
                    nombre++;
                printf("Nombre: %d\n",nombre);
            }


Si deux threads sont lancés concurremment avec cette fonction à exécuter, quelles sont les valeurs affichées possibles en fin d’exécution ?
Problème 2 : Même question, mais avec le code suivant :

            void fonction() {
                static int nombre=0;
                for(int i=0;i<10;i++)
                    nombre++;
                printf("Nombre: %d\n",nombre);
            }




# Question 2: Exclusion mutuelle



            static int nombre;

            void threadA() {
                nombre=0;
                nombre++;
                printf("Nombre: %d\n",nombre);
            }

            void threadB() {
                nombre=1;
                nombre*=2;
                printf("Nombre: %d\n",nombre);
            }


Si ces fonctions sont exécutées de manière concurrente, quelles sont les valeurs possibles de nombre en fin d’exécution ?

# Question 3: Exclusion mutuelle


Soit les deux tâches T0 et T1 données sur le code suivant et devant réaliser l’exclusion mutuelle
dans leur section critique.

         1   static bool intention[2] = {false,false};
         2   static int tour = 0; // ou 1
         4   void T0()
         5   {
         6       while (true) {
         7           intention[0] = true;
         8           while (tour != 0) {
         9               while (intention[1])
        10                   ;
        11               tour = 0;
        12           }
        13           /* section critique */
        14           intention[0] = false;
        15           /* section non-critique */
        16       }
        17   }
        18
        19   void T1()
        20   {
        21       while (true) {
        22           intention[1] = true;
        23           while (tour != 1) {
        24               while (intention[0])
        25                   ;
        26               tour = 1;
        27           }
        28           /* section critique */
        29           intention[1] = false;
        30           /* section non-critique */
        31       }
        32   }


L’exclusion mutuelle est-elle garantie par les parties prélude et postlude des tâches ? Justifiez
votre réponse.
Le code peut être récupéré ici :




# Question 4: Verrous


Commentez la différence entre les deux codes suivants :

            void taskA() {
                PcoMutex mutex;
                mutex.lock();
                std::cout << "Section critique" << std::endl;
                mutex.unlock();
            }


            void taskB() {
                static PcoMutex mutex;
                mutex.lock();
                std::cout << "Section critique" << std::endl;
                mutex.unlock();
            }