/******************************************************************************
 *
 *  Fichier Template pour les Exercices d'Initiation au C++.
 *
 *  Objectif: Fournir un squelette de code pour réaliser la série d'exercices
 *            sur les fondamentaux du C++. Chaque exercice est dans sa propre
 *            fonction. Pour travailler sur un exercice, décommentez l'appel
 *            correspondant dans la fonction `main()`. Bon entrainement :).
 *
 *  Auteur: @Kribet Naoufal
 *
 ******************************************************************************/

// --- INCLUDES NÉCESSAIRES POUR TOUS LES EXERCICES ---
// Flux d'entrée/sortie (console)
#include <iostream>
// Manipulation de chaînes de caractères
#include <string>
// Conteneur dynamique (tableau)
#include <vector>
// Flux de fichiers (lecture/écriture)
#include <fstream>
// Algorithmes numériques (ex: accumulate)
#include <numeric>
// Algorithmes génériques (ex: sort, find)
#include <algorithm>
// Pour la gestion d'exceptions lors de la conversion de string
#include <stdexcept>


// =========================================================================
// EXERCICE 1 : Prise en main de l'environnement et des flux
// =========================================================================
/*
 *  Objectif: Remplacer printf et scanf par les flux d'E/S du C++ et manipuler
 *            la brique de base : std::string.
 *
 *  Concepts: #include <iostream>, #include <string>, std::cout, std::cin,
 *            std::string, namespace std.
 *
 *  Tâche: Écrire un programme qui :
 *      a. Demande à l'utilisateur son prénom et le lit dans une std::string.
 *      b. Demande son âge et le lit dans un int.
 *      c. Affiche un message de bienvenue personnalisé du type :
 *         "Bonjour [Prénom], vous avez [Âge] ans et vous commencez le C++ !".
 */
void exercice1() {
    std::cout << "--- DEBUT EXERCICE 1 ---\n";

    // TODO: a. Déclarer une std::string pour le prénom et demander à l'utilisateur de le saisir.
    // Pensez à utiliser std::getline pour gérer les prénoms composés.

    // TODO: b. Déclarer un int pour l'âge et demander à l'utilisateur de le saisir.
    // Pensez à la manière robuste de le faire pour éviter les erreurs.

    // TODO: c. Afficher le message de bienvenue final.

    std::cout << "--- FIN EXERCICE 1 ---\n\n";
}


// =========================================================================
// EXERCICE 2 : Le conteneur dynamique par excellence : std::vector
// =========================================================================
/*
 *  Objectif: Remplacer les tableaux C et l'allocation manuelle avec malloc
 *            par le conteneur std::vector.
 *
 *  Concepts: #include <vector>, std::vector, méthode .push_back(),
 *            méthode .size(), boucle for sur une plage (range-based for loop).
 *
 *  Tâche: Écrivez un programme qui :
 *      a. Déclare un std::vector<int>.
 *      b. Demande à l'utilisateur de saisir 5 notes (entiers) et les ajoute
 *         au vecteur une par une avec .push_back().
 *      c. Calcule la moyenne de ces notes en parcourant le vecteur.
 *      d. Affiche la moyenne calculée.
 */
void exercice2() {
    std::cout << "--- DEBUT EXERCICE 2 ---\n";

    // TODO: a. Déclarez un std::vector<int> appelé 'notes'.

    // TODO: b. Faites une boucle (par exemple, une boucle for classique) pour demander 5 fois
    // une note à l'utilisateur et l'ajouter au vecteur avec notes.push_back().

    // TODO: c. Déclarez une variable pour la somme (de type double pour la précision).
    // Parcourez le vecteur avec une boucle "range-based for" (for (int note : notes))
    // pour calculer la somme.

    // TODO: d. Calculez et affichez la moyenne. Attention à la division entre entiers !

    std::cout << "--- FIN EXERCICE 2 ---\n\n";
}


// =========================================================================
// EXERCICE 3 : Fonctions, Références et const
// =========================================================================
/*
 *  Objectif: Comprendre comment passer des objets complexes (comme un vecteur)
 *            à des fonctions de manière efficace et sûre, en utilisant des
 *            références pour éviter les copies.
 *
 *  Concepts: Passage par référence (&), référence constante (const &).
 *
 *  Tâche :
 *      a. Reprenez le code de l'exercice 2.
 *      b. Créez une fonction double calculerMoyenne(const std::vector<int>& notes)
 *         qui prend le vecteur en entrée par référence constante et retourne la moyenne.
 *      c. Créez une autre fonction void afficherNotes(const std::vector<int>& notes)
 *         qui affiche simplement toutes les notes du vecteur.
 *      d. Appelez ces deux fonctions depuis votre fonction exercice3.
 */

// TODO: b. Implémentez la fonction calculerMoyenne ici.
// Elle ne doit contenir que la logique de calcul de la moyenne.
double calculerMoyenne(const std::vector<int>& notes) {
    // Votre code ici...
    return 0.0;
}

// TODO: c. Implémentez la fonction afficherNotes ici.
void afficherNotes(const std::vector<int>& notes) {
    // Votre code ici...
}

void exercice3() {
    std::cout << "--- DEBUT EXERCICE 3 ---\n";

    // TODO: a. Créez un std::vector<int> et remplissez-le avec quelques notes,
    // comme dans l'exercice 2.
    std::vector<int> mesNotes = {12, 18, 9, 15, 13};

    // TODO: d. Appelez vos deux fonctions.
    // afficherNotes( ... );
    // double moyenne = calculerMoyenne( ... );
    // std::cout << "La moyenne est : " << moyenne << std::endl;

    std::cout << "--- FIN EXERCICE 3 ---\n\n";
}

// =========================================================================
// EXERCICE 4 : Lecture depuis un fichier
// =========================================================================
/*
 *  Objectif: Remplacer fopen, fscanf, fclose par les flux de fichiers C++.
 *
 *  Concepts: #include <fstream>, std::ifstream, méthode .is_open().
 *
 *  Tâche :
 *      a. Créez un fichier texte simple notes.txt et écrivez une dizaine
 *         de notes à l'intérieur, une par ligne.
 *      b. Écrivez un programme C++ qui :
 *          - Ouvre ce fichier notes.txt.
 *          - Vérifie si le fichier a bien été ouvert.
 *          - Lit chaque note du fichier et la stocke dans un std::vector<int>.
 *          - Utilise la fonction calculerMoyenne de l'exercice 3 pour
 *            calculer et afficher la moyenne des notes lues.
 */
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 ---\n";

    // TODO: a. Avant de lancer le programme, créez manuellement un fichier "notes.txt"
    // dans le même dossier que votre exécutable. Mettez-y plusieurs nombres entiers,
    // un par ligne. Par exemple :
    // 15
    // 8
    // 19
    // 12

    std::vector<int> notesDuFichier;
    std::string nomDuFichier = "notes.txt";

    // TODO: b. Déclarez une variable de type std::ifstream et essayez d'ouvrir le fichier.
    // std::ifstream fluxFichier(nomDuFichier);

    // TODO: c. Vérifiez si l'ouverture a réussi avec un 'if (fluxFichier.is_open())'.
    // C'est une étape cruciale pour la robustesse du code.

    // TODO: d. Si le fichier est ouvert :
    // - Déclarez une variable 'int noteLue;'
    // - Créez une boucle 'while (fluxFichier >> noteLue)'
    //   Cet idiome C++ est très puissant : la boucle continuera tant que la lecture
    //   d'un entier dans le fichier réussit.
    // - À l'intérieur de la boucle, ajoutez la note lue au vecteur avec .push_back().

    // TODO: e. Après la boucle (donc après le 'if'), fermez le fichier avec fluxFichier.close();
    // (Bonne pratique, même si c'est automatique à la fin de la fonction).

    // TODO: f. Gérez le cas où le fichier n'a pas pu être ouvert avec un 'else'
    // qui affiche un message d'erreur.

    // TODO: g. Une fois que le vecteur est rempli, appelez vos fonctions de l'exercice 3
    // pour afficher les notes lues et calculer leur moyenne.
    // afficherNotes(notesDuFichier);
    // double moyenne = calculerMoyenne(notesDuFichier);
    // std::cout << "La moyenne des notes du fichier est : " << moyenne << std::endl;

    std::cout << "--- FIN EXERCICE 4 ---\n\n";
}


// =========================================================================
// EXERCICE 5 : Agréger les données avec struct
// =========================================================================
/*
 *  Objectif: Utiliser les structures pour regrouper des données de types
 *            différents, une première étape vers la programmation orientée objet.
 *
 *  Concepts: struct.
 *
 *  Tâche :
 *      a. Définissez une struct Etudiant qui contient un std::string nom;
 *         et un double note;.
 *      b. Dans votre fonction exercice5, créez un std::vector<Etudiant>.
 *      c. Remplissez ce vecteur avec au moins 3 étudiants, en leur donnant
 *         des noms et des notes.
 *      d. Parcourez le vecteur et affichez les informations de chaque étudiant.
 */

// TODO: a. La définition de la structure se fait en dehors de toute fonction,
// pour qu'elle soit visible par tout le code (comme un nouveau type).
struct Etudiant {
    std::string nom;
    double note;
};

void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n";

    // TODO: b. Déclarez un std::vector qui contiendra des objets de votre nouveau type Etudiant.
    // std::vector<Etudiant> classe;

    // TODO: c. Remplissez le vecteur. La méthode la plus moderne est d'utiliser
    // une liste d'initialisation directement à la déclaration.
    // std::vector<Etudiant> classe = {
    //     {"Alice", 18.5},
    //     {"Bob", 14.0},
    //     {"Charlie", 9.5}
    // };
    // Alternativement, vous pouvez utiliser .push_back():
    // classe.push_back({"David", 16.0});

    // TODO: d. Parcourez le vecteur avec une boucle 'range-based for'.
    // Utiliser 'const auto&' est une bonne pratique : 'const' car on ne modifie pas l'étudiant,
    // '&' pour éviter de faire une copie de chaque étudiant à chaque tour de boucle.
    // for (const auto& etudiant : classe) {
    //     // Affichez ici le nom et la note de 'etudiant' en accédant à ses membres
    //     // avec le point (ex: etudiant.nom).
    // }

    std::cout << "--- FIN EXERCICE 5 ---\n\n";
}


// =========================================================================
// EXERCICE 6 : Algorithmes de la STL
// =========================================================================
/*
 *  Objectif: Découvrir la puissance de la bibliothèque d'algorithmes pour
 *            éviter d'écrire des boucles manuellement.
 *
 *  Concepts: #include <numeric>, #include <algorithm>, std::accumulate, std::sort.
 *
 *  Tâche :
 *      a. Reprenez votre std::vector<int> des exercices précédents.
 *      b. Utilisez std::accumulate pour calculer la somme des notes.
 *      c. Utilisez std::sort pour trier le vecteur de notes par ordre croissant.
 *      d. Affichez le vecteur trié.
 */
void exercice6() {
    std::cout << "--- DEBUT EXERCICE 6 ---\n";

    // TODO: a. Déclarez et initialisez un std::vector<int> avec des notes non triées.
    std::vector<int> notes = {15, 8, 19, 12, 17, 5, 13};
    std::cout << "Vecteur original : ";
    afficherNotes(notes); // On réutilise le code de l'exo 3 !

    // TODO: b. Calculez la somme avec std::accumulate.
    // La fonction prend 3 arguments :
    // - un itérateur sur le début de la plage (notes.begin())
    // - un itérateur sur la fin de la plage (notes.end())
    // - la valeur initiale de la somme (0 pour des entiers)
    // int somme = std::accumulate( ... );
    // std::cout << "\nLa somme calculée avec std::accumulate est : " << somme << std::endl;

    // TODO: c. Triez le vecteur avec std::sort.
    // La fonction prend 2 arguments :
    // - un itérateur sur le début de la plage à trier (notes.begin())
    // - un itérateur sur la fin de la plage à trier (notes.end())
    // std::sort( ... );
    // TODO: d. Affichez le vecteur après le tri pour vérifier.
    std::cout << "\nVecteur trié : ";
    // afficherNotes(notes);

    std::cout << "--- FIN EXERCICE 6 ---\n\n";
}

// =========================================================================
// EXERCICE 7 : Itérateurs et recherche
// =========================================================================
/*
 *  Objectif: Comprendre le concept d'itérateur, qui est le "pointeur intelligent"
 *            des conteneurs de la STL.
 *
 *  Concepts: Itérateurs (std::vector<T>::iterator), begin(), end(), std::find.
 *
 *  Tâche :
 *      a. Reprenez votre std::vector<int> de notes.
 *      b. Demandez à l'utilisateur de saisir une note à rechercher.
 *      c. Utilisez std::find pour rechercher cette note dans le vecteur.
 *      d. Affichez un message indiquant si la note a été trouvée ou non en
 *         testant si l'itérateur retourné est différent de notes.end().
 */
void exercice7() {
    std::cout << "--- DEBUT EXERCICE 7 ---\n";

    // TODO: a. Déclarez et initialisez un std::vector<int> avec quelques notes.
    std::vector<int> notes = {15, 8, 19, 12, 17, 5, 13};
    std::cout << "Recherche dans le vecteur suivant :\n";
    // afficherNotes(notes); // Assurez-vous que cette fonction est accessible

    // TODO: b. Demandez à l'utilisateur une note à rechercher et stockez-la
    // dans une variable 'int noteARechercher;'.
    // Pensez à faire une saisie robuste comme nous l'avons vu.
    int noteARechercher = 0;
    std::cout << "\nQuelle note voulez-vous rechercher ? ";
    // std::cin >> noteARechercher; // Pour simplifier, on ne fait pas la saisie robuste ici.

    // TODO: c. Utilisez std::find. Il prend 3 arguments :
    // - Un itérateur sur le début de la plage de recherche (notes.begin())
    // - Un itérateur sur la fin de la plage de recherche (notes.end())
    // - La valeur que vous recherchez (noteARechercher)
    // La fonction retourne un itérateur. Stockez ce résultat dans une variable.
    // Le type est 'std::vector<int>::iterator'. Utiliser 'auto' est plus simple !
    // auto resultatIt = std::find( ... );

    // TODO: d. Testez le résultat.
    // L'idiome C++ est le suivant : si std::find ne trouve rien, il retourne
    // l'itérateur de fin (notes.end()).
    // if (resultatIt != notes.end()) {
    //     // L'élément a été trouvé !
    //     std::cout << "La note " << noteARechercher << " a été trouvée dans le vecteur." << std::endl;
    //     // Bonus : un itérateur se comporte comme un pointeur, on peut le déréférencer
    //     // pour obtenir la valeur sur laquelle il pointe.
    //     // std::cout << "Valeur trouvée : " << *resultatIt << std::endl;
    // } else {
    //     // L'élément n'a pas été trouvé.
    //     std::cout << "La note " << noteARechercher << " n'est pas présente dans le vecteur." << std::endl;
    // }

    std::cout << "--- FIN EXERCICE 7 ---\n\n";
}


// =========================================================================
// EXERCICE 8 : Organisation du code avec les namespace
// =========================================================================
/*
 *  Objectif: Éviter les conflits de noms et organiser logiquement votre code.
 *
 *  Concepts: namespace.
 *
 *  Tâche :
 *      a. Reprenez vos fonctions calculerMoyenne et afficherNotes.
 *      b. Placez ces deux fonctions à l'intérieur d'un namespace que vous
 *         appellerez StatistiquesUtils.
 *      c. Dans votre fonction exercice8, mettez à jour les appels à ces
 *         fonctions en les préfixant par le nom du namespace
 *         (ex : StatistiquesUtils::calculerMoyenne(...)).
 */

// TODO: b. Créez un namespace et déplacez-y vos fonctions.
// Vous devrez couper-coller les fonctions 'calculerMoyenne' et 'afficherNotes'
// que vous avez écrites précédemment pour les mettre à l'intérieur de ce bloc.
namespace StatistiquesUtils {
    //
    // COLLES ICI TES FONCTIONS calculerMoyenne et afficherNotes
    //
    // double calculerMoyenne(const std::vector<int>& notes) { ... }
    // void afficherNotes(const std::vector<int>& notes) { ... }
    //
} // fin du namespace StatistiquesUtils

void exercice8() {
    std::cout << "--- DEBUT EXERCICE 8 ---\n";

    std::vector<int> mesNotes = {10, 20, 15, 18};

    // TODO: c. Appelez les fonctions en utilisant l'opérateur de résolution de portée '::'
    std::cout << "Appel des fonctions depuis le namespace StatistiquesUtils :\n";

    // StatistiquesUtils::afficherNotes(mesNotes);

    // double moyenne = StatistiquesUtils::calculerMoyenne(mesNotes);
    // std::cout << "La moyenne est : " << moyenne << std::endl;

    std::cout << "--- FIN EXERCICE 8 ---\n\n";
}


// =========================================================================
// LE GROS PROBLÈME FINAL : Mini-Gestionnaire de Bibliothèque
// =========================================================================
/*
 *  Objectif: Créer une application console simple pour gérer une collection
 *            de livres, en lisant et écrivant les données dans un fichier.
 *            Cet exercice synthétise tous les concepts vus précédemment.
 */

// --- La structure de données (Définition globale) ---
struct Livre {
    std::string titre;
    std::string auteur;
    int anneePublication;
    bool estEmprunte;
};

// --- Le "moteur" (Toute la logique dans un namespace) ---
namespace Bibliotheque {

    // TODO: Implémentez chaque fonction ci-dessous.

    void ajouterLivre(std::vector<Livre>& livres) {
        std::cout << "\n--- Ajout d'un nouveau livre ---\n";
        // Demander le titre, l'auteur, l'année.
        // Créer un objet Livre, le remplir, et l'ajouter au vecteur.
    }

    void afficherBibliotheque(const std::vector<Livre>& livres) {
        std::cout << "\n--- Liste de tous les livres ---\n";
        // Parcourir le vecteur et afficher les détails de chaque livre.
        // Pensez à gérer le cas où la bibliothèque est vide.
    }

    void rechercherLivre(const std::vector<Livre>& livres) {
        std::cout << "\n--- Rechercher un livre ---\n";
        // Demander un titre, parcourir le vecteur et afficher le livre s'il est trouvé.
    }

    void sauvegarder(const std::vector<Livre>& livres, const std::string& nomFichier) {
        // Ouvrir un std::ofstream.
        // Parcourir le vecteur et écrire chaque livre dans le fichier.
        // Choisissez un format simple, ex: "Titre;Auteur;Annee;Emprunte\n"
        std::cout << "\nSauvegarde de la bibliothèque...\n";
    }

    void charger(std::vector<Livre>& livres, const std::string& nomFichier) {
        // Ouvrir un std::ifstream.
        // Lire le fichier ligne par ligne (avec std::getline).
        // Pour chaque ligne, extraire les informations (parsing) pour créer un
        // objet Livre et l'ajouter au vecteur.
        // Attention, c'est la partie la plus complexe !
        std::cout << "\nChargement de la bibliothèque...\n";
    }

} // fin du namespace Bibliotheque

void grosProblemeFinal() {
    std::cout << "--- DEBUT DU MINI-GESTIONNAIRE DE BIBLIOTHEQUE ---\n";
    
    std::vector<Livre> maBibliotheque;
    const std::string nomFichier = "bibliotheque.txt";

    // TODO: Charger la bibliothèque existante au démarrage
    // Bibliotheque::charger(maBibliotheque, nomFichier);

    int choix = 0;
    while (choix != 5) {
        // TODO: Afficher le menu
        std::cout << "\n--- MENU ---\n"
                  << "1. Afficher tous les livres\n"
                  << "2. Ajouter un livre\n"
                  << "3. Rechercher un livre\n"
                  << "4. Sauvegarder\n"
                  << "5. Quitter\n"
                  << "Votre choix : ";

        // TODO: Lire le choix de l'utilisateur de manière robuste
        std::cin >> choix; // Attention au piège cin/getline si vous lisez du texte ensuite !

        // TODO: Utiliser un switch pour appeler la bonne fonction
        switch (choix) {
            case 1:
                // Bibliotheque::afficherBibliotheque(maBibliotheque);
                break;
            case 2:
                // Bibliotheque::ajouterLivre(maBibliotheque);
                break;
            // etc. pour les autres cas
            case 3:
                // Bibliotheque::rechercherLivre(maBibliotheque);
                break;
            case 4:
                // Bibliotheque::sauvegarder(maBibliotheque, nomFichier);
                break;
            case 5:
                std::cout << "Sauvegarde avant de quitter...\n";
                // Bibliotheque::sauvegarder(maBibliotheque, nomFichier);
                std::cout << "Au revoir !\n";
                break;
            default:
                std::cout << "Choix invalide, veuillez réessayer.\n";
                break;
        }
    }

    std::cout << "--- FIN DU PROGRAMME ---\n\n";
}
// =========================================================================
// Le programme principal (main)
// =========================================================================
int main() {
    // Message de bienvenue
    std::cout << "*****************************************************\n";
    std::cout << "*              TEMPLATE D'EXERCICES C++             *\n";
    std::cout << "*****************************************************\n\n";

    // Décommentez la ligne de l'exercice sur lequel vous voulez travailler.
    // Il est conseillé de n'en activer qu'un seul à la fois.

    exercice1();
    // exercice2();
    // exercice3();
    // exercice4(); 
    // exercice5(); 
    // exercice6();
    // exercice7();
    // exercice8();

    // grosProblemeFinal(); 

    return 0;
}