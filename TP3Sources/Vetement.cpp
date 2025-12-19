
/** 
 * \file Vetement.cpp
 * \author Omar Mahamat
 * \date 13 novembre 2025
 * \brief Implémentation de la classe Vetement 
 */

#include "Vetement.h"
#include "ContratException.h"
#include <sstream>
using namespace std;
using namespace util;

namespace commerce{
    
    
 /**
   * \brief Constructeur avec paramètres
   *
   *        On construit un objet Vetement à partir des caractéristiques de base d’un produit
   *        (description, prix, code) et des informations propres à un vêtement : la taille
   *        et la couleur. La taille doit être l’une des tailles standards définies.
   *
   * \param[in] p_description description textuelle du vêtement
   * \param[in] p_prix prix du produit (positif ou nul)
   * \param[in] p_code code produit (valide selon les règles définies dans Produit)
   * \param[in] p_taille taille du vêtement (XS, S, M, L, XL, XXL)
   * \param[in] p_couleur couleur du vêtement (non vide)
   *
   * \pre p_taille est une taille standard (XS, S, M, L, XL, XXL)
   * \post m_taille == p_taille
   * \post m_couleur == p_couleur
   */
    
Vetement::Vetement(const string& p_description, double p_prix, const string& p_code, const string& p_taille, 
        const string& p_couleur): Produit(p_description, p_prix, p_code), m_taille(p_taille), m_couleur(p_couleur) 
{
    PRECONDITION( p_taille == "XS" || p_taille == "S" || p_taille == "M" ||
                  p_taille == "L" || p_taille == "XL" || p_taille == "XXL");
    
    POSTCONDITION(m_taille == p_taille);
    POSTCONDITION(m_couleur == p_couleur);
    
    INVARIANTS();
}
 /**
   * \brief Retourne la taille du vêtement.
   * \return une référence constante vers la taille (XS, S, M, L, XL, XXL)
   */
const string& Vetement::reqTaille() const {
    return m_taille;
}

 /**
   * \brief Retourne la couleur du vêtement.
   * \return une référence constante vers la couleur.
   */
const string& Vetement::reqCouleur() const {
    return m_couleur;
}
 /**
   * \brief Surcharge de l’opérateur d’égalité pour Vetement
   *
   *        Deux vêtements sont considérés comme égaux si :
   *        - leurs caractéristiques de base (description, prix, code) sont identiques,
   *        - leur taille est identique,
   *        - leur couleur est identique.
   *
   * \param[in] p_vetement vêtement à comparer à l'objet courant
   * \return true si les deux vêtements sont équivalents, false sinon
   */
bool Vetement::operator==(const Vetement& p_vetement) const {
    return Produit::operator==(p_vetement) && m_taille == p_vetement.m_taille &&
            m_couleur == p_vetement.m_couleur;
}
 /**
   * \brief Retourne une représentation textuelle du vêtement.
   *
   *        Cette méthode reprend le format de Produit puis ajoute les informations
   *        propres à Vetement : taille et couleur.

   * \return une chaîne contenant la description formatée du vêtement
   */
string Vetement::reqProduitFormate() const {
    ostringstream os;
    os << "----------------------------" << endl;
    os << "Produit Vetement" << endl;
    os << Produit::reqProduitFormate() << endl;
    os << "Taille : " << m_taille << endl;
    os << "Couleur : " << m_couleur << endl;
    return os.str();
}


/**
 * \brief Crée une copie polymorphique de l’objet courant.
 * \return Un pointeur unique vers un nouvel objet Vetement identique à l’objet courant.
 */
unique_ptr<Produit> Vetement::clone() const 
{
    return make_unique<Vetement>(*this);
}


 /**
   * \brief Teste l’invariant de la classe Vetement
   * 
   *        L’invariant garantit que :
   *        - la taille est parmi les tailles standards (XS, S, M, L, XL, XXL)
   *        Les invariants de la classe Produit sont également vérifiés par Produit.
   */
void Vetement::verifieInvariant() const {
    INVARIANT(m_taille == "XS" || m_taille == "S" || m_taille == "M" ||
              m_taille == "L" || m_taille == "XL" || m_taille == "XXL");
}
} // namespace commerce