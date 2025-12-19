/**
 * \file CatalogueTesteur.cpp
 * \brief Implantation des tests unitaires pour la classe Catalogue
 * \author Omar Mahamat
 * \date 18 novembre 2025
 * \version 2.0
 */
#include <gtest/gtest.h>
#include <sstream>
#include "Catalogue.h"
#include "Vetement.h"
#include "Electronique.h"
#include "validationFormat.h"
#include "ContratException.h"
#include "Date.h"
#include "ProduitException.h"

using namespace std;
using namespace commerce;
using namespace util;

/**
 * \brief Test du constructeur Catalogue(const std::string&, const Date&)
 *        Cas valides :
 *          - Constructeur_AvecParametres_objetValide
 *        Cas invalides :
 *          - Constructeur_NomVide_PreconditionException
 */
TEST(CatalogueTest, Constructeur_AvecParametres_objetValide)
{
  std::string nom = "Automne";
  Date date(26, 8, 2025);

  Catalogue c(nom, date);

  ASSERT_EQ(nom, c.reqNom());
  ASSERT_EQ(date, c.reqDateDerniereMiseAJour());
}

TEST(CatalogueTest, Constructeur_NomVide_PreconditionException)
{
  std::string nom = "";
  Date date(1, 1, 2025);

  ASSERT_THROW(Catalogue c(nom, date), PreconditionException);
}

/**
 * \class UnCatalogue
 * \brief Fixture pour la création d’un Catalogue avec quelques produits
 */
class UnCatalogue : public ::testing::Test
{
public:
  UnCatalogue() :
    f_nom("Automne"),
    f_date(26, 8, 2025),
    f_catalogue(f_nom, f_date)
  {
    // On ajoute un Vetement et un Electronique pour avoir un catalogue non vide
    std::string descV = "T-shirt coton";
    double prixV = 19.95;
    std::string codeV = genererCodeProduit(descV, prixV);
    Vetement v(descV, prixV, codeV, "M", "Blanc");
    f_catalogue.ajouterProduit(v);

    std::string descE = "Casque Bluetooth";
    double prixE = 89.99;
    std::string codeE = genererCodeProduit(descE, prixE);
    Electronique e(descE, prixE, codeE, 12, true);
    f_catalogue.ajouterProduit(e);
  }

  std::string f_nom;
  Date f_date;
  Catalogue f_catalogue;
};

/**
 * \brief Test de l'opérateur d'assignation operator=
 *        Cas valides :
 *          - OperateurAssignation_CopieProfonde
 */
TEST_F(UnCatalogue, OperateurAssignation_CopieProfonde)
{

  Catalogue autre("Hiver", Date(1, 12, 2024));

  autre = f_catalogue;

  std::string originalAvant = f_catalogue.reqCatalogueFormate();
  std::string copieAvant = autre.reqCatalogueFormate();

  ASSERT_EQ(originalAvant, copieAvant);

  std::string desc = "Nouvelle veste";
  double prix = 129.90;
  std::string code = genererCodeProduit(desc, prix);
  Vetement v(desc, prix, code, "XL", "Noir");
  f_catalogue.ajouterProduit(v);

  std::string originalApres = f_catalogue.reqCatalogueFormate();
  std::string copieApres = autre.reqCatalogueFormate();

  ASSERT_NE(originalAvant, originalApres);
  ASSERT_EQ(copieAvant, copieApres);
}


/**
 * \brief Test des accesseurs
 *        Cas valides :
 *          - reqNom_retourValide
 *          - reqDateDerniereMiseAJour_retourValide
 */
TEST_F(UnCatalogue, ReqNom_retourValide)
{
  ASSERT_EQ(f_nom, f_catalogue.reqNom());
}

TEST_F(UnCatalogue, ReqDateDerniereMiseAJour_retourValide)
{
  ASSERT_EQ(f_date, f_catalogue.reqDateDerniereMiseAJour());
}

/**
 * \brief Test de la méthode void ajouterProduit(const Produit&)
 *        Cas valides :
 *          - AjouterProduit_ProduitAjoute_catalogueFormateContientProduit
 *        Cas invalides : aucun
 */
TEST_F(UnCatalogue, AjouterProduit_ProduitAjoute_catalogueFormateContientProduit)
{
  std::string desc = "Jean slim";
  double prix = 49.90;
  std::string code = genererCodeProduit(desc, prix);
  Vetement v(desc, prix, code, "L", "Bleu");

  std::string avant = f_catalogue.reqCatalogueFormate();
  f_catalogue.ajouterProduit(v);
  std::string apres = f_catalogue.reqCatalogueFormate();

  ASSERT_TRUE(avant != apres);

  ASSERT_TRUE(apres.find(desc) != std::string::npos);
}

/**
 * \brief Test de la méthode void ajouterProduit(const Produit&)
 *        Cas invalides :
 *          - AjouterProduit_ProduitDejaPresent_ProduitDejaPresentException
 */
TEST_F(UnCatalogue, AjouterProduit_ProduitDejaPresent_ProduitDejaPresentException)
{
  
  std::string descV = "T-shirt coton";
  double prixV = 19.95;
  std::string codeV = genererCodeProduit(descV, prixV);
  Vetement doublon(descV, prixV, codeV, "M", "Blanc");

  ASSERT_THROW(f_catalogue.ajouterProduit(doublon), ProduitDejaPresentException);
}


/**
 * \brief Test de la méthode supprimerProduit(const std::string&)
 *        Cas valides :
 *          - SupprimerProduit_ProduitPresent_ProduitRetire
 */
TEST_F(UnCatalogue, SupprimerProduit_ProduitPresent_ProduitRetire)
{
 
  std::string codeV = genererCodeProduit("T-shirt coton", 19.95);

  std::string avant = f_catalogue.reqCatalogueFormate();
  f_catalogue.supprimerProduit(codeV);
  std::string apres = f_catalogue.reqCatalogueFormate();


  ASSERT_NE(avant, apres);

  ASSERT_EQ(std::string::npos, apres.find("T-shirt coton"));
}

/**
 * \brief Test de la méthode supprimerProduit(const std::string&)
 *        Cas invalides :
 *          - SupprimerProduit_ProduitAbsent_ProduitAbsentException
 */
TEST_F(UnCatalogue, SupprimerProduit_ProduitAbsent_ProduitAbsentException)
{
  std::string codeInexistant = "NNN005N";

  ASSERT_THROW(f_catalogue.supprimerProduit(codeInexistant), ProduitAbsentException);
}



/**
 * \brief Test de la méthode std::string reqCatalogueFormate() const
 *        Cas valides :
 *          - ReqCatalogueFormate_EnteteValide : l’en-tête du catalogue est formaté correctement
 */
TEST_F(UnCatalogue, ReqCatalogueFormate_EnteteValide)
{
  std::ostringstream os;
  os << "Catalogue " << f_nom << std::endl;
  os << "Dernière mise a jour : " << f_date << std::endl;

  std::string resultat = f_catalogue.reqCatalogueFormate();
  std::string enteteAttendu = os.str();

  ASSERT_TRUE(resultat.find(enteteAttendu) == 0);
}

/**
 * \brief Test du constructeur de copie Catalogue(const Catalogue&)
 *        Cas valides :
 *          - ConstructeurCopie_CopieProfonde : copie indépendante
 */
TEST_F(UnCatalogue, ConstructeurCopie_CopieProfonde)
{
  Catalogue copie(f_catalogue);

  std::string originalAvant = f_catalogue.reqCatalogueFormate();
  std::string copieAvant = copie.reqCatalogueFormate();

  ASSERT_EQ(originalAvant, copieAvant);

  std::string desc = "Nouvelle chemise";
  double prix = 59.90;
  std::string code = genererCodeProduit(desc, prix);
  Vetement v(desc, prix, code, "S", "Rouge");
  f_catalogue.ajouterProduit(v);

  std::string originalApres = f_catalogue.reqCatalogueFormate();
  std::string copieApres = copie.reqCatalogueFormate();


  ASSERT_NE(originalAvant, originalApres);
  ASSERT_EQ(copieAvant, copieApres);
}