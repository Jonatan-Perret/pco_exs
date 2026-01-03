# Question 19 — Lecteurs-rédacteurs


Lors du dernier festival Baleinev, un souci technique a impliqué que les toilettes hommes se
sont retrouvées fermées. Ne pouvant pas tolérer que les hommes et les femmes partagent les
même toilettes, il a fallut gérer l’accès à ce précieux local en garantissant qu’il n’y avait pas
possibilité d’avoir des hommes et des femmes en même temps dans celui-ci.
Ce ne fut pas une mince affaire.
Afin de choisir la meilleure manière de gérer un tel scénario l’année prochaine, l’équipe de
Baleinev vous demande de modéliser différentes politiques de gestion des accès.
  a. Les femmes sont prioritaires sur les hommes s’il y a déjà des femmes aux toilettes
  b. Les femmes ont la priorité sur les hommes
   c. Les personnes sont gérées selon leur ordre d’arrivée
  d. Après un maximum de N femmes, c’est aux hommes d’y accéder, et après un maximum
     de N hommes, c’est aux femmes

                                               10
Les toilettes disposent d’un nombre de places limitées, vous vous en doutez. Pour votre solution,
vous allez implémenter une sous-classe de AbstractToilet. Le nombre de places disponibles
aux toilettes est directement passé au constructeur.

            class AbstractToilet {
            public:
                AbstractToilet(int nbSeats) : nbSeats(nbSeats) {};
                virtual void manAccessing() = 0;
                virtual void manLeaving() = 0;
                virtual void womanAccessing() = 0;
                virtual void womanLeaving() = 0;

            protected:
                int nbSeats;
            }


Trois types de solution peuvent être proposées, exploitant :
  1. Des sémaphores
  2. Des variables de condition
  3. Un moniteur de Hoare
Un squelette de code est présent ici :


