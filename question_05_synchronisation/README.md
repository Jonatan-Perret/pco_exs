# Question 5 — Synchronisation


Nous désirons réaliser une application possédant 2 tâches. Le programme principal est en
charge de lancer les deux tâches. Une fois démarrées, les tâches doivent attendre un signal
du programme principal pour s’exécuter, ceci afin de garantir que toutes les tâches sont créées
avant qu’elles ne commencent effectivement leur traitement.
Comment résoudre le problème
  1. à l’aide de sémaphores ?
  2. à l’aide de mutex ?
Un squelette de code est présent ici :


