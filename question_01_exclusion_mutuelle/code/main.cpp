/** @file main.cpp
 *  @brief Tentative de protocole d'exclusion mutuelle
 *
 *  Cet exemple illustre une tentative de mettre en place de l'exclusion
 *  mutuelle par attente active. Il ne fonctionne effectivement pas
 *  correctement.
 *
 *  @author Yann Thoma
 *  @date 17.02.2017
 *  @bug Pas de bug connu
 */

#include <iostream>

#include <pcosynchro/pcothread.h>

static std::array<bool, 2> intention = {false,false};
static int tour = 0; // ou 1

void T0()
{
    for (int i = 0; i < 100000; i++) {
        intention[0] = true;
        while (tour != 0) {
            while (intention[1]) {
                ;
            }
            tour = 0;
        }
        /* section critique */
        intention[0] = false;
        /* section non-critique */
    }
}

void T1()
{
    for (int i = 0; i < 100000; i++) {
        intention[1] = true;
        while (tour != 1) {
            while (intention[0]) {
                ;
            }
            tour = 1;
        }
        /* section critique */
        intention[1] = false;
        /* section non-critique */
    }
}


int main(int /*argc*/, char */*argv*/[])
{
    PcoThread task0(T0);
    PcoThread task1(T1);

    task0.join();
    task1.join();

    return 0;
}
