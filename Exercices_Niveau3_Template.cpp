/******************************************************************************
 *
 *           Fichier d'Exercices Avancés - Maîtrise du C++ Moderne
 *
 *  Objectif: Explorer les mécanismes profonds du C++ : gestion sémantique de
 *            la mémoire, méta-programmation, concurrence et abstractions de
 *            haut niveau. Chaque exercice est une étape vers une
 *            compréhension experte du langage.
 * Auteur : @Kribet Naoufal
 ******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>       // Pour les pointeurs intelligents avancés
#include <stdexcept>
#include <algorithm>
#include <map>
#include <utility>      // Pour std::move et std::forward
#include <thread>       // Pour la programmation concurrente
#include <mutex>        // Pour la protection des données partagées
#include <future>       // Pour la programmation par tâches
#include <functional>   // Pour std::function
#include <type_traits>  // Pour la méta-programmation

// =========================================================================
// PARTIE 1 : MAÎTRISE DU CYCLE DE VIE ET DES RESSOURCES
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 1 : La Règle des Trois (Sémantique de Copie)
// -------------------------------------------------------------------------
/*
 *  Objectif: Comprendre pourquoi la gestion manuelle de la mémoire impose des
 *            règles strictes sur la copie des objets, et implémenter cette
 *            sémantique manuellement.
 *
 *  Concepts: Pointeur brut (new/delete), Destructeur, Constructeur de copie,
 *            Opérateur d'assignation par copie (operator=).
 *
 *  Tâche: Créez une classe 'String' personnalisée qui gère un char* alloué
 *         dynamiquement. Implémentez rigoureusement le destructeur, le
 *         constructeur de copie et l'opérateur d'assignation par copie pour
 *         éviter les fuites de mémoire et les double-libérations.
 */
void exercice1() {
    std::cout << "--- DEBUT EXERCICE 1 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 1 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 2 : La Règle des Cinq (Sémantique de Déplacement)
// -------------------------------------------------------------------------
/*
 *  Objectif: Comprendre et implémenter la sémantique de déplacement pour
 *            optimiser drastiquement la performance en évitant les copies inutiles.
 *
 *  Concepts: Sémantique de déplacement, r-value reference (&&), std::move,
 *            Constructeur de déplacement, Opérateur d'assignation par déplacement.
 *
 *  Tâche: Améliorez votre classe 'String' de l'exercice 1 en y ajoutant un
 *         constructeur de déplacement et un opérateur d'assignation par
 *         déplacement. Affichez des messages dans chaque constructeur/opérateur
 *         (copie vs. déplacement) pour visualiser quand chacun est appelé.
 */
void exercice2() {
    std::cout << "--- DEBUT EXERCICE 2 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 2 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 3 : La Règle de Zéro
// -------------------------------------------------------------------------
/*
 *  Objectif: Comprendre comment la composition d'objets RAII (comme les
 *            conteneurs STL et les pointeurs intelligents) permet au compilateur
 *            de générer automatiquement toutes les fonctions spéciales correctes.
 *
 *  Concepts: RAII, Composition, std::vector, std::unique_ptr.
 *
 *  Tâche: Réécrivez une classe qui a besoin de gérer une ressource (par exemple,
 *         un tableau dynamique) en utilisant un std::vector comme membre privé
 *         au lieu d'un pointeur brut. Constatez que vous n'avez plus besoin
 *         d'écrire AUCUN des destructeur, constructeur de copie/déplacement ou
 *         opérateur d'assignation. C'est la "Règle de Zéro".
 */
void exercice3() {
    std::cout << "--- DEBUT EXERCICE 3 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 3 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 4 : La Possession Partagée (shared_ptr et weak_ptr)
// -------------------------------------------------------------------------
/*
 *  Objectif: Gérer des scénarios de possession complexes où une ressource peut
 *            appartenir à plusieurs objets, et apprendre à briser les cycles
 *            de référence.
 *
 *  Concepts: std::shared_ptr, std::make_shared, std::weak_ptr, référence cyclique.
 *
 *  Tâche: Modélisez une relation Parent-Enfant. Un Parent peut avoir plusieurs
 *         Enfants, et chaque Enfant connaît son Parent.
 *         Utilisez des std::shared_ptr pour cela. Créez un cycle de référence
 *         (le Parent pointe sur l'Enfant, l'Enfant pointe sur le Parent) et
 *         observez que les destructeurs ne sont jamais appelés (fuite de mémoire).
 *         Corrigez le problème en utilisant un std::weak_ptr pour le lien Enfant->Parent.
 */
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 4 ---\n\n";
}


// =========================================================================
// PARTIE 2 : PROGRAMMATION GÉNÉRIQUE AVANCÉE
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 5 : Les Templates Variadiques
// -------------------------------------------------------------------------
/*
 *  Objectif: Écrire des fonctions qui acceptent un nombre arbitraire d'arguments
 *            de types potentiellement différents.
 *
 *  Concepts: Template variadique (typename... Args), paquet de paramètres, récursion de templates.
 *
 *  Tâche: Écrivez une fonction 'print' générique et "typesafe" qui peut
 *         remplacer printf. L'appel `print("Bonjour", 42, 'c', 3.14);` doit
 *         afficher tous les arguments sur une ligne, séparés par des espaces.
 */
void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 5 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 6 : La Programmation "Compile-Time" (if constexpr)
// -------------------------------------------------------------------------
/*
 *  Objectif: Écrire du code générique qui s'adapte et se compile différemment
 *            en fonction des propriétés des types passés en paramètre.
 *
 *  Concepts: if constexpr, <type_traits> (ex: std::is_pointer, std::is_integral).
 *
 *  Tâche: Écrivez une fonction template 'avancer(T& arg)'.
 *         - Si 'arg' est un type entier (int, long...), la fonction doit l'incrémenter (++arg).
 *         - Si 'arg' est un pointeur, la fonction doit l'avancer (*arg++).
 *         - Pour tous les autres types, la fonction ne doit rien faire.
 *         Utilisez 'if constexpr' pour que le code invalide ne soit même pas compilé.
 */
void exercice6() {
    std::cout << "--- DEBUT EXERCICE 6 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 6 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 7 : La Méta-programmation par Template (TMP)
// -------------------------------------------------------------------------
/*
 *  Objectif: Effectuer des calculs durant la compilation plutôt qu'à l'exécution.
 *
 *  Concepts: Spécialisation de template, récursion de templates.
 *
 *  Tâche: Calculez la factorielle d'un nombre à la compilation. Créez un
 *         template de struct `Factorielle<N>` qui expose une valeur statique
 *         `value` égale à N!. L'appel `Factorielle<5>::value` doit être une
 *         constante de compilation égale à 120.
 */
void exercice7() {
    std::cout << "--- DEBUT EXERCICE 7 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 7 ---\n\n";
}


// =========================================================================
// PARTIE 3 : CONCURRENCE ET PARALLÉLISME
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 8 : Threads et Protection des Données
// -------------------------------------------------------------------------
/*
 *  Objectif: Lancer plusieurs threads et protéger les données partagées contre
 *            les "race conditions".
 *
 *  Concepts: <thread>, std::thread, <mutex>, std::mutex, std::lock_guard.
 *
 *  Tâche: Créez une variable globale 'compteur'. Lancez 10 threads. Chaque
 *         thread doit boucler 1 million de fois pour incrémenter le compteur.
 *         Affichez le résultat final. Constatez qu'il est incorrect.
 *         Corrigez le problème en protégeant l'accès au compteur avec un std::mutex.
 */
void exercice8() {
    std::cout << "--- DEBUT EXERCICE 8 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 8 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 9 : Le Parallélisme par Tâches (Futures)
// -------------------------------------------------------------------------
/*
 *  Objectif: Lancer des calculs en arrière-plan et récupérer leur résultat
 *            plus tard, de manière asynchrone.
 *
 *  Concepts: <future>, std::async, std::future.
 *
 *  Tâche: Écrivez une fonction qui simule un calcul long (ex: une boucle
 *         qui attend 2 secondes). Lancez cette fonction en tâche de fond avec
 *         std::async. Pendant que le calcul s'effectue, le thread principal
 *         doit afficher des messages. Enfin, récupérez et affichez le résultat
 *         du calcul en utilisant la méthode .get() du future.
 */
void exercice9() {
    std::cout << "--- DEBUT EXERCICE 9 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 9 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 10 : Les Objets Fonctions (std::function)
// -------------------------------------------------------------------------
/*
 *  Objectif: Stocker n'importe quel type d' "appelable" (fonction, lambda,
 *            objet avec operator()) dans une seule variable polymorphique.
 *
 *  Concepts: <functional>, std::function.
 *
 *  Tâche: Créez une map `std::map<std::string, std::function<int(int, int)>>`.
 *         Remplissez cette map pour associer des chaînes ("+", "-", "*") à des
 *         lambdas qui effectuent les opérations arithmétiques correspondantes.
 *         Créez une calculatrice simple qui utilise cette map pour exécuter
 *         l'opération demandée par l'utilisateur.
 */
void exercice10() {
    std::cout << "--- DEBUT EXERCICE 10 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 10 ---\n\n";
}


// =========================================================================
// LE GROS PROBLÈME FINAL : Implémentation d'un "Thread Pool"
// =========================================================================
/*
 *  Objectif: Synthétiser tous les concepts avancés (concurrence, gestion de
 *            ressources, templates, sémantique de déplacement, objets fonctions)
 *            dans un composant logiciel complexe et réutilisable.
 *
 *  Description:
 *      Créez une classe 'ThreadPool' qui gère un nombre fixe de threads "travailleurs".
 *      1. Le constructeur doit lancer N threads et les mettre en attente.
 *      2. Le destructeur doit notifier tous les threads de s'arrêter, puis les 'join'.
 *      3. Une méthode template 'enqueue' doit permettre de soumettre une tâche
 *         (n'importe quelle fonction avec n'importe quels arguments) au pool.
 *         Cette méthode doit retourner un std::future<ResultType> permettant de
 *         récupérer le résultat de la tâche plus tard.
 *      4. En interne, le pool doit utiliser une file d'attente de tâches thread-safe
 *         (protégée par un std::mutex) pour que les travailleurs puissent piocher
 *         du travail. Un std::condition_variable est nécessaire pour réveiller
 *         les threads en attente quand une nouvelle tâche arrive.
 */
void grosProblemeFinal() {
    std::cout << "--- DEBUT DU PROJET THREAD POOL ---\n\n";
    std::cout << "\n--- FIN DU PROJET THREAD POOL ---\n\n";
}


// =========================================================================
// Le programme principal (main)
// =========================================================================
int main() {
    std::cout << "*****************************************************\n";
    std::cout << "*            TEMPLATE D'EXERCICES AVANCES           *\n";
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