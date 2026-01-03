# Question 6 — Séquentialité


Soit le graphe d’exécution des tâches suivant :

                                                      T0


                                         T1



                              T3         T4                T5   T2



                                         T6


                                                      T7


Les tâches doivent exécuter leur traitement dans l’ordre indiqué par les flèches. En l’occurence
la tâche T 0 doit être terminée avant que T 1 et T 2 ne commencent.
  1. Ecrire un programme permettant de garantir ce fonctionnement, en utilisant la fonction
     PcoThread::join().
  2. Faire de même, en utilisant des sémaphores pour la synchronisation.

Un squelette de code est présent ici :


