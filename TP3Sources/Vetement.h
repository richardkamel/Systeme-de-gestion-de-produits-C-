
/** 
 * \file Vetement.h
 * \author Omar Mahamat
 * \date 13 novembre 2025
 * \brief Interface de la classe Vetement 
 */

#ifndef VETEMENT_H
#define VETEMENT_H

#include "Produit.h"
#include <string>

namespace commerce{
    
/**
 * \class Vetement
 * \brief Classe représentant un produit de type vêtement.
 *
 * La classe Vetement dérive de Produit et ajoute les caractéristiques propres à un
 * article textile, comme la taille et la couleur. Elle représente donc tout type
 * de vêtement pouvant être vendu dans un catalogue : un pantalon, une chemise,
 * un manteau, etc.
 *
 * En s’appuyant sur les fonctionnalités de la classe Produit, Vetement enrichit
 * l’information disponible pour un produit en y ajoutant des attributs typiques
 * du domaine vestimentaire. Cela permet de manipuler uniformément différents types
 * de produits tout en conservant leurs particularités.
 *
 * La classe Vetement permet :
 * - d’obtenir la taille du vêtement (ex. S, M, XL, etc.) ;
 * - d’obtenir sa couleur ;
 * - de comparer deux vêtements entre eux en tenant compte de leurs attributs spécifiques ;
 * - d’obtenir une version textuelle détaillée du vêtement incluant taille et couleur.
 *
 * Les invariants de la classe garantissent que :
 * - la taille du vêtement n’est jamais vide ;
 * - la couleur n’est jamais vide ;
 * - les invariants de la classe mère Produit sont également respectés.
 */
   

    
class Vetement : public Produit 
{
public:
    Vetement(const std::string& p_description, double p_prix, const std::string& p_code, const std::string& p_taille, const std::string& p_couleur);
    const std::string& reqTaille() const;
    const std::string& reqCouleur() const;
    bool operator==(const Vetement& p_vetement) const;
    std::string reqProduitFormate() const override;
    std::unique_ptr<Produit> clone() const override;
private:
    std::string m_taille;
    std::string m_couleur;
    void verifieInvariant() const;

};
} // namespace commerce

#endif /* VETEMENT_H */

