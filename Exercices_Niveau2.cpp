/******************************************************************************
 *
 *       Fichier d'Exercices Intermédiaires - Apprentissage du C++
 *
 *  Objectif: Mettre en pratique les concepts de Programmation Orientée Objet,
 *            la gestion moderne des ressources et la programmation générique.
 *
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

// D'abord, la classe, qui est maintenant un "moteur" propre et autonome.


// class CompteBancaire {
// private:
//     double solde;
// public:
//     CompteBancaire() : solde(0.0) {}
//     CompteBancaire(double SoldeInitial) : solde(SoldeInitial) {}

//     // Méthode pour retirer de l'argent
//     void Retrait(double retrait) {
//         if (solde > 0 && solde >= retrait) {
//             solde -= retrait;
//         } else {
//             std::cout << "Solde insuffisant" << std::endl;
//         }
//         std::cout << "Votre solde est de : " << solde << " EUR." << std::endl;
//     }

//     // Méthode pour déposer de l'argent
//     void Depot(double depot) {
//         if (depot > 0) {
//             solde += depot;
//         } else {
//             std::cout << "Rentre un dépot suffisant" << std::endl;
//         }
//         std::cout << "Votre solde est de : " << solde << " EUR." << std::endl;
//     }

//     // Méthode pour consulter le solde
//     void checkSolde() const {
//         std::cout << "Votre solde est de : " << solde << " EUR." << std::endl;
//     }
// };

void exercice2() {
    CompteBancaire compte;
    int choix = 0;
    while (choix != 4) {
        std::cout << "\n#===== Bienvenue sur ton compte =====#\n"
                  << "1. Retirer de l'argent\n"
                  << "2. Deposer de l'argent\n"
                  << "3. Consulter son solde\n"
                  << "4. Quitter\n"
                  << "Choix : ";
        std::cin >> choix;
        std::cin.ignore();

        switch (choix) {
            case 1: {
                std::string retrait_texte;
                double retrait;
                std::cout << "Combien veux-tu retirer ? ";
                std::getline(std::cin, retrait_texte);
                try {
                    retrait = std::stod(retrait_texte);
                    compte.Retrait(retrait);
                } catch (const std::exception& e) {
                    std::cerr << "Retrait invalide" << std::endl;
                }
                break;
            }
            case 2: {
                std::string depot_texte;
                double depot;
                std::cout << "Combien veux-tu deposer ? ";
                std::getline(std::cin, depot_texte);
                try {
                    depot = std::stod(depot_texte);
                    compte.Depot(depot);
                } catch (const std::exception& e) {
                    std::cerr << "Dépôt invalide" << std::endl;
                }
                break;
            }
            case 3:
                compte.checkSolde();
                break;
            case 4:
                std::cout << "Au revoir !" << std::endl;
                break;
            default:
                std::cout << "Choix invalide." << std::endl;
        }
    }
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
 * 
 */

// class CompteEpargne : public CompteBancaire {
// private:
//     double tauxInteret;
// public:
//     CompteEpargne(double soldeInitial, double taux) : CompteBancaire(soldeInitial), tauxInteret(taux) {}

//     void interet() {
//         double montantInteret = tauxInteret * getSolde();
//         Depot(montantInteret);
//         std::cout << "Intérêts ajoutés : " << montantInteret << " EUR." << std::endl;
//     }

//     double getSolde() const {
//         return CompteBancaire::checkSolde(); 
//     }
// };
// void exercice3() {
//     std::cout << "--- DEBUT EXERCICE 3 ---\n\n";

//     std::string solde_text, interet_text;
//     double soldeInitial = 0.0, taux = 0.0;

//     std::cout << "Donne moi le solde initial : ";
//     while (true) {
//         std::getline(std::cin, solde_text);
//         try {
//             soldeInitial = std::stod(solde_text);
//             break;
//         } catch (const std::exception& e) {
//             std::cerr << "Solde invalide" << std::endl;
//         }
//     }

//     std::cout << "Donne moi le taux d'interet de ta banque : ";
//     while (true) {
//         std::getline(std::cin, interet_text);
//         try {
//             taux = std::stod(interet_text);
//             break;
//         } catch (const std::exception& e) {
//             std::cerr << "Taux d'interet invalide" << std::endl;
//         }
//     }

//     CompteEpargne epargne(soldeInitial, taux);
//     std::cout << "Solde avant intérêts : " << epargne.getSolde() << " EUR." << std::endl;
//     epargne.interet();
//     std::cout << "Solde après intérêts : " << epargne.getSolde() << " EUR." << std::endl;

//     std::cout << "\n--- FIN EXERCICE 3 ---\n\n";
// }

//--------------------------------------------------------------------------
// EXERCICE 3.5 : L'héritage
//--------------------------------------------------------------------------
/*
* Objectif : S'exercer.
* Une classe voiture, et une classe Derive qui hérite de voiture mais en + on a la couleur
*/

class Voiture{
    protected:
        double vitesse;
    public:
        Voiture() : vitesse(0.0){}
        Voiture(double vitesse_initial) : vitesse(vitesse_initial){}

        double distance_parcourue(double temps){
            double distance;
            if (temps>0){
                distance=temps*vitesse;
                return distance;
            } else { 
                std::cout << "Erreur le temps doit être positif" <<std::endl;
                return 0.0;
            }
        }
};

class Derive : public Voiture{
    protected:
        std::string couleur;
    public:
        Derive(double vitesse, std::string laCouleur) : Voiture(vitesse), couleur(laCouleur){}

    void afficher_couleur(){
        std::cout << "Afficher la couleur : " << couleur << std::endl;
    }

    void couleur_et_distance(double temps){
        double distance;
        afficher_couleur();
        distance = distance_parcourue(temps);
        std::cout <<" La voiture " <<  couleur << "à parcouru" << distance << "Km." << std::endl;
    }
};

void exercice35(){
    double distanceSimple;
    Derive maVoiture(140.0,"Rouge");
    maVoiture.afficher_couleur();
    distanceSimple=maVoiture.distance_parcourue(2.0);
    std::cout<<"Afficher la distance"<< distanceSimple<< std::endl;

    maVoiture.couleur_et_distance(2.0);
}

class ObjetBase {
protected:
    double taille;

public:
    ObjetBase() : taille(0.0) {}
    // CORRECTION : Le corps du constructeur est {}, pas ;
    ObjetBase(double taille_initiale) : taille(taille_initiale) {}

    // CORRECTION : La méthode modifie maintenant l'objet, donc elle retourne void.
    void augmenter(double facteur) {
        double taille_augmentee;
        // CORRECTION : Ajout du point-virgule.
        taille_augmentee = taille * facteur;
        std::cout << "Initialement la taille était de : " << taille 
                  << ". Après augmentation d'un facteur " << facteur 
                  << ", on est sur du " << taille_augmentee << std::endl;
        
        // CORRECTION : Mise à jour de l'état de l'objet.
        taille = taille_augmentee;
    }
};

// --- CLASSE DÉRIVÉE ---
class ObjetDerive : public ObjetBase {
protected:
    std::string couleur;

public:
    // CORRECTION : On passe le paramètre 'taille', pas une variable inexistante.
    ObjetDerive(double taille, std::string laCouleur) : ObjetBase(taille), couleur(laCouleur) {}

    void afficher_details() {
        // CORRECTION : On utilise le membre 'couleur', pas le paramètre 'laCouleur'.
        std::cout << "Détails -> Taille : " << taille << ", Couleur : " << couleur << std::endl;
    }
};

// --- FONCTION DE TEST ---
void exercice36() {
    std::cout << "--- DEBUT DU TEST ---\n\n";

    ObjetDerive situation(9.0, "Vert");
    situation.afficher_details();
    std::cout << "\n";

    std::cout << "--- Augmentation d'un facteur 1.5 ---\n";
    // La méthode modifie l'objet directement, pas besoin de récupérer une valeur.
    situation.augmenter(1.5);
    situation.afficher_details(); // On vérifie que la taille a bien changé.
    std::cout << "\n";
    
    std::cout << "--- Augmentation d'un facteur 2 ---\n";
    situation.augmenter(2.0);
    situation.afficher_details(); // On vérifie la nouvelle taille.
    
    std::cout << "\n--- FIN DU TEST ---\n\n";
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

#include <iostream>
#include <string>
#include <vector>

// --- CLASSE DE BASE CORRIGÉE ---
class CompteBancaire {
protected:
    double solde;

public:
    // Constructeur paramétré (plus utile que celui par défaut ici)
    CompteBancaire(double monSolde) : solde(monSolde) {}

    // RÈGLE D'OR : Le destructeur DOIT être virtuel
    virtual ~CompteBancaire() {}

    void checkSolde() const { // 'const' car elle ne modifie pas l'objet
        std::cout << "Le solde est de : " << solde << " EUR." << std::endl;
    }

    // On change le type de retour en bool, plus logique pour une transaction.
    virtual bool retirer(double montant) {
        std::cout << "Tentative de retrait (standard) de " << montant << " EUR... ";
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            std::cout << "Succès.\n";
            return true;
        } else {
            std::cout << "Échec. Solde insuffisant.\n";
            return false;
        }
    }

    virtual void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            std::cout << "Dépôt de " << montant << " EUR réussi.\n";
        } else {
            std::cout << "Dépôt impossible, montant négatif.\n";
        }
    }
};

// --- CLASSE DÉRIVÉE CORRIGÉE ---
// On crée une classe C

class CompteEpargne : public CompteBancaire {
public:
    // Le constructeur appelle juste celui de la classe mère.
    CompteEpargne(double solde) : CompteBancaire(solde) {}
};

// Votre classe CompteCourant corrigée.
class CompteCourant : public CompteBancaire {
private:
    double decouvertAutorise;

public:
    // CORRECTION : Appel correct du constructeur mère.
    CompteCourant(double solde, double monDecouvert)
        : CompteBancaire(solde), decouvertAutorise(monDecouvert) {}

    // CORRECTION : Logique du découvert
    // 'override' est une sécurité pour vérifier qu'on redéfinit bien une méthode virtuelle.
    bool retirer(double montant) override {
        std::cout << "Tentative de retrait (compte courant) de " << montant << " EUR... ";
        // On vérifie que le retrait ne nous met pas plus bas que le découvert autorisé.
        if (montant > 0 && (solde - montant >= -decouvertAutorise)) {
            solde -= montant;
            std::cout << "Succès.\n";
            return true;
        } else {
            std::cout << "Échec. Plafond de découvert dépassé.\n";
            return false;
        }
    }
};
void exercice4() {
    std::cout << "--- DEBUT EXERCICE 4 : Polymorphisme ---\n\n";

    // d. Créez un vecteur de pointeurs de CompteBancaire.
    std::vector<CompteBancaire*> portefeuille;

    // On remplit le vecteur avec des instances allouées dynamiquement.
    // 'new' retourne une adresse (un pointeur).
    std::cout << "Création des comptes...\n";
    portefeuille.push_back(new CompteEpargne(500.0));       // Pointeur vers un CompteEpargne
    portefeuille.push_back(new CompteCourant(200.0, 100.0)); // Pointeur vers un CompteCourant (peut aller jusqu'à -100)
    portefeuille.push_back(new CompteCourant(50.0, 50.0));   // Pointeur vers un autre CompteCourant (peut aller jusqu'à -50)
    std::cout << "--------------------------------\n\n";

    // e. Parcourez le vecteur et appelez les méthodes virtuelles.
    int i = 1;
    for (CompteBancaire* comptePtr : portefeuille) {
        std::cout << "--- Opérations sur le compte n°" << i++ << " ---\n";
        comptePtr->checkSolde();
        
        // C'est ici que la magie du polymorphisme opère.
        // Même si 'comptePtr' est de type 'CompteBancaire*',
        // c'est la bonne méthode 'retirer()' (celle de CompteCourant ou CompteBancaire)
        // qui sera appelée à l'exécution !
        comptePtr->retirer(250.0);
        
        comptePtr->checkSolde();
        std::cout << "\n";
    }

    // f. N'oubliez pas de libérer la mémoire allouée dynamiquement.
    std::cout << "--------------------------------\n";
    std::cout << "Nettoyage de la mémoire...\n";
    for (CompteBancaire* comptePtr : portefeuille) {
        delete comptePtr; // On libère chaque objet créé avec 'new'.
    }
    portefeuille.clear(); // On vide le vecteur de ses pointeurs (maintenant invalides).

    std::cout << "\n--- FIN EXERCICE 4 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 4.1 : Le Polymorphisme et les Formes Géométriques
// -------------------------------------------------------------------------
/*
 *  Objectif: Calculer l'aire totale d'une collection de formes diverses sans
 *            jamais avoir à connaître le type spécifique de chaque forme.
 *
 *  Concepts: virtual, polymorphisme, override, classe abstraite, fonction virtuelle pure.
 *
 *  Tâche: Créez un système de gestion de formes géométriques.
 *      a. Créez une classe de base abstraite 'Forme'.
 *         - Elle doit déclarer une fonction virtuelle pure : 'double calculerAire() const = 0;'.
 *         - Elle doit avoir un destructeur virtuel.
 *      b. Créez deux classes dérivées concrètes : 'Rectangle' et 'Cercle'.
 *         - 'Rectangle' aura une largeur et une hauteur.
 *         - 'Cercle' aura un rayon.
 *         - Chaque classe doit implémenter (override) la méthode 'calculerAire'
 *           pour effectuer le calcul correspondant à sa géométrie.
 *      c. Dans la fonction exercice4_1, créez un vecteur de pointeurs de
 *         'Forme' (std::vector<Forme*>).
 *      d. Remplissez ce vecteur avec plusieurs instances de 'Rectangle' et de
 *         'Cercle' allouées dynamiquement avec 'new'.
 *      e. Parcourez le vecteur et calculez l'aire totale de toutes les formes
 *         en appelant la méthode 'calculerAire' sur chaque pointeur.
 *      f. N'oubliez pas de libérer la mémoire allouée dynamiquement à la fin.
 */

 #include <cmath>

 class Forme{
    public:
        virtual double calculerAire() const = 0;
        virtual ~Forme(){} 
 };

 class Rectangle{
    private:
        double LARGEUR, HAUTEUR;
    public:
        Rectangle(double l, double h) : largeur(l), hauteur(h) {}
        double calculerAire() override{
            if (LARGEUR>0 && HAUTEUR>0){
                double air=LARGEUR*HAUTEUR;
                return air;
            } else {
                return 0.0;
            }        
        }
 };

 class Cercle{
    private:
        double RAYON;
    public:
        Cercle(double r) : RAYON(r) {}
        double calculerAire() const override{
            if (RAYON>0){
                double air = RAYON*M_PI*RAYON;
                return air;
            } else {
                return 0.0;
            }
        }
 }

 void exercice4_1(){
    std::vector<Forme*> geometrie;
    geometrie.push_back(new Cercle);
    geometrie.push_back(new Rectangle);

    for (Forme* ptr_forme : geometrie){
        double air = ptr_forme->calculerAire()
        std::cout << "L'air calculé est égale à :" << air << std::endl;   
    }

    for(Forme* ptr_forme : geometrie){
        delete.ptr_forme;
    }
    geometrie.clear()
    std::cout << "\n--- FIN EXERCICE 4_1 ---\n\n";
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

 class vecteur2D{
    public:
        double x,y;

        vecteur2D operator+(const vecteur2D& autre) const{
            vecteur2D resultat;
            resultat.x=this->x + autre.x;
            resultat.y=this->y + autre.y;
            return resultat;
    }
 };

void exercice5() {
    std::cout << "--- DEBUT EXERCICE 5 ---\n\n";
    vecteur2D v2={6,8};
    vecteur2D v1={2,3};
    vecteur2D v3=v1+v2;

    std::cout << "Affichage du vecteur v3 : " << v3 << std::endl;
    std::cout << "\n--- FIN EXERCICE 5 ---\n\n";
}

// -------------------------------------------------------------------------
// EXERCICE 6 : La Propriété et la Durée de Vie des Ressources (RAII)
// -------------------------------------------------------------------------
/*
 *  Objectif: Comprendre et appliquer le principe le plus important du C++ moderne :
 *            RAII (Resource Acquisition Is Initialization). L'objectif est de lier
 *            la durée de vie d'une ressource à la durée de vie d'un objet, rendant
 *            les fuites de ressources (mémoire, fichiers, verrous...) impossibles.
 *
 *  Concepts: RAII, propriété exclusive, std::unique_ptr, std::make_unique, std::move.
 *
 *  Tâche: Créez un système simple de gestion de "connexions" à un serveur.
 *      a. Créez une classe simple 'Connexion' qui simule une ressource.
 *         - Son constructeur affichera ">> Connexion(ID) établie."
 *         - Son destructeur affichera "<< Connexion(ID) fermée."
 *         - Donnez-lui un ID (entier ou string) pour la différencier.
 *
 *      b. Écrivez une première fonction 'gestionManuelle()'.
 *         - Dans cette fonction, créez un std::vector<Connexion*> pour stocker
 *           des pointeurs vers des connexions.
 *         - Allouez dynamiquement (avec 'new') plusieurs objets 'Connexion' et
 *           stockez leurs pointeurs dans le vecteur.
 *         - Simulez une "erreur" au milieu de la fonction en faisant un 'return'
 *           prématuré.
 *         - Observez à l'exécution que les messages des destructeurs ne sont
 *           jamais affichés pour les connexions créées avant l'erreur.
 *           Vous avez créé une fuite de ressource.
 *
 *      c. Écrivez une seconde fonction 'gestionAutomatiqueRAII()'.
 *         - Cette fois, créez un std::vector<std::unique_ptr<Connexion>>.
 *           Un 'unique_ptr' est un objet qui "possède" un pointeur brut. Quand
 *           l'unique_ptr est détruit, il appelle automatiquement 'delete' sur
 *           le pointeur qu'il possède.
 *         - Remplissez le vecteur en utilisant std::make_unique<Connexion>(...).
 *           'make_unique' est la façon moderne et sûre d'allouer dynamiquement
 *           et de créer un unique_ptr en une seule étape.
 *         - Comme précédemment, simulez une erreur avec un 'return' prématuré.
 *         - Observez que, même avec le 'return' prématuré, les messages des
 *           destructeurs de toutes les connexions créées sont bien affichés.
 *           La libération est maintenant automatique et garantie.
 *
 *      d. Dans cette seconde fonction, démontrez le concept de "transfert de
 *         propriété" en sortant un unique_ptr du vecteur et en le plaçant dans
 *         une variable locale en utilisant 'std::move'.
 */

class Connexion {
private: 
    int id_;
public:
    Connexion(int identifiant) : id_(identifiant) {
        std::cout << ">> Connexion(" << id_ << ") etablie." << std::endl;
    }
    ~Connexion() {
        std::cout << "<< Connexion(" << id_ << ") fermee." << std::endl;
    }
};

void gestionManuelle() {
    std::cout << "\n--- Début de la gestion manuelle ---\n";
    std::vector<Connexion*> connexions_ouvertes;

    std::cout << "Allocation des ressources...\n";
    connexions_ouvertes.push_back(new Connexion(1));
    connexions_ouvertes.push_back(new Connexion(2));
    connexions_ouvertes.push_back(new Connexion(3));
    std::cout << "\n!!! Une erreur se produit, sortie prématurée de la fonction !!!\n";
    if (true) { 
        return;
    }

    std::cout << "\nNettoyage manuel de la mémoire...\n";
    for (Connexion* ptr_connexion : connexions_ouvertes) {
        delete ptr_connexion;
    }

    connexions_ouvertes.clear();
    std::cout << "--- Fin de la gestion manuelle ---\n";
}

void gestionAutomatiqueRAII(){
    std::cout << " Debut de la gestion Automatique" << std::endl;
    std::vector<std::unique_ptr<Connexion>> connexions_auto;

    connexions_auto.push_back(std::make_unique<Connexion>(new Connexion(1)));
    connexions_auto.push_back(std::make_unique<Connexion>(new Connexion(2)));
    connexions_auto.push_back(std::make_unique<Connexion>(new Connexion(3)));
    std::cout << "\n!!! Admettons qu'une erreur se produise, sortie prématurée de la fonction !!!\n";

    propriete = std::move(connexions_auto[1]);
    if(propriete){
        propriete->utiliser();
    }

    std::cout << "L'emplacement dans le vecteur est maintenant vide (nullptr).\n";
    if (connexions_auto[1] == nullptr) {
        std::cout << "   connexions_auto[1] est bien vide.\n";
    }
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
    //exercice3();
    //exercice35();
    exercice36();
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