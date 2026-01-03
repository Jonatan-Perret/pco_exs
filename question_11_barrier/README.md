# Question 11 — Barrière de synchronisation


Nous sommes intéressés à la réalisation d’une barrière de synchronisation. Une telle barrière
fonctionne de la manière suivante :
Pour une barrière initialisée à N , les N − 1 threads faisant appel à la méthode arrive() seront
bloqués. Lorsque le N ème thread appel arrive(), tous les threads sont relâchés et peuvent
poursuivre leur exécution.
La barrière aura l’interface suivante :

            class PcoBarrier
            {
            public:
                PcoBarrier(unsigned int nbToWait);
                ~PcoBarrier();

                 void arrive();
            };


Trois types de solution peuvent être proposées, exploitant :
  1. Des sémaphores
  2. Des variables de condition
  3. Un moniteur de Hoare
Un squelette de code est présent ici :


