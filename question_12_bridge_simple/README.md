# Question 12 — Coordination


Nous désirons contrôler l’accès à un pont suspendu. Ce pont est capable de supporter un poids
de maxWeight tonnes. Une voiture pèse 1 tonne, et un camion 10 tonnes. En considérant que
les voitures et camions arrivant devant le pont sont modélisés par des threads, et que le pont
est une ressource critique, écrire le code permettant la gestion correcte de l’accès au pont.
L’interface du gestionnaire de pont doit être la suivante. Le nombre maxWeight de tonnes
supportées par le pont est passé en paramètre du constructeur.

            class BridgeManager
            {
            public:
                BridgeManager(unsigned int maxWeight);
                ~BridgeManager();

                 void carAccess();
                 void truckAccess();
                 void carLeave();
                 void truckLeave();
            }


Trois types de solution peuvent être proposées, exploitant :
  1. Des sémaphores
  2. Des variables condition
  3. Un moniteur de Hoare


Un squelette de code est présent ici :


