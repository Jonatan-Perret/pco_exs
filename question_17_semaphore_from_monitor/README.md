# Question 17 — Sémaphore par moniteur


Réaliser un sémaphore faible grâce à :
  1. Des variables de conditions
  2. Un moniteur de Hoare
Un sémaphore faible n’a pas besoin de respecter un ordre FIFO pour sa file d’attente. Les
threads en attentes peuvent donc être relâchés dans un ordre quelconque (ceci simplifie quelque
peu la solution).
Le sémaphore aura l’interface suivante :

            class SemaphoreFromMonitor
            {
            public:
                SemaphoreFromMonitor(unsigned int initValue);
                ~SemaphoreFromMonitor();

                 void wait();
                 void post();
                 bool trywait(); //! Same as wait, but won’t block. Returns
                     true if the semaphore value was strictly positive,
                     false else
            };


Un squelette de code est présent ici :


