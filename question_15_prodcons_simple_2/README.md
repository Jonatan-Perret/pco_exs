# Question 15 — Producteurs-consommateurs


Nous désirons réaliser un tampon simple dont le fonctionnement implique que chaque donnée
qui y est placée doit être consommée par 2 consommateurs. L’interface de ce buffer sera la
suivante :

            template<typename T> class Buffer2Conso : public
                AbstractBuffer<T> {
            public:
                Buffer2Conso();

                 virtual ~Buffer2Conso();

                 virtual void put(T item);
                 virtual T get(void);
            };


Trois types de solution peuvent être proposées, exploitant :
  1. Des sémaphores
  2. Des variables de condition
  3. Un moniteur de Hoare
Un squelette de code est présent ici :


