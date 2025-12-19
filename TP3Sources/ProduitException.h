/**
 * \file ProduitException.h
 * \author Omar Mahamat
 * \date 8 decembre 2025
 * \brief Hiérarchie d’exceptions spécifiques aux produits du catalogue.
 *
 * Ce fichier déclare une hiérarchie d’exceptions dérivant de std::runtime_error,
 * utilisée pour signaler les erreurs liées aux produits dans le catalogue :
 * - erreur générique sur un produit (ProduitException) ;
 * - produit déjà présent dans le catalogue (ProduitDejaPresentException) ;
 * - produit absent du catalogue lors d’une suppression (ProduitAbsentException).
 *
 * Cette hiérarchie est utilisée par la classe Catalogue pour lever des exceptions
 * plus significatives que les exceptions standard.
 */

#ifndef PRODUITEXCEPTION_H
#define PRODUITEXCEPTION_H

#include <stdexcept>
#include <string>

namespace commerce{
    
 /**
 * \class ProduitException
 * \brief Exception de base pour les erreurs liées aux produits.
 *
 * Cette classe dérive de std::runtime_error et sert de classe de base pour
 * toutes les exceptions spécifiques aux produits. Elle encapsule un message
 * décrivant la raison de l’erreur.
 */   
  
class ProduitException : public std::runtime_error
{
    
    public:
  /**
   * \brief Constructeur avec message.
   * \param[in] p_raison message décrivant la cause de l’exception.
   */
        ProduitException(const std::string& p_raison) 
        : std::runtime_error(p_raison) {};
   
};
/**
 * \class ProduitAbsentException
 * \brief Exception lancée lorsqu’on tente de supprimer un produit absent.
 *
 * Cette exception est levée par la classe Catalogue lorsqu’on tente de
 * supprimer un produit dont le code ne se trouve pas dans le catalogue.
 */
class ProduitDejaPresentException : public ProduitException
{
    public:
  /**
   * \brief Constructeur avec message.
   * \param[in] p_raison message décrivant la cause de l’exception.
   */
            ProduitDejaPresentException(const std::string& p_raison)
            :ProduitException(p_raison) {};

};
/**
 * \class ProduitAbsentException
 * \brief Exception lancée lorsqu’on tente de supprimer un produit absent.
 *
 * Cette exception est levée par la classe Catalogue lorsqu’on tente de
 * supprimer un produit dont le code ne se trouve pas dans le catalogue.
 */
class ProduitAbsentException : public ProduitException
{
    public:
 /**
   * \brief Constructeur avec message.
   * \param[in] p_raison message décrivant la cause de l’exception.
   */
            ProduitAbsentException(const std::string& p_raison)
            :ProduitException(p_raison) {};

};} // namespace commerce
#endif /* PRODUITEXCEPTION_H */

