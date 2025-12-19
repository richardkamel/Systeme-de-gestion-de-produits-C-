
/** 
 * \file Catalogue.h
 * \author Omar Mahamat
 * \date 8 novembre 2025
 * \brief Interface de la classe Catalogue 
 */

#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <string>
#include <vector>
#include "Produit.h"
#include <memory>
#include "Date.h"
namespace commerce{
    
/**
 * \class Catalogue
 * \brief Classe représentant un catalogue de produits.
 *
 * La classe Catalogue modélise une collection organisée de produits. Un catalogue possède 
 * un nom ainsi qu’une date de dernière mise à jour, ce qui permet de garder une trace claire 
 * de sa validité ou de sa fraîcheur.
 *
 * Un catalogue peut contenir plusieurs produits, chacun stocké sous forme de copie polymorphique.
 * Cela permet d’y intégrer n’importe quel type de produit dérivé de la classe Produit 
 * (électronique, vêtement, etc.), sans se préoccuper de leur type concret.
 *
 * La classe Catalogue permet :
 * - de consulter son nom et sa date de dernière mise à jour ;
 * - d’ajouter de nouveaux produits au catalogue, tout en conservant leur comportement polymorphique ;
 * - de produire une représentation textuelle bien formatée de son contenu ;
 * - de dupliquer un catalogue grâce au constructeur de copie (copie profonde des produits).
 * 
 * Les invariants de cette classe garantissent :
 * - le nom du catalogue n’est jamais vide ;
 * - la date de dernière mise à jour est toujours valide ;
 * - la liste des produits ne contient que des pointeurs valides et non nuls.
 */
    
class Catalogue {
public:
    Catalogue(const std::string& p_nom, const util::Date& p_dateDerniereMiseAJour);
    Catalogue(const Catalogue& p_catalogue);
    
    Catalogue& operator=(const Catalogue& p_catalogue);
    const std::string& reqNom() const;
    const util::Date& reqDateDerniereMiseAJour() const;
    void asgDerniereMiseAJour(const util::Date& p_date);
    void ajouterProduit (const Produit& p_nouveauProduit);
    void supprimerProduit (const std::string& p_codeProduit);
    
    std::string reqCatalogueFormate() const;
private:
    std::string m_nom;
    util::Date m_dateDerniereMiseAJour;
    std::vector<std::unique_ptr<Produit>> m_produits;
    
    bool produitEstDejaPresent(const std::string& p_codeProduit) const;
    void verifieInvariant() const;
    

};
} //namespace commerce

#endif /* CATALOGUE_H */

