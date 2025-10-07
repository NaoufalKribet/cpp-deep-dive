/******************************************************************************
 *
 *              Fichier d'Exercices – Niveau Expert en C++
 *
 *  Objectif: Atteindre une compréhension architecturale et systémique du C++.
 *            Cette série se concentre sur les design patterns, la performance
 *            de bas niveau, la méta-programmation avancée, les idiomes de
 *            C++20/23 et la conception de systèmes concurrents complexes.
 *
 *  Auteur : @Kribet Naoufal
 ******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <utility>
#include <thread>
#include <mutex>
#include <future>
#include <functional>
#include <type_traits>
#include <optional>     // C++17
#include <variant>      // C++17
#include <any>          // C++17
#include <ranges>       // C++20
#include <concepts>     // C++20
#include <coroutine>    // C++20
#include <atomic>       // Pour la programmation sans verrous

// =========================================================================
// PARTIE 1 : PATRONS DE CONCEPTION ET ARCHITECTURE LOGICIELLE
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 1 : Le Patron de Fabrique (Factory Pattern)
// -------------------------------------------------------------------------
/*
 *  Objectif: Découpler la création d'objets de leur utilisation, permettant
 *            d'ajouter de nouveaux types sans modifier le code client.
 *
 *  Concepts: Polymorphisme, Encapsulation, Pointeurs intelligents.
 *
 *  Tâche: En reprenant la hiérarchie de classes 'Personnage' (Guerrier, Mage),
 *         créez une classe 'PersonnageFactory'. Cette factory doit exposer une
 *         méthode statique `creerPersonnage(const std::string& type)` qui retourne
 *         un `std::unique_ptr<Personnage>`. Le code client ne doit plus jamais
 *         appeler `new Guerrier()` ou `new Mage()` directement.
 */
void exercice1() {
    std::cout << "--- DEBUT EXERCICE 1 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 1 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 2 : Le Patron Observateur (Observer Pattern)
// -------------------------------------------------------------------------
/*
 *  Objectif: Mettre en place un mécanisme de notification un-à-plusieurs
 *            sans que le sujet et ses observateurs soient fortement couplés.
 *
 *  Concepts: Interfaces (classes abstraites), Polymorphisme, std::vector, std::function.
 *
 *  Tâche: Créez un système de notification. Une classe 'Sujet' doit permettre
 *         à des objets 'Observateur' de s'enregistrer et de se désenregistrer.
 *         Quand l'état du 'Sujet' change (via une méthode `setEtat`), il doit
 *         automatiquement appeler une méthode `mettreAJour()` sur tous ses
 *         observateurs enregistrés.
 */
void exercice2() {
    std::cout << "--- DEBUT EXERCICE 2 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 2 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 3 : Le Patron de Stratégie (Strategy Pattern)
// -------------------------------------------------------------------------
/*
 *  Objectif: Permettre de changer l'algorithme utilisé par un objet à l'exécution.
 *
 *  Concepts: Composition, Interfaces, std::unique_ptr, std::function.
 *
 *  Tâche: Créez une classe 'ImageProcessor'. Au lieu d'implémenter les filtres
 *         (NoirEtBlanc, Sepia, Flou) directement dans la classe, créez une
 *         interface 'IFilter' et des classes concrètes pour chaque filtre.
 *         L'ImageProcessor doit avoir une méthode `setFilter(std::unique_ptr<IFilter> f)`
 *         et une méthode `appliquerFiltre()` qui utilise le filtre actuellement défini.
 */
void exercice3() {
    std::cout << "--- DEBUT EXERCICE 3 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 3 ---\n\n";
}


// =========================================================================
// PARTIE 2 : PERFORMANCE ET PROGRAMMATION SYSTÈME
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 4 : Conception Orientée Données (Data-Oriented Design)
// -------------------------------------------------------------------------
/*
 *  Objectif: Comprendre l'impact de l'organisation de la mémoire sur la
 *            performance en optimisant l'utilisation du cache CPU.
 *
 *  Concepts: Cache CPU (localité spatiale/temporelle), Array of Structs (AoS) vs.
 *            Struct of Arrays (SoA).
 *
 *  Tâche: Créez une structure 'Particle' (position, vélocité, couleur).
 *         1. Stockez 10 millions de particules dans un `std::vector<Particle>` (AoS).
 *         2. Créez une structure `ParticleSystem` qui stocke les données en SoA
 *            (`std::vector<Position>`, `std::vector<Velocite>`, etc.).
 *         3. Écrivez une fonction qui met à jour uniquement la position de toutes les
 *            particules. Mesurez et comparez le temps d'exécution sur les deux
 *            structures de données. Expliquez la différence.
 */
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 4 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 5 : Allocateurs Personnalisés
// -------------------------------------------------------------------------
/*
 *  Objectif: Prendre le contrôle total de l'allocation mémoire pour des besoins
 *            spécifiques (performance, fragmentation).
 *
 *  Concepts: operator new/delete, placement new, Allocator STL.
 *
 *  Tâche: Implémentez un allocateur "pool" (ou "arena"). Cet allocateur
 *         pré-alloue un grand bloc de mémoire une seule fois. Les allocations
 *         suivantes sont des services quasi-instantanés de pointeurs dans ce bloc,
 *         sans appel système. Implémentez l'interface requise pour l'utiliser
 *         avec un `std::vector`.
 */
void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 5 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 6 : SFINAE et Techniques de Méta-programmation
// -------------------------------------------------------------------------
/*
 *  Objectif: Écrire du code générique qui s'active ou se désactive à la compilation
 *            en fonction des propriétés d'un type, permettant une spécialisation fine.
 *
 *  Concepts: SFINAE (Substitution Failure Is Not An Error), std::enable_if, Concepts (C++20).
 *
 *  Tâche: Écrivez une fonction template `serialize(const T& value)`.
 *         - Si T est un type intégral, elle doit l'écrire en binaire.
 *         - Si T est un std::string, elle doit l'écrire tel quel.
 *         - Si T a une méthode `.serialize()`, la fonction doit l'appeler.
 *         Implémentez ceci en utilisant SFINAE (ou des concepts si vous utilisez C++20).
 */
void exercice6() {
    std::cout << "--- DEBUT EXERCICE 6 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 6 ---\n\n";
}


// =========================================================================
// PARTIE 3 : C++20 ET AU-DELÀ
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 7 : Ranges et Vues
// -------------------------------------------------------------------------
/*
 *  Objectif: Utiliser la bibliothèque Ranges de C++20 pour écrire des
 *            algorithmes déclaratifs, expressifs et composables.
 *
 *  Concepts: <ranges>, vues (views), projections, pipe operator (|).
 *
 *  Tâche: Soit un vecteur de `struct Personne { std::string nom; int anneeNaissance; }`.
 *         En une seule expression, sans boucle explicite, produisez une nouvelle
 *         liste contenant les noms, en majuscules, des personnes nées avant 1980,
 *         triée par ordre alphabétique.
 */
void exercice7() {
    std::cout << "--- DEBUT EXERCICE 7 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 7 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 8 : Coroutines
// -------------------------------------------------------------------------
/*
 *  Objectif: Écrire du code asynchrone de manière séquentielle et lisible.
 *
 *  Concepts: <coroutine>, co_await, co_yield, co_return, Promise/Future.
 *
 *  Tâche: Implémentez un "générateur". Créez une fonction coroutine qui
 *         `co_yield` les nombres de la suite de Fibonacci un par un, sans
 *         jamais bloquer et sans les stocker tous en mémoire.
 */
void exercice8() {
    std::cout << "--- DEBUT EXERCICE 8 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 8 ---\n\n";
}

// =========================================================================
// PARTIE 4 : CONCURRENCE AVANCÉE
// =========================================================================

// -------------------------------------------------------------------------
// EXERCICE 9 : Les atomiques et la Mémoire Lock-Free
// -------------------------------------------------------------------------
/*
 *  Objectif: Écrire du code concurrent sans utiliser de verrous (mutex), en
 *            manipulant directement les opérations atomiques du processeur.
 *
 *  Concepts: <atomic>, std::atomic<T>, ordres mémoire (memory ordering).
 *
 *  Tâche: Implémentez un compteur de références thread-safe pour un pointeur
 *         intelligent personnalisé en utilisant `std::atomic<unsigned int>`.
 *         Assurez-vous que l'incrémentation et la décrémentation sont correctes
 *         même si plusieurs threads copient et détruisent le pointeur en même temps.
 */
void exercice9() {
    std::cout << "--- DEBUT EXERCICE 9 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 9 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 10 : L'API C++ et l'Interfaçage C
// -------------------------------------------------------------------------
/*
 *  Objectif: Exposer une API C++ complexe à travers une interface C simple et
 *            stable (ABI), permettant l'interopérabilité avec d'autres langages.
 *
 *  Concepts: extern "C", ABI (Application Binary Interface), pointeurs opaques.
 *
 *  Tâche: Prenez votre classe `CompteBancaire`. Créez un en-tête C (`.h`)
 *         qui expose ses fonctionnalités via des fonctions C pures.
 *         Ex: `CompteHandle* create_account(double initial_balance);`
 *             `void deposit(CompteHandle* account, double amount);`
 *             `void destroy_account(CompteHandle* account);`
 *         Le code C++ implémentera ces fonctions en faisant le lien avec la classe.
 */
void exercice10() {
    std::cout << "--- DEBUT EXERCICE 10 ---\n\n";
    std::cout << "\n--- FIN EXERCICE 10 ---\n\n";
}


// =========================================================================
// LE GROS PROBLÈME FINAL : Système de Journalisation (Logger) Asynchrone
// =========================================================================
/*
 *  Objectif: Synthétiser tous les concepts (design patterns, concurrence,
 *            performance, gestion des ressources) pour créer un composant
 *            logiciel de qualité professionnelle.
 *
 *  Description:
 *      Implémentez un système de logging asynchrone, performant et thread-safe.
 *      1.  **Façade et Singleton :** L'accès au logger doit se faire via une
 *          interface simple et globale (ex: `Logger::getInstance().log(level, message);`).
 *      2.  **Asynchronisme :** L'appel à `log()` ne doit PAS bloquer le thread
 *          appelant. Il doit simplement mettre le message dans une file d'attente
 *          et retourner immédiatement. Un thread "travailleur" dédié doit
 *          consommer les messages de cette file et les écrire dans la destination.
 *      3.  **Concurrence :** La file d'attente doit être thread-safe. Utilisez un
 *          mutex et une condition_variable pour la synchronisation.
 *      4.  **Extensibilité (Patron Stratégie) :** Le logger doit pouvoir écrire
 *          vers différentes destinations (console, fichier...). Créez une
 *          interface `ILogSink` et permettez à l'utilisateur d'ajouter
 *          différents "sinks" au logger.
 *      5.  **Gestion des ressources (RAII) :** Le destructeur du logger doit
 *          garantir que tous les messages restants dans la file sont écrits
 *          avant que le programme ne se termine.
 */
void grosProblemeFinal() {
    std::cout << "--- DEBUT DU PROJET LOGGER ASYNCHRONE ---\n\n";
    std::cout << "\n--- FIN DU PROJET LOGGER ASYNCHRONE ---\n\n";
}


// =========================================================================
// Le programme principal (main)
// =========================================================================
int main() {
    std::cout << "*****************************************************\n";
    std::cout << "*             TEMPLATE D'EXERCICES EXPERTS          *\n";
    std::cout << "*****************************************************\n\n";

    // Décommentez la ligne de l'exercice sur lequel vous voulez travailler.
    // exercice1();

    return 0;
}