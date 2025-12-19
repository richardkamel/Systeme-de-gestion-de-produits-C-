

/** 
 * \file  Electronique.h
 * \author Omar Mahamat
 * \date 8 novembre 2025
 * \brief Interface de la classe Electronique
 */

#ifndef ELECTRONIQUE_H
#define ELECTRONIQUE_H


#include <string>
#include <memory>
#include "Produit.h"

namespace commerce {
    
 /**
 * \class Electronique
 * \brief Classe représentant un produit électronique.
 *
 * La classe Electronique dérive de Produit et ajoute des informations propres aux 
 * appareils électroniques. En plus des attributs génériques d’un produit 
 * (description, prix, code), un produit électronique possède une durée de garantie 
 * et peut être indiqué comme reconditionné ou non.
 *
 * Cette classe illustre l’usage du polymorphisme dans la hiérarchie de produits :
 * elle redéfinit notamment la méthode clone() pour permettre la copie dynamique 
 * d’un produit électronique, et adapte la méthode reqProduitFormate() pour inclure 
 * ses informations spécifiques.
 *
 * La classe Electronique permet :
 * - d’obtenir la durée de garantie exprimée en mois ;
 * - de savoir si le produit est reconditionné ou neuf ;
 * - de comparer deux produits électroniques entre eux ;
 * - de fournir une version textuelle détaillée du produit incluant ses attributs propres ;
 * - de créer une copie polymorphique du produit électronique via clone().
 *
 * Les invariants de cette classe garantissent que :
 * - la durée de garantie est toujours positive ou nulle ;
 * - l’information sur l’état reconditionné est cohérente ;
 * - les invariants de la classe de base Produit sont aussi respectés.
 */
   
    
class Electronique : public Produit {
public:
    Electronique(const std::string& p_description, double p_prix, const std::string& p_code, int p_garantieMois, bool p_estReconditionne);
    int reqGarantieMois() const;
    bool reqEstReconditionne() const;
    bool operator==(const Electronique& p_electronique) const;
    std::unique_ptr<Produit> clone() const override;
    std::string reqProduitFormate() const override;
    
private:
    int m_garantieMois;
    bool m_estReconditionne;
    void verifieInvariant() const;
   
    
 
};}

#endif /* ELECTRONIQUE_H */

