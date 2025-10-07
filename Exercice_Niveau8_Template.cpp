/******************************************************************************
 *
 *       Fichier d'Exercices – Spécialisation Réseaux de Neurones Profonds
 *
 *  Objectif: Construire une bibliothèque de réseaux de neurones ("neural network")
 *            à partir de zéro. Cette série se concentre sur l'implémentation des
 *            mécanismes fondamentaux : la propagation avant (forward pass),
 *            la rétropropagation du gradient (backpropagation), et les
 *            algorithmes d'optimisation (descente de gradient). L'objectif est
 *            de comprendre intimement le fonctionnement d'un réseau de neurones,
 *            pas seulement de l'utiliser.
 *
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <random>       // Pour l'initialisation aléatoire des poids
#include <concepts>     // C++20

// Incluez vos propres bibliothèques d'algèbre linéaire des exercices précédents.
// Une implémentation performante de Vecteur et Matrice est PRÉREQUIS.
// #include "Vecteur.hpp"
// #include "Matrice.hpp"

// =========================================================================
// PARTIE 1 : LES COMPOSANTS STATIQUES DU RÉSEAU
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 1 : Les Fonctions d'Activation
// -------------------------------------------------------------------------
/*
 *  Objectif: Implémenter les non-linéarités qui permettent aux réseaux d'apprendre
 *            des fonctions complexes.
 *
 *  Concepts: Fonctions d'activation, Dérivées.
 *
 *  Tâche: Créez une structure ou une classe pour chaque fonction d'activation.
 *         Chacune doit exposer deux méthodes statiques : `val(x)` et `prime(x)` (la dérivée).
 *         - Implémentez `Sigmoid`.
 *         - Implémentez `ReLU` (Rectified Linear Unit).
 *         La dérivée est cruciale pour la rétropropagation.
 */
void exercice1() {
    std::cout << "--- DEBUT EXERCICE 1 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 1 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 2 : La Couche de Neurones (Layer)
// -------------------------------------------------------------------------
/*
 *  Objectif: Créer le bloc de construction fondamental d'un réseau : une couche dense.
 *
 *  Concepts: Poids, biais, transformation affine.
 *
 *  Tâche: Créez une classe `Layer`.
 *         - Le constructeur prend le nombre de neurones en entrée et en sortie.
 *         - Elle doit contenir une `Matrice` pour les poids `W` et un `Vecteur` pour les biais `b`.
 *         - Initialisez les poids avec une distribution aléatoire (ex: Xavier/Glorot).
 *         - Implémentez la méthode `forward(const Vecteur& input)` qui calcule la
 *           sortie de la couche : `activation(W * input + b)`.
 */
void exercice2() {
    std::cout << "--- DEBUT EXERCICE 2 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 2 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 3 : Le Réseau Complet (Network) et la Propagation Avant
// -------------------------------------------------------------------------
/*
 *  Objectif: Assembler les couches pour former un réseau et calculer une prédiction.
 *
 *  Concepts: Propagation avant (Forward Pass), architecture du réseau.
 *
 *  Tâche: Créez une classe `Network`.
 *         - Elle doit contenir un `std::vector<Layer>` pour stocker les couches du réseau.
 *         - Implémentez une méthode `predict(const Vecteur& input)` qui propage
 *           l'entrée à travers toutes les couches séquentiellement et retourne
 *           la sortie de la dernière couche.
 */
void exercice3() {
    std::cout << "--- DEBUT EXERCICE 3 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 3 ---\n\n";
}

// =========================================================================
// PARTIE 2 : LE MÉCANISME D'APPRENTISSAGE : LA RÉTROPROPAGATION
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 4 : La Fonction de Coût (Loss Function)
// -------------------------------------------------------------------------
/*
 *  Objectif: Quantifier l'erreur du réseau.
 *
 *  Concepts: Fonction de coût, Erreur Quadratique Moyenne (MSE).
 *
 *  Tâche: Créez une classe `MSE`. Comme pour les activations, elle doit exposer
 *         deux méthodes statiques : `val(prediction, target)` qui calcule l'erreur,
 *         et `prime(prediction, target)` qui calcule la dérivée de l'erreur.
 */
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 4 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 5 : La Rétropropagation (Partie 1 : Couche de Sortie)
// -------------------------------------------------------------------------
/*
 *  Objectif: Calculer le gradient de l'erreur par rapport aux poids et biais
 *            de la dernière couche.
 *
 *  Concepts: Règle de dérivation en chaîne (Chain Rule), gradient.
 *
 *  Tâche: Dans votre classe `Layer`, ajoutez une méthode `backward`. Pour la couche
 *         de sortie, le gradient de l'erreur est le point de départ. Calculez
 *         `dE/dW`, `dE/db` pour la dernière couche, en utilisant la dérivée de la
 *         fonction de coût et la dérivée de la fonction d'activation.
 */
void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 5 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 6 : La Rétropropagation (Partie 2 : Couches Cachées)
// -------------------------------------------------------------------------
/*
 *  Objectif: Propager le gradient de l'erreur vers l'arrière à travers le réseau.
 *
 *  Concepts: Rétropropagation du gradient.
 *
 *  Tâche: Modifiez votre méthode `backward` dans la classe `Layer`. Elle doit
 *         maintenant prendre en paramètre le gradient de l'erreur de la couche
 *         *suivante* (`dE/dY`) et retourner le gradient de l'erreur par rapport
 *         à sa propre entrée (`dE/dX`), qui sera utilisé par la couche *précédente*.
 *         À l'intérieur, elle calcule `dE/dW` et `dE/db` pour elle-même.
 */
void exercice6() {
    std::cout << "--- DEBUT EXERCICE 6 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 6 ---\n\n";
}

// =========================================================================
// PARTIE 3 : L'ENTRAÎNEMENT
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 7 : L'Optimiseur (Descente de Gradient Stochastique)
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser les gradients calculés pour mettre à jour les poids du réseau.
 *
 *  Concepts: Descente de gradient, taux d'apprentissage (learning rate).
 *
 *  Tâche: Dans votre classe `Network`, implémentez une méthode `update(learning_rate)`.
 *         Cette méthode doit parcourir chaque couche et mettre à jour les poids et
 *         biais en utilisant la règle `param = param - learning_rate * gradient_param`.
 */
void exercice7() {
    std::cout << "--- DEBUT EXERCICE 7 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 7 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 8 : La Boucle d'Entraînement
// -------------------------------------------------------------------------
/*
 *  Objectif: Assembler tous les composants pour entraîner le réseau sur un jeu de données.
 *
 *  Concepts: Époque (epoch), lot (batch), apprentissage en ligne/par lot.
 *
 *  Tâche: Créez une méthode `fit(dataset, epochs, learning_rate)` dans votre
 *         classe `Network`. Cette méthode doit implémenter la boucle d'entraînement principale :
 *         Pour chaque époque :
 *           Pour chaque exemple dans le jeu de données :
 *             1. `predict` (passe avant)
 *             2. Calculer le coût et son gradient initial
 *             3. `backward` (passe arrière pour calculer tous les gradients)
 *             4. `update` (mettre à jour les poids)
 */
void exercice8() {
    std::cout << "--- DEBUT EXERCICE 8 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 8 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 9 : Apprentissage par Mini-Lots (Mini-Batch SGD)
// -------------------------------------------------------------------------
/*
 *  Objectif: Améliorer la stabilité et la vitesse de l'entraînement.
 *
 *  Concepts: Apprentissage par mini-lots, moyennage des gradients.
 *
 *  Tâche: Modifiez votre méthode `fit`. Au lieu de mettre à jour les poids
 *         après chaque exemple, accumulez les gradients sur un petit "mini-lot"
 *         d'exemples. Une fois le lot traité, moyennez les gradients et effectuez
 *         une seule mise à jour.
 */
void exercice9() {
    std::cout << "--- DEBUT EXERCICE 9 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 9 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 10 : Évaluation et Précision (Accuracy)
// -------------------------------------------------------------------------
/*
 *  Objectif: Mesurer la performance du réseau sur un problème de classification.
 *
 *  Concepts: Précision (accuracy), ensemble de test, one-hot encoding.
 *
 *  Tâche: Écrivez une fonction qui prend votre réseau et un ensemble de test.
 *         Pour chaque exemple de test, elle doit faire une prédiction. Pour un
 *         problème de classification, cela consiste à trouver l'indice du
 *         neurone de sortie avec la plus haute activation. Comparez cet indice
 *         avec la vraie étiquette et calculez le pourcentage de prédictions correctes.
 */
void exercice10() {
    std::cout << "--- DEBUT EXERCICE 10 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 10 ---\n\n";
}


// =========================================================================
// LE GROS PROBLÈME FINAL : Reconnaissance de Chiffres Manuscrits (MNIST)
// =========================================================================
/*
 *  Objectif: Appliquer votre bibliothèque "from-scratch" à un problème
 *            classique et réel de vision par ordinateur.
 *
 *  Description:
 *      Entraînez un réseau de neurones à reconnaître les chiffres de 0 à 9 à
 *      partir d'images de 28x28 pixels de la base de données MNIST.
 *      1.  **Gestion des Données :** Écrivez un chargeur de données capable de
 *          lire les fichiers binaires du jeu de données MNIST et de les convertir
 *          en `Vecteur` pour les images (784 pixels) et les étiquettes (en
 *          format "one-hot", ex: 5 -> [0,0,0,0,0,1,0,0,0,0]).
 *      2.  **Architecture :** Définissez une architecture de réseau appropriée.
 *          Par exemple, une couche d'entrée de 784 neurones, deux couches
 *          cachées (ex: 128 et 64 neurones) avec activation ReLU, et une
 *          couche de sortie de 10 neurones avec activation Sigmoid.
 *      3.  **Entraînement :** Entraînez votre réseau sur les 60 000 images de
 *          l'ensemble d'entraînement en utilisant votre méthode `fit` par mini-lots.
 *          Affichez l'erreur et la précision à la fin de chaque époque.
 *      4.  **Évaluation :** Après l'entraînement, évaluez la performance finale
 *          de votre réseau sur les 10 000 images de l'ensemble de test, qui n'ont
 *          jamais été vues pendant l'entraînement. Visez une précision de >90%.
 */
void grosProblemeFinal() {
    std::cout << "--- DEBUT DU PROJET MNIST ---\n\n";
    std::cout << "\n--- FIN DU PROJET MNIST ---\n\n";
}


// =========================================================================
// Le programme principal (main)
// =========================================================================
int main() {
    std::cout << "*****************************************************\n";
    std::cout << "*     TEMPLATE - RÉSEAUX DE NEURONES FROM-SCRATCH    *\n";
    std::cout << "*****************************************************\n\n";

    // Décommentez la ligne de l'exercice sur lequel vous voulez travailler.
    // exercice1();

    return 0;
}