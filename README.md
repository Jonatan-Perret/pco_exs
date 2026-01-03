# Exercices de Programmation Concurrente (PCO)

Exercices de programmation concurrente pour le semestre automne 2025-2026, HEIG-VD.

**Professeurs:** Yann Thoma, Alberto Dassatti  
**Assistant:** Florian Vaussard

## Description

Ce dépôt contient une collection d'exercices pratiques couvrant les concepts fondamentaux de la programmation concurrente en C++, incluant l'exclusion mutuelle, la synchronisation et la coordination entre threads.

## Structure du Projet

Chaque exercice est organisé dans un répertoire dédié avec la structure suivante:
```
question_XX_nom/
├── README.md          # Énoncé de l'exercice
└── code/
    ├── CMakeLists.txt # Configuration CMake
    ├── *.cpp          # Fichiers source
    ├── *.h            # Fichiers d'en-tête
    └── build/         # Répertoire de build (ignoré par git)
```

## Liste des Exercices

1. **Exclusion mutuelle** - Problèmes de base d'exclusion mutuelle
5. **Synchronisation** - Synchronisation de threads
6. **Séquentialité (1)** - Exercices de séquentialité avec joins et sémaphores
7. **Séquentialité (2)** - Suite des exercices de séquentialité
8. **Séquentialité (3)** - Séquentialité avancée
9. **Séquentialité (4)** - Derniers exercices de séquentialité
10. **Mutex depuis sémaphore** - Implémentation d'un mutex à partir d'un sémaphore
11. **Barrière** - Implémentation de barrières (sémaphores, moniteurs, variables de condition)
12. **Pont simple** - Problème du pont à sens unique
13. **Pont flottant** - Problème du pont avec capacité variable
14. **Pont flottant avec arrêt** - Extension avec arrêt de véhicules
15. **Producteur-consommateur simple** - Buffer à 2 consommateurs
16. **Producteur-consommateur multiple** - Buffer multi-consommateurs
17. **Sémaphore depuis moniteur** - Implémentation d'un sémaphore à partir d'un moniteur
18. **Preloader** - Système de préchargement
19. **Toilettes** - Problème de synchronisation des toilettes
20. **Lecteur-rédacteur avec priorité** - Priorité aux rédacteurs
21. **Lecteur-rédacteur classe A/B** - Classification des accès

## Compilation et Exécution

### Prérequis
- CMake (version 3.10 ou supérieure)
- Compilateur C++ compatible C++11 ou supérieur
- PcoSynchro library (pour les primitives de synchronisation)

### Compiler un exercice

```bash
cd question_XX_nom/code
mkdir -p build
cd build
cmake ..
make
```

### Exécuter un exercice

```bash
./nom_du_test
```

## Documentation

Le fichier `pco-exercices.pdf` contient l'énoncé complet de tous les exercices.

## Outils de Développement

Les projets supportent:
- **CMake** pour la compilation
- **Qt Creator** (fichiers `.pro` fournis)

## Notes

- Les répertoires `build/` sont ignorés par Git
- Chaque exercice peut avoir plusieurs implémentations (sémaphores, moniteurs, variables de condition)
- Les fichiers README.md dans chaque exercice contiennent les énoncés détaillés

## Licence

Matériel pédagogique de la HEIG-VD pour le cours de Programmation Concurrente.
