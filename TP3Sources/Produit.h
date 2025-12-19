/** 
 * \file Produit.h
 * \author Omar Mahamat
 * \date 8 novembre 2025
 * \brief Interface de la classe Produit
 */


#include <string>
#include <memory>
#include "ContratException.h"
#include "validationFormat.h"

#ifndef PRODUIT_H
#define PRODUIT_H

/**
 * \class Produit
 * \brief Classe abstraite qui représente l’idée générale d’un produit à vendre.
 *
 * La classe Produit regroupe tous les éléments essentiels qu’on retrouve chez n’importe
 * quel produit : une description, un prix et un code produit. Elle assure aussi que ces
 * informations demeurent toujours valides grâce à différentes règles de vérification.
 *
 * Cette classe joue le rôle de fondation pour toutes les catégories de produits plus
 * spécifiques (comme un produit électronique ou un vêtement). Elle impose donc à ses
 * classes dérivées de réimplémenter certaines méthodes, notamment celle qui permet
 * de cloner correctement un produit selon son type concret.
 *
 * Concrètement, la classe Produit permet :
 * - d’accéder et de gérer les informations de base d’un produit (description, prix, code) ;
 * - de comparer deux produits entre eux ;
 * - de générer une version textuelle bien formatée du produit ;
 * - de créer des copies polymorphiques grâce à une méthode de clonage virtuelle pure.
 *
 * Les invariants de cette classe garantissent que :
 * - la description n’est jamais vide ;
 * - le prix est toujours positif ou égal à zéro ;
 * - le code produit est conforme au format attendu (défini dans validationFormat.h).
 */

namespace commerce{
    
    
class Produit{
public:
    Produit(const std::string& p_description, double p_prix,const std::string& p_code);
    virtual ~Produit();
    const std::string& reqDescription() const;
    double reqPrix() const;
    const std::string& reqCode() const;
    
    void asgPrix(double p_prix);
    bool operator==(const Produit& p_produit) const;
    virtual std::string reqProduitFormate() const;
    virtual std::unique_ptr<Produit> clone() const = 0;
private:
    std::string m_description;
    double m_prix;
    std::string m_code;
    void verifieInvariant() const; 
    
};
} //namespace commerce

#endif /* PRODUIT_H */

