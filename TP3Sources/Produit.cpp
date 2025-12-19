/** 
 * \file Produit.cpp
 * \author Omar Mahamat
 * \date 8 novembre 2025
 * \brief L'implémentation de la classe Produit
 */


#include "Produit.h"
#include <string>
#include <sstream>

using namespace std;

namespace commerce{
  
  /**
   * \brief Constructeur avec paramètres
   *        On construit un objet Produit à partir de valeurs passées en paramètres.
   *        Les attributs sont assignés seulement si les valeurs sont considérées comme valides.
   *        Autrement, une erreur de précondition est générée.
   * \param[in] p_description chaîne décrivant le produit (doit être non vide)
   * \param[in] p_prix prix du produit (doit être positif ou nul)
   * \param[in] p_code code du produit (doit être valide selon util::validerCodeProduit)
   * \pre !p_description.empty()
   * \pre p_prix >= 0
   * \pre util::validerCodeProduit(p_code)
   * \post m_description == p_description
   * \post m_prix == p_prix
   * \post m_code == p_code
   */
    
    
Produit::Produit(const std::string& p_description, double p_prix,const std::string& p_code):m_description(p_description), m_prix(p_prix), m_code(p_code)
{
    PRECONDITION(!p_description.empty());
    PRECONDITION(p_prix >= 0);
    PRECONDITION(util::validerCodeProduit(p_code, p_description, p_prix));
    
    POSTCONDITION(m_description == p_description);
    POSTCONDITION(m_prix == p_prix);
    POSTCONDITION(m_code == p_code);
    
    INVARIANTS();
    
    
}

  /**
   * \brief Destructeur virtuel de la classe Produit
   *        Ne fait rien de particulier, mais est nécessaire pour permettre la
   *        destruction correcte des objets dérivés via un pointeur sur Produit.
   */
Produit::~Produit()
{
    
}
  /**
   * \brief Retourne la description du produit
   * \return Une référence constante vers la description du produit
   */
 const std::string& Produit::reqDescription() const
 {
     return m_description;
     
 }
  /**
   * \brief Retourne le prix du produit
   * \return Le prix du produit
   */
 double Produit::reqPrix() const
 {
     return m_prix;
     
 }
 
  /**
   * \brief Retourne le code du produit
   * \return Une référence constante vers le code du produit
   */
 
  const std::string& Produit::reqCode() const
 {
      return m_code;
      
 }
  
  /**
   * \brief Assigne un nouveau prix au produit
   *
   *        Le prix doit être positif ou nul. En cas de valeur invalide,
   *        une erreur de précondition est générée.
   *
   * \param[in] p_prix le nouveau prix du produit
   *
   * \pre p_prix >= 0
   * \post reqPrix() == p_prix
   */
  
 void Produit::asgPrix(double p_prix){
     PRECONDITION(p_prix >= 0);
     
     m_prix = p_prix;
     
     m_code = util::genererCodeProduit(m_description, m_prix);
     
     POSTCONDITION(m_prix == p_prix);
     POSTCONDITION(util::validerCodeProduit(m_code, m_description, m_prix));
     
     INVARIANTS();
     
 }
  /**
   * \brief Surcharge de l'opérateur d'égalité
   *
   *        Deux produits sont considérés comme égaux si :
   *        - leur description est identique ;
   *        - leur prix est identique ;
   *        - leur code est identique.
   *
   * \param[in] p_produit produit à comparer à l'objet courant
   * \return true si tous les attributs sont égaux, false sinon
   */
 bool Produit::operator==(const Produit& p_produit) const {
    return m_description == p_produit.m_description &&
            m_prix == p_produit.m_prix &&
            m_code == p_produit.m_code;
}
  /**
   * \brief Retourne une représentation textuelle formatée du produit
   *
   * \return Une chaîne de caractères contenant la description formatée du produit
   */
 std::string Produit::reqProduitFormate() const{
     ostringstream os;
     os<< m_description<<endl;
     os<< m_prix<<endl;
     os<< m_code;
     return os.str();
     
 }
  /**
   * \brief Teste l'invariant de la classe Produit
   *
   *        L'invariant de cette classe s'assure que :
   *        - la description n'est pas vide ;
   *        - le prix est positif ou nul ;
   *        - le code est valide selon util::validerCodeProduit.
   */
 void Produit::verifieInvariant() const{
    INVARIANT(!m_description.empty());
    INVARIANT(m_prix >= 0);
    INVARIANT(util::validerCodeProduit(m_code, m_description, m_prix));

 } 
} // namespace commerce
