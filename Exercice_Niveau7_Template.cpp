/******************************************************************************
 *
 *       Fichier d'Exercices – Spécialisation Problèmes Inverses Linéaires
 *
 *  Objectif: Développer une boîte à outils pour la résolution de problèmes
 *            inverses de la forme `d = Gm`, où `d` sont les données observées,
 *            `m` le modèle à retrouver, et `G` l'opérateur "direct" (forward).
 *            Cette série se concentre sur les solveurs directs et itératifs pour
 *            les systèmes sur- ou sous-déterminés, et l'introduction de la
 *            régularisation pour traiter les problèmes mal-posés.
 * 
 *  Auteur : @Kribet Naoufal
 *
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <numeric>
#include <concepts>     // C++20

// Incluez vos propres bibliothèques d'algèbre linéaire des exercices précédents
// #include "Vecteur.hpp"
// #include "Matrice.hpp"

// Pour les exercices avancés, vous pourriez avoir besoin de :
// #include <Eigen/Dense> // Une bibliothèque de référence pour comparer vos résultats

// =========================================================================
// PARTIE 1 : PROBLÈMES BIEN POSÉS ET SYSTÈMES CARRÉS
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 1 : Rappel sur les Solveurs Directs
// -------------------------------------------------------------------------
/*
 *  Objectif: Consolider la base : la résolution de systèmes carrés inversibles.
 *
 *  Concepts: Décomposition LU, Décomposition de Cholesky.
 *
 *  Tâche: Assurez-vous d'avoir une classe `Matrice` fonctionnelle.
 *         - Implémentez un solveur basé sur la décomposition LU (déjà vu).
 *         - Implémentez un solveur basé sur la décomposition de Cholesky,
 *           spécialisé pour les matrices symétriques définies positives.
 *           Cette méthode est significativement plus rapide et plus stable.
 */
void exercice1() {
    std::cout << "--- DEBUT EXERCICE 1 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 1 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 2 : Solveurs Itératifs pour Systèmes Creux
// -------------------------------------------------------------------------
/*
 *  Objectif: Résoudre de très grands systèmes `Ax = b` où la matrice A est
 *            majoritairement remplie de zéros (typique en discrétisation d'EDP).
 *
 *  Concepts: Matrice creuse, Méthode du Gradient Conjugué (CG).
 *
 *  Tâche: Créez une classe pour représenter une matrice creuse (par exemple, au
 *         format CSR - Compressed Sparse Row). Puis, implémentez l'algorithme
 *         du Gradient Conjugué pour résoudre `Ax = b` où A est symétrique
 *         définie positive. Cet algorithme ne nécessite que des produits
 *         matrice-vecteur, ce qui est très efficace avec un stockage creux.
 */
void exercice2() {
    std::cout << "--- DEBUT EXERCICE 2 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 2 ---\n\n";
}

// =========================================================================
// PARTIE 2 : PROBLÈMES SUR-DÉTERMINÉS ET MOINDRES CARRÉS
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 3 : Régression Linéaire (Équations Normales)
// -------------------------------------------------------------------------
/*
 *  Objectif: Trouver la "meilleure" solution d'un système `Ax = b` qui n'a pas
 *            de solution exacte (plus d'équations que d'inconnues).
 *
 *  Concepts: Problème des moindres carrés, équations normales, pseudo-inverse.
 *
 *  Tâche: Écrivez une fonction `moindresCarres(A, b)` qui résout le problème
 *         `min ||Ax - b||²`. Pour cela, formez les équations normales
 *         `(A^T A) x = A^T b`. Le système `A^T A` est carré et symétrique,
 *         vous pouvez donc le résoudre avec votre solveur de Cholesky.
 *         Testez en ajustant une droite à un nuage de points bruité.
 */
void exercice3() {
    std::cout << "--- DEBUT EXERCICE 3 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 3 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 4 : Stabilité Numérique (Décomposition QR)
// -------------------------------------------------------------------------
/*
 *  Objectif: Résoudre le problème des moindres carrés de manière numériquement
 *            plus stable que les équations normales, qui peuvent être mal conditionnées.
 *
 *  Concepts: Décomposition QR, Algorithme de Gram-Schmidt.
 *
 *  Tâche: Implémentez la factorisation QR d'une matrice A via le procédé de
 *         Gram-Schmidt modifié. Une fois que `A = QR` (où Q est orthogonale et
 *         R est triangulaire supérieure), le problème `min ||Ax - b||²` se
 *         simplifie en la résolution du système triangulaire `Rx = Q^T b`.
 *         Implémentez ce solveur et comparez sa précision à celui des équations normales.
 */
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 4 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 5 : L'Approche Spectrale (Décomposition en Valeurs Singulières - SVD)
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser l'outil le plus puissant de l'algèbre linéaire pour
 *            analyser et résoudre n'importe quel système linéaire.
 *
 *  Concepts: Décomposition en Valeurs Singulières (SVD), valeurs singulières,
 *            vecteurs singuliers, conditionnement, pseudo-inverse de Moore-Penrose.
 *
 *  Tâche: Implémentez (ou, de manière plus réaliste, écrivez un wrapper pour une
 *         routine SVD d'une bibliothèque comme Eigen/LAPACK) un algorithme qui
 *         calcule la SVD d'une matrice A (`A = U S V^T`).
 *         Utilisez la SVD pour calculer le pseudo-inverse `A^+ = V S^+ U^T` et
 *         ainsi trouver la solution des moindres carrés `x = A^+ b`. La SVD est
 *         l'outil ultime pour diagnostiquer les problèmes inverses.
 */
void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 5 ---\n\n";
}

// =========================================================================
// PARTIE 3 : PROBLÈMES MAL-POSÉS ET RÉGULARISATION
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 6 : Le Problème Mal-Posé
// -------------------------------------------------------------------------
/*
 *  Objectif: Comprendre comment un bruit infime dans les données peut être
 *            amplifié de manière catastrophique dans la solution d'un problème
 *            mal conditionné.
 *
 *  Concepts: Conditionnement d'une matrice, amplification du bruit.
 *
 *  Tâche: Construisez une matrice de Hilbert (un exemple classique de matrice
 *         extrêmement mal conditionnée). Résolvez le système `Hx = b` pour un `b`
 *         connu. Ensuite, ajoutez un bruit très faible à `b` (ex: 1e-10) pour
 *         créer `b_bruite`. Résolvez `Hx' = b_bruite` et observez la différence
 *         dramatique entre `x` et `x'`.
 */
void exercice6() {
    std::cout << "--- DEBUT EXERCICE 6 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 6 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 7 : Régularisation de Tikhonov (Ridge Regression)
// -------------------------------------------------------------------------
/*
 *  Objectif: Introduire de l'information a priori dans le problème pour le
 *            stabiliser et obtenir une solution physiquement plausible.
 *
 *  Concepts: Régularisation, paramètre de régularisation (λ), compromis biais-variance.
 *
 *  Tâche: Modifiez votre solveur par équations normales pour résoudre le
 *         problème régularisé de Tikhonov : `min ||Ax - b||² + λ² ||x||²`.
 *         La solution est donnée par `(A^T A + λ² I) x = A^T b`.
 *         Appliquez ce solveur au problème de l'exercice 6 et observez comment
 *         la solution redevient stable, même avec des données bruitées,
 *         en faisant varier le paramètre λ.
 */
void exercice7() {
    std::cout << "--- DEBUT EXERCICE 7 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 7 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 8 : Régularisation par SVD Tronquée
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser la SVD pour filtrer les composantes de la solution les
 *            plus sensibles au bruit.
 *
 *  Concepts: Espace modèle, espace données, filtrage spectral.
 *
 *  Tâche: Reprenez votre solveur basé sur la SVD. Au lieu d'inverser toutes
 *         les valeurs singulières dans `S^+`, ne gardez que les `k` plus grandes
 *         et mettez les autres à zéro. Cela revient à "tronquer" la décomposition.
 *         Observez comment le choix de `k` permet de contrôler la régularisation.
 */
void exercice8() {
    std::cout << "--- DEBUT EXERCICE 8 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 8 ---\n\n";
}

// =========================================================================
// PARTIE 4 : APPLICATIONS
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 9 : Déconvolution d'Image 1D
// -------------------------------------------------------------------------
/*
 *  Objectif: Appliquer les techniques d'inversion pour restaurer un signal flouté.
 *
 *  Concepts: Convolution, matrice de Toeplitz, déconvolution.
 *
 *  Tâche:
 *      1. Générez un signal 1D simple (ex: un créneau).
 *      2. Créez un noyau de convolution (ex: un flou gaussien).
 *      3. Représentez l'opération de convolution comme une multiplication
 *         matrice-vecteur `d = Gm`, où `G` est une matrice de Toeplitz.
 *      4. Ajoutez du bruit à `d`.
 *      5. Résolvez le problème inverse `m = (G^T G + λ² I)^-1 G^T d` pour
 *         retrouver le signal original `m` à partir du signal bruité `d`.
 */
void exercice9() {
    std::cout << "--- DEBUT EXERCICE 9 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 9 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 10 : L'Algorithme CGLS
// -------------------------------------------------------------------------
/*
 *  Objectif: Implémenter un algorithme itératif qui résout le problème des
 *            moindres carrés régularisés sans jamais former explicitement les
 *            matrices `G^T G` ou `G^T d`, ce qui est crucial pour les très
 *            grands problèmes.
 *
 *  Concepts: Méthode du gradient conjugué sur les équations normales (CGLS).
 *
 *  Tâche: Implémentez l'algorithme CGLS (Conjugate Gradient for Least Squares).
 *         Cet algorithme ne requiert que la capacité de calculer des produits
 *         `G*v` et `G^T*w`. Il est donc extrêmement puissant pour les problèmes
 *         où l'opérateur `G` n'est pas une matrice mais une fonction qui
 *         simule un processus physique.
 */
void exercice10() {
    std::cout << "--- DEBUT EXERCICE 10 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 10 ---\n\n";
}


// =========================================================================
// LE GROS PROBLÈME FINAL : Tomographie Sismique 2D Linéarisée
// =========================================================================
/*
 *  Objectif: Synthétiser toutes les compétences pour résoudre un problème
 *            inverse canonique en géophysique.
 *
 *  Description:
 *      Estimez la carte des vitesses du sous-sol à partir des temps d'arrivée
 *      de rayons sismiques.
 *      1.  **Le Problème Direct :** Discrétisez un domaine 2D en cellules. La
 *          lenteur (inverse de la vitesse) est constante dans chaque cellule.
 *          Simulez le trajet de plusieurs rayons sismiques (lignes droites pour
 *          simplifier) traversant ce milieu. Pour chaque rayon, le temps de
 *          trajet total est la somme des `longueur_segment * lenteur_cellule`.
 *          Ceci forme un grand système linéaire `d = Gm`, où `d` sont les temps
 *          de trajet, `m` le vecteur des lenteurs de toutes les cellules, et `G`
 *          une matrice creuse géante où `G(i,j)` est la longueur du rayon `i`
 *          dans la cellule `j`.
 *      2.  **La Matrice G :** Écrivez une fonction qui construit la matrice `G`.
 *          Cette matrice est immense et très creuse.
 *      3.  **Le Problème Inverse :** Générez un modèle de lenteur synthétique,
 *          calculez les temps de trajet `d`, puis ajoutez-y du bruit.
 *      4.  **La Résolution :** En utilisant les `d` bruitées, résolvez le
 *          problème inverse `min ||Gm - d||² + λ² ||Lm||²`, où `L` est un
 *          opérateur de régularisation (ex: un Laplacien discret qui favorise
 *          les solutions lisses). Utilisez un algorithme itératif comme CGLS
 *          car `G` est trop grosse pour être stockée et inversée directement.
 *      5.  **Visualisation :** Écrivez le modèle de lenteur retrouvé dans un
 *          fichier pour le visualiser et le comparer au modèle original.
 */
void grosProblemeFinal() {
    std::cout << "--- DEBUT DU PROJET DE TOMOGRAPHIE ---\n\n";
    std::cout << "\n--- FIN DU PROJET DE TOMOGRAPHIE ---\n\n";
}


// =========================================================================
// Le programme principal (main)
// =========================================================================
int main() {
    std::cout << "*****************************************************\n";
    std::cout << "*     TEMPLATE - PROBLÈMES INVERSES LINÉAIRES       *\n";
    std::cout << "*****************************************************\n\n";

    // Décommentez la ligne de l'exercice sur lequel vous voulez travailler.
    // exercice1();

    return 0;
}