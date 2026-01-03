# Question 18 — Préchargement


Dans le cadre d’un programme devant récupérer des informations d’un grand nombre de
fichiers lors d’une action spécifique de l’utilisateur, nous sommes intéressés à précharger ces
fichiers afin d’offrir une meilleure ergonomie à l’application. La classe gérant le chargement des
fichiers est SimpleLoader. Elle peut être utilisée telle quelle, mais nous sommes intéressés par
une nouvelle implémentation permettant de faire le chargement en tâche de fond.
Pour ce faire nous devons implémenter la classe ThreadedLoader.



            class Data;

            class ILoader
            {
            public:
                Data* getData() = 0;
            };

            class SimpleLoader : public ILoader
            {
            public:
                Data* getData();
            };

            class ThreadedLoader : public ILoader
            {
            public:
                ThreadedLoader();
                ~ThreadedLoader;

                 void startPreloading();
                 Data* getData();
            };


La fonction getData() de ThreadedLoader est exploitée tout au long du programme pour
accéder les données chargées. Cette fonction est potentiellement bloquante si les données ne
sont pas encore chargées. La fonction startPreloading() peut être appelée en début de
programme, et son rôle est de lancer un thread qui sera responsable de charger l’ensemble des
fichiers (non bloquante).
Le chargement réel des données est fait via l’appel de la méthode getData() de la classe
SimpleLoader depuis les méthodes de ThreadedLoader.
Attention, l’usage de startPreloading() n’est pas obligatoire, et dès lors getData() doit
gérer le chargement si celui-ci n’a pas été commencé. Le pointeur sur DataDescriptor retourné
par getData() sera censé contenir les informations récupérées (non géré dans l’exercice).
Trois types de solution peuvent être proposées, exploitant :
  1. Des sémaphores
  2. Des variables de condition
  3. Un moniteur de Hoare
Un squelette de code est présent ici :


