/**
 * \file ProduitTesteur.cpp
 * \brief Tests unitaires de la classe Produit (via une classe concrète de test)
 * \author Omar Mahamat
 * \date 15 novembre 2025
 * \version 2.0
 */

#include <gtest/gtest.h>
#include <sstream>
#include "Produit.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace commerce;
using namespace util;

/**
 * \class ProduitDeTest
 * \brief Classe concrète de test dérivée de Produit (Produit est abstraite).
 */
class ProduitDeTest : public Produit
{
public:
  ProduitDeTest(const std::string& p_description, double p_prix, const std::string& p_code) : Produit(p_description, p_prix, p_code) 
  { 
  }

  virtual std::string reqProduitFormate() const override
  {
    return Produit::reqProduitFormate();
  }

  virtual std::unique_ptr<Produit> clone() const override
  {
    return std::unique_ptr<Produit>(new ProduitDeTest(*this));
  }
};

/**
 * \brief Test du constructeur Produit(const std::string&, double, const std::string&)
 *        Cas valides :
 *          - Constructeur_AvecParametres : produit bien initialisé avec valeurs cohérentes
 *        Cas invalides :
 *          - Constructeur_DescriptionVide_PreconditionException
 *          - Constructeur_PrixNegatif_PreconditionException
 *          - Constructeur_CodeInvalide_PreconditionException
 */
TEST(ProduitTest, Constructeur_AvecParametres_objetValide)
{
  std::string description = "Jean Slim";
  double prix = 49.99;
  std::string code = genererCodeProduit(description, prix);

  ProduitDeTest produit(description, prix, code);

  ASSERT_EQ(description, produit.reqDescription());
  ASSERT_DOUBLE_EQ(prix, produit.reqPrix());
  ASSERT_EQ(code, produit.reqCode());
}

TEST(ProduitTest, Constructeur_DescriptionVide_PreconditionException)
{
  std::string description = "";
  double prix = 10.0;
  std::string code = genererCodeProduit("Test", prix);

  ASSERT_THROW(ProduitDeTest produit(description, prix, code), PreconditionException);
}

TEST(ProduitTest, Constructeur_PrixNegatif_PreconditionException)
{
  std::string description = "Article";
  double prix = -5.0;
  std::string code = genererCodeProduit(description, 10.0);

  ASSERT_THROW(ProduitDeTest produit(description, prix, code), PreconditionException);
}

TEST(ProduitTest, Constructeur_CodeInvalide_PreconditionException)
{
  std::string description = "Pantalon";
  double prix = 39.99;
  std::string code = genererCodeProduit(description, prix);
  code += "X";

  ASSERT_THROW(ProduitDeTest produit(description, prix, code), PreconditionException);
}

/**
 * \class UnProduit
 * \brief Fixture pour la création d’un produit valide
 */
class UnProduit : public ::testing::Test
{
public:
  UnProduit() : f_description("T-shirt coton"), f_prix(19.95), f_code(genererCodeProduit(f_description, f_prix)), f_produit(f_description, f_prix, f_code)
  {
      
  }

  std::string f_description;
  double f_prix;
  std::string f_code;
  ProduitDeTest f_produit;
};

/**
 * \brief Test des accesseurs (reqDescription(), reqPrix(), reqCode())
 *        Cas valides :
 *          - reqDescription, reqPrix, reqCode : vérification des valeurs retournées
 *        Cas invalides : aucun
 */
TEST_F(UnProduit, ReqDescription_retourValide)
{
  ASSERT_EQ(f_description, f_produit.reqDescription());
}

TEST_F(UnProduit, ReqPrix_retourValide)
{
  ASSERT_DOUBLE_EQ(f_prix, f_produit.reqPrix());
}

TEST_F(UnProduit, ReqCode_retourValide)
{
  ASSERT_EQ(f_code, f_produit.reqCode());
}

/**
 * \brief Test de la méthode void asgPrix(double)
 *        Cas valides :
 *          - asgPrix_PrixValide_modifiePrixEtCode
 *        Cas invalides :
 *          - asgPrix_PrixNegatif_PreconditionException
 */
TEST_F(UnProduit, AsgPrix_PrixValide_modifiePrixEtCode)
{
  double nouveauPrix = 24.50;
  std::string ancienCode = f_produit.reqCode();

  f_produit.asgPrix(nouveauPrix);

  ASSERT_DOUBLE_EQ(nouveauPrix, f_produit.reqPrix());
  std::string codeAttendu = genererCodeProduit(f_description, nouveauPrix);
  ASSERT_EQ(codeAttendu, f_produit.reqCode());
  ASSERT_NE(ancienCode, f_produit.reqCode());
}

TEST_F(UnProduit, AsgPrix_PrixNegatif_PreconditionException)
{
  ASSERT_THROW(f_produit.asgPrix(-1.0), PreconditionException);
}

/**
 * \brief Test de l’opérateur bool operator==(const Produit&) const
 *        Cas valides :
 *          - ProduitsIdentiques_retourneTrue
 *          - ProduitsDifferents_retourneFalse
 *        Cas invalides : aucun
 */
TEST_F(UnProduit, OperateurEgalite_ProduitsIdentiques_retourneTrue)
{
  ProduitDeTest autre(f_description, f_prix, f_code);
  ASSERT_TRUE(f_produit == autre);
}

TEST_F(UnProduit, OperateurEgalite_DescriptionsDifferentes_retourneFalse)
{
    std::string autreDescription = "Autre produit";
    std::string autreCode = genererCodeProduit(autreDescription, f_prix);

    ProduitDeTest autre(autreDescription, f_prix, autreCode);

    ASSERT_FALSE(f_produit == autre);
}

/**
 * \brief Test de la méthode std::string reqProduitFormate() const
 *        Cas valides :
 *          - reqProduitFormate_formatConforme : chaîne formatée comme attendu
 *        Cas invalides : aucun
 */
TEST_F(UnProduit, ReqProduitFormate_formatConforme)
{
  std::ostringstream os;
  os << f_description << std::endl;
  os << f_prix << std::endl;
  os << f_code;

  ASSERT_EQ(os.str(), f_produit.reqProduitFormate());
}

/**
 * \brief Test de la méthode std::unique_ptr<Produit> clone() const
 *        Cas valides :
 *          - Clone_CopieProfonde : copie identique mais indépendante
 *        Cas invalides : aucun
 */
TEST_F(UnProduit, Clone_CopieProfonde)
{
  std::unique_ptr<Produit> copie = f_produit.clone();

  ASSERT_EQ(f_produit.reqDescription(), copie->reqDescription());
  ASSERT_DOUBLE_EQ(f_produit.reqPrix(), copie->reqPrix());
  ASSERT_EQ(f_produit.reqCode(), copie->reqCode());

  double nouveauPrix = 35.0;
  f_produit.asgPrix(nouveauPrix);

  ASSERT_DOUBLE_EQ(nouveauPrix, f_produit.reqPrix());
  ASSERT_NE(f_produit.reqPrix(), copie->reqPrix());
  ASSERT_NE(f_produit.reqCode(), copie->reqCode());
}
