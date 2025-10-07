/******************************************************************************
 *
 *       Fichier d'Exercices Intermédiaires - Apprentissage du C++
 *
 *  Objectif: Mettre en pratique les concepts de Programmation Orientée Objet,
 *            la gestion moderne des ressources et la programmation générique.
 *   Auteur : @Kribet Naoufal
 ******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
#include <map>
#include <algorithm>

// =========================================================================
// PARTIE 1 : LA PROGRAMMATION ORIENTÉE OBJET (POO)
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 1 : La Classe et l'Encapsulation
// -------------------------------------------------------------------------
/*
 *  Objectif: Créer votre premier type de données personnalisé, en masquant
 *            les détails d'implémentation et en ne fournissant qu'une
 *            interface publique contrôlée.
 *
 *  Concepts: class, public, private, attributs, méthodes.
 *
 *  Tâche: Créez une classe CompteBancaire.
 *      a. Elle doit avoir un attribut privé pour le solde.
 *      b. Elle doit offrir des méthodes publiques pour déposer de l'argent,
 *         retirer de l'argent (en vérifiant les conditions), et consulter le solde.
 *      c. Le solde ne doit pas pouvoir être modifié directement de l'extérieur.
 */
void exercice1() {
    std::cout << "--- DEBUT EXERCICE 1 ---\n\n";

    // Mettez votre code de test ici : créez une instance et utilisez ses méthodes.

    std::cout << "\n--- FIN EXERCICE 1 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 2 : Le Cycle de Vie d'un Objet (Constructeurs/Destructeur)
// -------------------------------------------------------------------------
/*
 *  Objectif: Contrôler la création et la destruction de vos objets pour
 *            garantir qu'ils sont toujours dans un état valide.
 *
 *  Concepts: Constructeur, destructeur, liste d'initialisation.
 *
 *  Tâche: Améliorez votre classe CompteBancaire.
 *      a. Ajoutez un constructeur qui permet de définir un solde initial à la création.
 *      b. Ajoutez un constructeur par défaut (sans arguments) qui initialise le solde à 0.
 *      c. Ajoutez un destructeur.
 *      d. Affichez des messages dans les constructeurs et le destructeur pour tracer
 *         le cycle de vie des objets que vous créerez dans la fonction exercice2.
 */
void exercice2() {
    std::cout << "--- DEBUT EXERCICE 2 ---\n\n";

    // Testez ici la création d'objets avec et sans solde initial,
    // et observez l'ordre des messages de création/destruction.

    std::cout << "\n--- FIN EXERCICE 2 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 3 : L'Héritage
// -------------------------------------------------------------------------
/*
 *  Objectif: Créer de nouvelles classes en se basant sur des classes existantes
 *            pour réutiliser le code et modéliser des relations "est un(e)".
 *
 *  Concepts: Héritage (: public Base), classe de base, classe dérivée, protected.
 *
 *  Tâche: Modélisez différents types de comptes.
 *      a. Créez une classe CompteEpargne qui hérite de CompteBancaire.
 *      b. Cette nouvelle classe doit avoir un attribut supplémentaire pour le taux d'intérêt.
 *      c. Elle doit posséder une méthode pour calculer et ajouter les intérêts au solde.
 *      d. Son constructeur doit initialiser à la fois ses propres attributs et ceux
 *         de sa classe mère (CompteBancaire).
 */
void exercice3() {
    std::cout << "--- DEBUT EXERCICE 3 ---\n\n";

    // Testez votre classe CompteEpargne.

    std::cout << "\n--- FIN EXERCICE 3 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 4 : Le Polymorphisme
// -------------------------------------------------------------------------
/*
 *  Objectif: Manipuler une collection d'objets de types différents (mais
 *            apparentés) via une interface commune.
 *
 *  Concepts: virtual, polymorphisme, override, classe abstraite.
 *
 *  Tâche: Gérez un portefeuille de comptes hétérogènes.
 *      a. Rendez une ou plusieurs méthodes de CompteBancaire virtuelles.
 *      b. Créez une autre classe CompteCourant qui hérite de CompteBancaire
 *         et qui possède une notion de découvert autorisé.
 *      c. Redéfinissez (override) la méthode de retrait dans CompteCourant
 *         pour prendre en compte le découvert.
 *      d. Dans la fonction exercice4, créez un vecteur de pointeurs de
 *         CompteBancaire (std::vector<CompteBancaire*>) et remplissez-le
 *         avec des instances de CompteEpargne et CompteCourant.
 *      e. Parcourez ce vecteur et appelez les méthodes virtuelles. Observez
 *         que le comportement correct est appelé pour chaque type d'objet.
 *      f. N'oubliez pas de libérer la mémoire allouée dynamiquement.
 */
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 ---\n\n";

    // Mettez en place le scénario polymorphique ici.

    std::cout << "\n--- FIN EXERCICE 4 ---\n\n";
}


// =========================================================================
// PARTIE 2 : LE C++ MODERNE ET SES IDIOMES
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 5 : La Surcharge d'Opérateurs
// -------------------------------------------------------------------------
/*
 *  Objectif: Rendre vos propres classes aussi intuitives à manipuler que
 *            les types de base.
 *
 *  Concepts: Surcharge d'opérateurs (operator+), surcharge de flux (operator<<).
 *
 *  Tâche: Créez une classe Vecteur2D pour un vecteur mathématique (x, y).
 *      a. Surchargez l'opérateur '+' pour permettre l'addition de deux Vecteur2D.
 *      b. Surchargez l'opérateur '<<' pour permettre d'afficher un Vecteur2D
 *         directement avec std::cout.
 */
void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n\n";

    // Créez des instances de Vecteur2D et testez vos opérateurs surchargés.

    std::cout << "\n--- FIN EXERCICE 5 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 6 : La Gestion des Ressources (RAII et unique_ptr)
// -------------------------------------------------------------------------
/*
 *  Objectif: Écrire du code C++ sûr, sans fuite de mémoire.
 *
 *  Concepts: RAII, <memory>, std::unique_ptr, std::make_unique, std::move.
 *
 *  Tâche: Modernisez votre code de l'exercice 4.
 *      a. Remplacez le std::vector<CompteBancaire*> par un
 *         std::vector<std::unique_ptr<CompteBancaire>>.
 *      b. Mettez à jour le code de création des objets pour utiliser std::make_unique.
 *      c. Supprimez la boucle de 'delete' manuelle. Constatez que le programme
 *         est plus simple, plus sûr, et fonctionne toujours.
 */
void exercice6() {
    std::cout << "--- DEBUT EXERCICE 6 ---\n\n";

    // Réécrivez la logique de l'exercice 4 en utilisant des pointeurs intelligents.

    std::cout << "\n--- FIN EXERCICE 6 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 7 : La Programmation Générique (Templates)
// -------------------------------------------------------------------------
/*
 *  Objectif: Écrire du code qui fonctionne avec de multiples types de données.
 *
 *  Concepts: template<typename T>, templates de fonction, templates de classe.
 *
 *  Tâche:
 *      a. Écrivez une fonction template 'afficherInfo' qui peut afficher
 *         n'importe quelle variable (int, double, string) de manière générique.
 *      b. Créez une classe template 'Boite' qui peut contenir un objet de
 *         n'importe quel type. Elle aura une méthode pour y mettre un objet
 *         et une autre pour le récupérer.
 */
void exercice7() {
    std::cout << "--- DEBUT EXERCICE 7 ---\n\n";

    // Testez votre fonction et votre classe template avec différents types.

    std::cout << "\n--- FIN EXERCICE 7 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 8 : Les Conteneurs Associatifs (std::map)
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser le conteneur clé-valeur le plus courant de la STL.
 *
 *  Concepts: <map>, std::map, paires clé-valeur.
 *
 *  Tâche: Créez un inventaire de produits.
 *      a. Utilisez une std::map<std::string, int> pour associer le nom d'un
 *         produit (clé) à sa quantité en stock (valeur).
 *      b. Implémentez des opérations simples : ajouter un produit,
 *         modifier la quantité d'un produit, et afficher l'inventaire complet.
 */
void exercice8() {
    std::cout << "--- DEBUT EXERCICE 8 ---\n\n";

    // Manipulez votre map d'inventaire ici.

    std::cout << "\n--- FIN EXERCICE 8 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 9 : La Gestion d'Erreurs (Exceptions)
// -------------------------------------------------------------------------
/*
 *  Objectif: Apprendre à signaler et à gérer les erreurs exceptionnelles.
 *
 *  Concepts: throw, try, catch, <stdexcept>.
 *
 *  Tâche: Rendez la méthode de retrait de CompteBancaire plus robuste.
 *      a. Au lieu de retourner 'false', la méthode doit maintenant lancer
 *         une exception (ex: std::runtime_error) si les fonds sont insuffisants.
 *      b. Dans la fonction exercice9, appelez cette méthode dans un bloc 'try'
 *         et attrapez l'exception dans un bloc 'catch' pour afficher un message
 *         d'erreur convivial.
 */
void exercice9() {
    std::cout << "--- DEBUT EXERCICE 9 ---\n\n";

    // Testez votre nouvelle gestion d'erreurs par exception.

    std::cout << "\n--- FIN EXERCICE 9 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 10 : Les Lambdas et Algorithmes
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser des fonctions anonymes (lambdas) pour personnaliser
 *            le comportement des algorithmes de la STL.
 *
 *  Concepts: Expressions Lambda [](){}, std::find_if, std::count_if.
 *
 *  Tâche: Filtrez une liste de produits (exercice 8).
 *      a. Créez un vecteur de produits (utilisez une struct simple).
 *      b. Utilisez std::count_if et une expression lambda pour compter le nombre
 *         de produits dont la quantité est inférieure à un certain seuil.
 *      c. Utilisez std::find_if pour trouver le premier produit dont le nom
 *         est "Épée".
 */
void exercice10() {
    std::cout << "--- DEBUT EXERCICE 10 ---\n\n";

    // Utilisez les algorithmes et les lambdas ici.

    std::cout << "\n--- FIN EXERCICE 10 ---\n\n";
}


// =========================================================================
// LE GROS PROBLÈME FINAL : Mini Simulateur de Combat RPG
// =========================================================================
/*
 *  Objectif: Synthétiser tous les concepts de POO et de C++ moderne.
 *
 *  Description:
 *      1. Hiérarchie de classes:
 *          - Classe de base abstraite 'Personnage' (nom, PV, attaque).
 *          - Fonctions virtuelles : attaquer, estVivant.
 *          - Classes dérivées 'Guerrier' et 'Mage' avec des logiques d'attaque différentes.
 *      2. Classe 'Arene' pour gérer le combat entre deux personnages.
 *          - Doit utiliser des std::unique_ptr<Personnage>.
 *          - Une méthode 'lancerCombat' gère la boucle de combat tour par tour.
 *      3. Programme principal:
 *          - Permet à l'utilisateur de choisir sa classe.
 *          - Crée les combattants, l'arène, et lance le combat.
 */
void grosProblemeFinal() {
    std::cout << "--- DEBUT DU SIMULATEUR DE COMBAT ---\n\n";

    // Votre code pour le simulateur de combat.

    std::cout << "\n--- FIN DU SIMULATEUR DE COMBAT ---\n\n";
}


// =========================================================================
// Le programme principal (main)
// =========================================================================
int main() {
    std::cout << "*****************************************************\n";
    std::cout << "*         TEMPLATE D'EXERCICES INTERMEDIAIRES       *\n";
    std::cout << "*****************************************************\n\n";

    // Décommentez la ligne de l'exercice sur lequel vous voulez travailler.
    // exercice1();
    // exercice2();
    // exercice3();
    // exercice4();
    // exercice5();
    // exercice6();
    // exercice7();
    // exercice8();
    // exercice9();
    // exercice10();

    // grosProblemeFinal();

    return 0;

}
