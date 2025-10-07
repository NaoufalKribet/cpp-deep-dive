/******************************************************************************
 *
 *        Fichier d'Exercices – Spécialisation Calcul Scientifique en C++
 *
 *  Objectif: Maîtriser les techniques fondamentales de la programmation C++
 *            pour le calcul haute performance (HPC). Cette série se concentre sur
 *            la création d'outils d'algèbre linéaire génériques et performants,
 *            l'implémentation d'algorithmes numériques, et l'optimisation de bas
 *            niveau via la parallélisation et la vectorisation.
 * 
 *  Auteur : @Kribet Naoufal
 *
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>        // Pour les fonctions mathématiques (sqrt, sin, cos...)
#include <complex>      // Pour le type std::complex<T>
#include <chrono>       // Pour mesurer la performance
#include <stdexcept>
#include <numeric>      // Pour std::iota
#include <functional>
#include <concepts>     // C++20, essentiel pour contraindre les types numériques

// Pour les exercices avancés, vous pourriez avoir besoin de :
// #include <omp.h>     // Pour OpenMP (parallélisation)
// #include <immintrin.h> // Pour les intrinsèques SIMD (AVX)

// =========================================================================
// PARTIE 1 : FONDATIONS D'ALGÈBRE LINÉAIRE
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 1 : Le Vecteur Mathématique Statique
// -------------------------------------------------------------------------
/*
 *  Objectif: Créer une classe de base pour les opérations vectorielles qui
 *            exploite l'allocation sur la pile pour une performance maximale.
 *
 *  Concepts: Templates (type et non-type), allocation sur la pile, surcharge d'opérateurs.
 *
 *  Tâche: Créez une classe template `Vecteur<typename T, size_t N>`.
 *         - Elle doit stocker ses N éléments de type T dans un `std::array<T, N>`.
 *         - Surchargez les opérateurs `+`, `-`, `*` (scalaire) et `/` (scalaire).
 *         - Implémentez des méthodes pour le produit scalaire et la norme euclidienne.
 *         - L'accès aux éléments doit se faire via `operator[]`.
 */
void exercice1() {
    std::cout << "--- DEBUT EXERCICE 1 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 1 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 2 : La Matrice Statique et Générique
// -------------------------------------------------------------------------
/*
 *  Objectif: Construire un type Matrice performant et "typesafe".
 *
 *  Concepts: Templates (multiples non-types), stockage Row-Major, accès aux éléments.
 *
 *  Tâche: Créez une classe template `Matrice<typename T, size_t Rows, size_t Cols>`.
 *         - Le stockage des données doit être un `std::array<T, Rows * Cols>`.
 *         - Implémentez `operator()` pour l'accès aux éléments (ex: `mat(i, j)`).
 *           Cette méthode est préférable à `operator[]` pour les accès 2D.
 *         - Écrivez des constructeurs pour l'initialiser à zéro ou avec une valeur.
 */
void exercice2() {
    std::cout << "--- DEBUT EXERCICE 2 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 2 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 3 : Opérations Matricielles
// -------------------------------------------------------------------------
/*
 *  Objectif: Compléter l'algèbre de base de votre classe Matrice.
 *
 *  Concepts: Multiplication Matrice-Vecteur, Multiplication Matrice-Matrice.
 *
 *  Tâche: Surchargez les opérateurs de multiplication pour votre classe Matrice:
 *         - `Vecteur<T, Rows> operator*(const Matrice<T, Rows, Cols>&, const Vecteur<T, Cols>&)`
 *         - `Matrice<T, R1, C2> operator*(const Matrice<T, R1, C1>&, const Matrice<T, C1, C2>&)`
 *           Notez l'utilisation des templates pour garantir la validité des dimensions à la compilation.
 */
void exercice3() {
    std::cout << "--- DEBUT EXERCICE 3 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 3 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 4 : "Expression Templates"
// -------------------------------------------------------------------------
/*
 *  Objectif: Éliminer la création d'objets temporaires dans les chaînes
 *            d'opérations (ex: `D = A + B + C`) pour atteindre des performances
 *            équivalentes au code C ou Fortran écrit à la main.
 *
 *  Concepts: Méta-programmation, templates, surcharge d'opérateurs avancée.
 *
 *  Tâche: Modifiez vos classes Vecteur/Matrice. Les opérateurs `+` et `-` ne
 *         doivent plus retourner un objet Vecteur/Matrice, mais un objet "Expression"
 *         léger qui stocke des références aux opérandes. L'évaluation de
 *         l'expression (le calcul réel) ne doit se produire qu'au moment de
 *         l'assignation, dans un unique passage en boucle.
 */
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 4 ---\n\n";
}


// =========================================================================
// PARTIE 2 : ALGORITHMES NUMÉRIQUES FONDAMENTAUX
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 5 : Résolution de Systèmes Linéaires
// -------------------------------------------------------------------------
/*
 *  Objectif: Implémenter un solveur direct pour les systèmes d'équations `Ax = b`.
 *
 *  Concepts: Décomposition LU, pivotage partiel, substitution avant/arrière.
 *
 *  Tâche: Écrivez une fonction `resoudreSysteme(Matrice A, Vecteur b)` qui
 *         retourne le vecteur solution `x`. Cette fonction doit d'abord calculer
 *         la décomposition LU de la matrice A, puis résoudre les deux systèmes
 *         triangulaires Ly = b et Ux = y.
 */
void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 5 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 6 : Intégration d'Équations Différentielles Ordinaires (EDO)
// -------------------------------------------------------------------------
/*
 *  Objectif: Simuler l'évolution d'un système dynamique décrit par `y' = f(t, y)`.
 *
 *  Concepts: Méthodes de Runge-Kutta (RK4), std::function, pas de temps.
 *
 *  Tâche: Écrivez une fonction `integrerRK4` qui prend en entrée une fonction
 *         `f(t, y)`, un état initial `y0`, et un intervalle de temps `[t0, tf]`.
 *         Elle doit retourner l'état final `yf`. Testez votre intégrateur sur un
 *         système simple comme l'oscillateur harmonique.
 */
void exercice6() {
    std::cout << "--- DEBUT EXERCICE 6 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 6 ---\n\n";
}

// =========================================================================
// PARTIE 3 : OPTIMISATION ET PARALLÉLISATION
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 7 : Vectorisation SIMD
// -------------------------------------------------------------------------
/*
 *  Objectif: Exploiter les instructions vectorielles du CPU (SSE, AVX) pour
 *            effectuer des opérations sur plusieurs données en un seul cycle d'horloge.
 *
 *  Concepts: SIMD (Single Instruction, Multiple Data), intrinsèques, alignement mémoire.
 *
 *  Tâche: Réécrivez l'addition de votre classe `Vecteur` en utilisant des
 *         intrinsèques AVX (`_mm256_*`). Comparez la performance avec la version
 *         scalaire (boucle simple) pour de grands vecteurs.
 */
void exercice7() {
    std::cout << "--- DEBUT EXERCICE 7 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 7 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 8 : Parallélisation Multi-Thread (OpenMP)
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser tous les cœurs du CPU pour accélérer les calculs "parallélisables".
 *
 *  Concepts: OpenMP, pragmas (`#pragma omp parallel for`), réduction.
 *
 *  Tâche: Prenez votre multiplication Matrice-Matrice de l'exercice 3.
 *         Parallélisez la (ou les) boucle(s) externe(s) en utilisant OpenMP.
 *         Mesurez le gain en performance (speedup) en fonction du nombre de threads.
 */
void exercice8() {
    std::cout << "--- DEBUT EXERCICE 8 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 8 ---\n\n";
}

// =========================================================================
// PARTIE 4 : INTEROPÉRABILITÉ ET C++ MODERNE
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 9 : Interfaçage avec BLAS/LAPACK
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser des bibliothèques Fortran/C hautement optimisées depuis
 *            le C++, une pratique standard dans le calcul scientifique.
 *
 *  Concepts: extern "C", ABI, link avec des bibliothèques externes.
 *
 *  Tâche: Écrivez un wrapper C++ pour la routine `dgemm` de BLAS (multiplication
 *         de matrices double précision). Votre fonction C++ doit prendre vos
 *         objets `Matrice` en entrée, extraire les pointeurs vers leurs données,
 *         et appeler la fonction C/Fortran `dgemm_`.
 */
void exercice9() {
    std::cout << "--- DEBUT EXERCICE 9 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 9 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 10 : Contraintes avec les Concepts (C++20)
// -------------------------------------------------------------------------
/*
 *  Objectif: Rendre le code générique plus sûr, plus lisible et produire des
 *            messages d'erreur de compilation clairs.
 *
 *  Concepts: `requires`, `std::floating_point`, concepts personnalisés.
 *
 *  Tâche: Reprenez vos classes `Vecteur` et `Matrice`. Définissez un concept
 *         `IsArithmetic` et contaignez le type `T` de vos templates avec ce concept.
 *         Créez un concept `IsMatrix` et réécrivez vos fonctions d'opérations
 *         matricielles pour qu'elles n'acceptent que des types respectant ce concept.
 */
void exercice10() {
    std::cout << "--- DEBUT EXERCICE 10 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 10 ---\n\n";
}

// =========================================================================
// LE GROS PROBLÈME FINAL : Simulateur N-Corps Gravitationnel
// =========================================================================
/*
 *  Objectif: Synthétiser l'ensemble des compétences acquises pour créer une
 *            simulation physique complète, performante et précise.
 *
 *  Description:
 *      Simulez l'évolution d'un système de N corps (planètes, étoiles) sous
 *      l'effet de la gravitation universelle.
 *      1.  **Structure de Données (SoA) :** Stockez les propriétés des corps
 *          (position, vitesse, masse) dans une structure de type "Struct of Arrays"
 *          pour optimiser l'utilisation du cache lors des calculs.
 *      2.  **Calcul de Force :** La boucle principale calcule, à chaque pas de
 *          temps, la force gravitationnelle exercée sur chaque corps par tous
 *          les autres. Cette boucle (N^2) est le goulot d'étranglement : elle
 *          doit être parallélisée (OpenMP).
 *      3.  **Intégration Temporelle :** Utilisez un intégrateur numérique (comme
 *          votre RK4 de l'exercice 6, ou un simple Leapfrog) pour mettre à jour
 *          la position et la vitesse de chaque corps en fonction de l'accélération
 *          calculée.
 *      4.  **Généricité :** Le simulateur doit être templatisé pour fonctionner
 *          en 2D ou 3D et avec différentes précisions (float, double).
 *      5.  **Sortie :** Le programme doit générer des fichiers de données à chaque
 *          pas de temps, visualisables par un outil externe (Python/matplotlib, Gnuplot).
 */
void grosProblemeFinal() {
    std::cout << "--- DEBUT DU SIMULATEUR N-CORPS ---\n\n";
    std::cout << "\n--- FIN DU SIMULATEUR N-CORPS ---\n\n";
}

// =========================================================================
// Le programme principal (main)
// =========================================================================
int main() {
    std::cout << "*****************************************************\n";
    std::cout << "*     TEMPLATE D'EXERCICES - CALCUL SCIENTIFIQUE    *\n";
    std::cout << "*****************************************************\n\n";

    // Décommentez la ligne de l'exercice sur lequel vous voulez travailler.
    // exercice1();

    return 0;
}