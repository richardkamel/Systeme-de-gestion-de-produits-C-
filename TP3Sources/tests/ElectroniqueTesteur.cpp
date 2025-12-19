/**
 * \file ElectroniqueTesteur.cpp
 * \brief Tests unitaires de la classe Electronique
 * \author Omar Mahamat
 * \date 15 novembre 2025
 * \version 1.0
 */

#include <gtest/gtest.h>
#include <sstream>
#include "Electronique.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace commerce;
using namespace util;

/**
 * \brief Test du constructeur Electronique(const std::string&, double, const std::string&, int, bool)
 *        Cas valides :
 *          - Constructeur_AvecParametres_objetValide
 *        Cas invalides :
 *          - Constructeur_GarantieNegative_PreconditionException
 */
TEST(ElectroniqueTest, Constructeur_AvecParametres_objetValide)
{
  std::string description = "Casque Bluetooth";
  double prix = 89.99;
  std::string code = genererCodeProduit(description, prix);
  int garantie = 12;
  bool reconditionne = true;

  Electronique e(description, prix, code, garantie, reconditionne);

  ASSERT_EQ(description, e.reqDescription());
  ASSERT_DOUBLE_EQ(prix, e.reqPrix());
  ASSERT_EQ(code, e.reqCode());
  ASSERT_EQ(garantie, e.reqGarantieMois());
  ASSERT_TRUE(e.reqEstReconditionne());
}

TEST(ElectroniqueTest, Constructeur_GarantieNegative_PreconditionException)
{
  std::string description = "Ordinateur portable";
  double prix = 999.99;
  std::string code = genererCodeProduit(description, prix);
  int garantie = -3;
  bool reconditionne = false;

  ASSERT_THROW(Electronique e(description, prix, code, garantie, reconditionne),
               PreconditionException);
}

/**
 * \class UnElectronique
 * \brief Fixture pour la création d’un produit Electronique valide
 */
class UnElectronique : public ::testing::Test
{
public:
  UnElectronique() :
    f_description("Écran 27 pouces"),
    f_prix(249.99),
    f_code(genererCodeProduit(f_description, f_prix)),
    f_electronique(f_description, f_prix, f_code, 24, false)
  { 
        
  }

  std::string f_description;
  double f_prix;
  std::string f_code;
  Electronique f_electronique;
};

/**
 * \brief Test des accesseurs spécifiques
 *        Cas valides :
 *          - reqGarantieMois_retourValide
 *          - reqEstReconditionne_retourValide
 */
TEST_F(UnElectronique, ReqGarantieMois_retourValide)
{
  ASSERT_EQ(24, f_electronique.reqGarantieMois());
}

TEST_F(UnElectronique, ReqEstReconditionne_retourValide)
{
  ASSERT_FALSE(f_electronique.reqEstReconditionne());
}

/**
 * \brief Test de l’opérateur bool operator==(const Electronique&) const
 *        Cas valides :
 *          - ElectroniquesIdentiques_retourneTrue
 *          - ElectroniquesDifferents_retourneFalse
 */
TEST_F(UnElectronique, OperateurEgalite_ElectroniquesIdentiques_retourneTrue)
{
  Electronique autre(f_description, f_prix, f_code, 24, false);
  ASSERT_TRUE(f_electronique == autre);
}

TEST_F(UnElectronique, OperateurEgalite_ElectroniquesDifferents_retourneFalse)
{
  Electronique autre(f_description, f_prix, f_code, 12, false);
  ASSERT_FALSE(f_electronique == autre);
}

/**
 * \brief Test de la méthode std::string reqProduitFormate() const
 *        Cas valides :
 *          - reqProduitFormate_formatConforme
 */
TEST_F(UnElectronique, ReqProduitFormate_formatConforme)
{
  std::ostringstream os;
  os << "----------------------------" << std::endl;
  os << "Produit Electronique" << std::endl;
  os << f_electronique.Produit::reqProduitFormate() << std::endl;
  os << "Garantie : " << f_electronique.reqGarantieMois() << " mois" << std::endl;
  os << "Reconditionné : " << (f_electronique.reqEstReconditionne() ? "Oui" : "Non") << std::endl;

  ASSERT_EQ(os.str(), f_electronique.reqProduitFormate());
}

/**
 * \brief Test de la méthode std::unique_ptr<Produit> clone() const
 *        Cas valides :
 *          - Clone_CopieProfonde : copie identique et indépendante
 */
TEST_F(UnElectronique, Clone_CopieProfonde)
{
  std::unique_ptr<Produit> copie = f_electronique.clone();

  ASSERT_EQ(f_electronique.reqDescription(), copie->reqDescription());
  ASSERT_DOUBLE_EQ(f_electronique.reqPrix(), copie->reqPrix());
  ASSERT_EQ(f_electronique.reqCode(), copie->reqCode());


  f_electronique.asgPrix(199.90);

  ASSERT_DOUBLE_EQ(199.90, f_electronique.reqPrix());
  ASSERT_NE(f_electronique.reqPrix(), copie->reqPrix());
  ASSERT_NE(f_electronique.reqCode(), copie->reqCode());
}
