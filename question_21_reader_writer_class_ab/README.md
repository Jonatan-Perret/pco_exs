# Question 21 — Lecteurs-rédacteurs


Une application est composée de threads de deux classes, A et B. Une ressource est partagée
entre tous les threads, selon les contraintes suivantes :
  1. Les threads de classe A peuvent accéder concurrement à la ressource.
  2. Les threads de classe B peuvent accéder concurrement à la ressource.
  3. Les threads de différente classe ne peuvent accéder à la ressource au même instant.
Proposer un algorithme permettant de gérer l’accès à la ressource, en s’inspirant des solutions
du chapitre. Considérez une solution où la coalition est possible entre threads d’une même
classe.
Trois types de solution peuvent être proposées, exploitant :
  1. Des sémaphores
  2. Des variables de condition
  3. Un moniteur de Hoare
Un squelette de code est présent ici :

                                              11
