
/**
 * \file Catalogue.cpp
 * \author Omar Mahamat
 * \date 8 novembre 2025
 * \brief Implementation de la classe Catalogue 
 * \version 2.0
 */


#include "Catalogue.h"
#include "ContratException.h"
#include <sstream>
#include "ProduitException.h"
using namespace std;
using namespace util; 

namespace commerce {
    
/**
   * \brief Constructeur avec paramètres.
   *
   *        Initialise un catalogue avec un nom et une date de dernière mise à jour.
   *        Le nom du catalogue doit être non vide. En cas de violation, une erreur
   *        de précondition est générée.
   *
   * \param[in] p_nom Nom du catalogue.
   * \param[in] p_dateDerniereMiseAJour Date de dernière mise à jour du catalogue.
   *
   * \pre !p_nom.empty()
   * \post m_nom == p_nom
   * \post m_dateDerniereMiseAJour == p_dateDerniereMiseAJour
   */
    
Catalogue::Catalogue(const std::string& p_nom, const util::Date& p_dateDerniereMiseAJour): m_nom(p_nom), m_dateDerniereMiseAJour(p_dateDerniereMiseAJour) {
    
    PRECONDITION (!p_nom.empty());
    
    POSTCONDITION(m_nom == p_nom);
    POSTCONDITION(m_dateDerniereMiseAJour == p_dateDerniereMiseAJour);
    
    INVARIANTS();
}

 /**
   * \brief Constructeur de copie.
   *
   *        Copie en profondeur un catalogue existant. Tous les produits sont clonés
   *        individuellement via la méthode polymorphique Produit::clone().
   *
   * \param[in] p_catalogue Catalogue à copier.
   *
   * \post Le nouvel objet contient une copie complète et indépendante
   *       des produits du catalogue passé en paramètre.
   */
Catalogue::Catalogue(const Catalogue& p_catalogue): m_nom(p_catalogue.m_nom), m_dateDerniereMiseAJour(p_catalogue.m_dateDerniereMiseAJour) {
        for (const auto& produit : p_catalogue.m_produits) {
            m_produits.push_back(produit->clone());
        }
        INVARIANTS();
}

/**
 * \brief Opérateur d’assignation par copie.
 *
 *        Remplace le contenu du catalogue courant par une copie en profondeur
 *        d’un autre catalogue. Tous les produits du catalogue source sont
 *        clonés individuellement (via Produit::clone()) afin de préserver
 *        le polymorphisme et d’éviter tout partage de pointeurs.
 *
 * \param[in] p_catalogue Catalogue source à copier.
 *
 * \return Une référence vers le catalogue courant après la copie.
 *
 * \post m_nom == p_catalogue.m_nom
 * \post m_dateDerniereMiseAJour == p_catalogue.m_dateDerniereMiseAJour
 * \post Le nombre de produits du catalogue courant est égal à celui de p_catalogue.
 */

Catalogue& Catalogue::operator=(const Catalogue& p_catalogue)
{
    if (this != &p_catalogue) {
        m_nom = p_catalogue.m_nom;
        m_dateDerniereMiseAJour = p_catalogue.m_dateDerniereMiseAJour;

        m_produits.clear();
        for (const auto& produit : p_catalogue.m_produits) {
            m_produits.push_back(produit->clone());
        }

        INVARIANTS();
    }
    return *this;
}
 
 /**
   * \brief Retourne le nom du catalogue.
   * \return Une référence constante vers le nom.
   */          
const string& Catalogue::reqNom() const {
        return m_nom;
    }
 /**
   * \brief Retourne la date de dernière mise à jour.
   * \return Une référence constante vers la date.
   */
const Date& Catalogue::reqDateDerniereMiseAJour() const {
        return m_dateDerniereMiseAJour;
    }
/**
   * \brief Met à jour la date.
   * \param[in] p_date une nouvelle date.
   * \post m_dateDerniereMiseAJour == p_date.
   */

void Catalogue::asgDerniereMiseAJour(const util::Date& p_date)
{
    m_dateDerniereMiseAJour = p_date;
    POSTCONDITION(m_dateDerniereMiseAJour == p_date);
    INVARIANTS();

}
/**
 * \brief Ajoute un produit au catalogue.
 *
 *        Le produit passé en paramètre est cloné à l'aide de la méthode
 *        polymorphique Produit::clone(), afin d'éviter toute dépendance
 *        envers l'objet original. Avant l'ajout, la méthode vérifie que
 *        le code du produit n'est pas déjà présent dans le catalogue.
 *        En cas de doublon, une ProduitDejaPresentException est levée.
 *
 * \param[in] p_nouveauProduit Le produit à ajouter au catalogue.
 *
 * \exception ProduitDejaPresentException
 *            Levée si un produit possédant le même code est déjà présent.
 */


void Catalogue::ajouterProduit (const Produit& p_nouveauProduit)
{
    if (produitEstDejaPresent(p_nouveauProduit.reqCode())) {
        throw ProduitDejaPresentException(
            "Le produit suivant existe déjà. Voici son code: " + p_nouveauProduit.reqCode());
    }

    m_produits.push_back(p_nouveauProduit.clone());
    INVARIANTS();
}

/**
 * \brief Supprime un produit du catalogue à partir de son code.
 *
 *        Parcourt la liste des produits et recherche un produit dont le
 *        code correspond à celui passé en paramètre. Si un tel produit
 *        est trouvé, il est supprimé du catalogue. Dans le cas contraire,
 *        une ProduitAbsentException est levée.
 *
 * \param[in] p_codeProduit Code du produit à supprimer.
 *
 * \exception ProduitAbsentException
 *            Levée si aucun produit dans le catalogue ne correspond au code fourni.
 */

void Catalogue::supprimerProduit (const std::string& p_codeProduit)
{
    for (auto iter = m_produits.begin(); iter != m_produits.end(); ++iter) {
        if ((*iter)->reqCode() == p_codeProduit) {
            m_produits.erase(iter);
            INVARIANTS();
            return;
        }
    }

   
    throw ProduitAbsentException("Aucun produit avec le code : " + p_codeProduit);
}

 /**
   * \brief Retourne une version textuelle formatée du catalogue.
   *
   *        Cette représentation inclut :
   *        - le nom du catalogue ;
   *        - la date de dernière mise à jour ;
   *        - la liste des produits avec leur propre formatage.
   *
   * \return Une chaîne contenant la représentation formatée.
   */    
    
std::string Catalogue::reqCatalogueFormate() const{
    ostringstream oss;
    oss << "Catalogue " << m_nom << endl
    << "Dernière mise a jour : " << m_dateDerniereMiseAJour << endl;
    
    for (const auto& produit : m_produits) {
            oss << produit->reqProduitFormate() << endl;
        }
    return oss.str();
}

/**
 * \brief Vérifie si un produit avec un code donné est déjà présent dans le catalogue.
 *
 *        Parcourt la collection de produits et compare le code de chacun
 *        d’eux avec le code reçu en paramètre. La recherche s’arrête dès
 *        qu’un produit correspondant est trouvé.
 *
 * \param[in] p_codeProduit Code du produit à rechercher.
 *
 * \return true si un produit du catalogue possède ce code, false sinon.
 */

bool Catalogue::produitEstDejaPresent(const std::string& p_codeProduit) const
{
    for (auto iter = m_produits.begin(); iter != m_produits.end(); ++iter) {
        if ((*iter)->reqCode() == p_codeProduit) {
            return true;
        }
    }
    return false;
}
 /**
   * \brief Vérifie les invariants de la classe Catalogue.
   *
   * \invariant !m_nom.empty()
   */
void Catalogue::verifieInvariant() const{
    INVARIANT(!m_nom.empty());
}

} //namespace commerce
