

/** 
 * \file Electronique.cpp
 * \author Omar Mahamat
 * \date 8 novembre 2025
 * \biref Implémentation de la classe Electronique
 */

#include "Electronique.h"
#include "ContratException.h"
#include <sstream>
using namespace std;

namespace commerce{
    
 /**
   * \brief Constructeur avec paramètres
   *
   *        On construit un objet Electronique à partir des informations de base d’un produit
   *        (description, prix, code) et des informations propres aux produits électroniques :
   *        la durée de garantie et l’état (reconditionné ou non).
   *
   * \param[in] p_description chaîne décrivant le produit (doit être non vide)
   * \param[in] p_prix prix du produit (doit être positif ou nul)
   * \param[in] p_code code du produit (doit être valide selon util::validerCodeProduit)
   * \param[in] p_garantieMois durée de garantie en mois (doit être positive ou nulle)
   * \param[in] p_estReconditionne booléen indiquant si le produit est reconditionné (true) ou neuf (false)
   *
   * \pre p_garantieMois >= 0
   * \pre Les préconditions de Produit sont respectées (voir constructeur de Produit)
   * \post m_garantieMois == p_garantieMois
   */
Electronique::Electronique(const string& p_description, double p_prix, const string& p_code, int p_garantieMois, bool p_estReconditionne):Produit(p_description, p_prix, p_code),m_garantieMois(p_garantieMois),m_estReconditionne(p_estReconditionne) {
    PRECONDITION(p_garantieMois >= 0);
    
    POSTCONDITION(m_garantieMois == p_garantieMois);
    
    INVARIANTS();
}
 /**
   * \brief Retourne la durée de garantie du produit électronique en mois.
   * \return Un entier représentant la durée de garantie (en mois).
   */

 int Electronique::reqGarantieMois() const
 {
     return m_garantieMois;
     
 }
    
 /**
   * \brief Indique si le produit est reconditionné.
   * \return true si le produit est reconditionné, false s’il est neuf.
   */
 
bool Electronique::reqEstReconditionne() const
{
    
    return m_estReconditionne;
    
}
 /**
   * \brief Surcharge de l’opérateur d’égalité pour la classe Electronique.
   *
   *        Deux produits électroniques sont considérés comme égaux si :
   *        - leurs attributs de base (description, prix, code) sont égaux (comparaison via Produit) ;
   *        - leur durée de garantie est identique ;
   *        - leur état (reconditionné ou non) est identique.
   *
   * \param[in] p_electronique produit électronique à comparer à l’objet courant.
   * \return true si tous les attributs sont égaux, false sinon.
   */
bool Electronique::operator==(const Electronique& p_electronique) const 
{
     return Produit::operator==(p_electronique) && m_garantieMois == p_electronique.m_garantieMois 
             && m_estReconditionne == p_electronique.m_estReconditionne;
}



 /**
   * \brief Méthode de clonage polymorphique.
   *
   *        Cette méthode permet de créer dynamiquement une copie d’un produit
   *        électronique, tout en la retournant sous la forme d’un std::unique_ptr<Produit>.
   *        Cela facilite l’utilisation polymorphique de la classe dans un conteneur
   *        de produits (par exemple dans Catalogue).
   *
   * \return Un pointeur intelligent vers une nouvelle instance d’Electronique copiée.
   */
unique_ptr<Produit> Electronique::clone() const 
{
        return make_unique<Electronique>(*this);
}
 /**
   * \brief Retourne une représentation textuelle détaillée du produit électronique.
   *
   *        Cette méthode reprend d’abord la représentation textuelle du produit de base
   *        (via Produit::reqProduitFormate()), puis y ajoute les informations
   *        spécifiques aux produits électroniques :
   *        - la durée de garantie en mois ;
   *        - l’état (reconditionné ou non).
   * \return Une chaîne de caractères contenant la description formatée du produit électronique.
   */


 string Electronique::reqProduitFormate() const {
        ostringstream oss;
        oss << "----------------------------" << endl;
        oss << "Produit Electronique" << endl;
        // Informations de base du produit
        oss << Produit::reqProduitFormate() << endl;
        // Informations spécifiques à Electronique
        oss << "Garantie : " << reqGarantieMois() << " mois" << endl;
        oss << "Reconditionné : " << (reqEstReconditionne() ? "Oui" : "Non") << endl;
        return oss.str();
    }



/**
   * \brief Teste l’invariant de la classe Electronique.
   *
   *        L’invariant de cette classe s’assure que :
   *        - la durée de garantie est positive ou nulle ;
   *        - les invariants de la classe de base Produit sont respectés (assurés par Produit).
   */


void Electronique::verifieInvariant() const {
    INVARIANT(m_garantieMois >= 0);
}

} // namespace commerce