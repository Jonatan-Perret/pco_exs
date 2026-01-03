# Question 10 — Verrou-sémaphore


Réaliser un verrou à base de sémaphores. La sémantique du verrou doit évidemment être
préservée. Si un verrou est déjà déverouillé et que la fonction unlock() est appelée, alors
cet appel ne doit pas avoir d’effet. Afin de simplifier le problème, il n’est pas nécessaire de
garantir un ordre de réveil des threads. Le verrou aura l’interface suivante :

            class MutexFromSem
            {
            public:
                MutexFromSem();
                ~MutexFromSem();

                 void lock();
                 void unlock();
                 bool trylock(); //! Returns true if the mutex was
                     successfully acquired, otherwise returns false without
                     waiting if it is already locked
            };


Un squelette de code est présent ici :




