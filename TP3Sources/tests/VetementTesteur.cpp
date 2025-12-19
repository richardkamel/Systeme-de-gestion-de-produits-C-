/**
 * \file VetementTesteur.cpp
 * \brief Implantation des tests unitaires pour la classe Vetement
 * \author Omar Mahamat
 * \date 15 novembre 2025
 * \version 1.0
 */

#include <gtest/gtest.h>
#include <sstream>
#include "Vetement.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace commerce;
using namespace util;

/**
 * \brief Test du constructeur Vetement(const std::string&, double, const std::string&, const std::string&, const std::string&)
 *        Cas valides :
 *          - Constructeur_AvecParametres_objetValide
 *        Cas invalides :
 *          - Constructeur_TailleInvalide_PreconditionException
 */
TEST(VetementTest, Constructeur_AvecParametres_objetValide)
{
  std::string description = "T-shirt coton";
  double prix = 19.95;
  std::string code = genererCodeProduit(description, prix);
  std::string taille = "M";
  std::string couleur = "Blanc";

  Vetement v(description, prix, code, taille, couleur);

  ASSERT_EQ(description, v.reqDescription());
  ASSERT_DOUBLE_EQ(prix, v.reqPrix());
  ASSERT_EQ(code, v.reqCode());
  ASSERT_EQ(taille, v.reqTaille());
  ASSERT_EQ(couleur, v.reqCouleur());
}

TEST(VetementTest, Constructeur_TailleInvalide_PreconditionException)
{
  std::string description = "Pantalon";
  double prix = 39.99;
  std::string code = genererCodeProduit(description, prix);
  std::string taille = "XXXL"; // taille non valide
  std::string couleur = "Noir";

  ASSERT_THROW(Vetement v(description, prix, code, taille, couleur),
               PreconditionException);
}

/**
 * \class UnVetement
 * \brief Fixture pour la création d’un Vetement valide
 */
class UnVetement : public ::testing::Test
{
public:
  UnVetement() :
    f_description("Jean slim"),
    f_prix(49.90),
    f_code(genererCodeProduit(f_description, f_prix)),
    f_taille("L"),
    f_couleur("Bleu"),
    f_vetement(f_description, f_prix, f_code, f_taille, f_couleur)
  { }

  std::string f_description;
  double f_prix;
  std::string f_code;
  std::string f_taille;
  std::string f_couleur;
  Vetement f_vetement;
};

/**
 * \brief Test des accesseurs spécifiques
 *        Cas valides :
 *          - reqTaille_retourValide
 *          - reqCouleur_retourValide
 */
TEST_F(UnVetement, ReqTaille_retourValide)
{
  ASSERT_EQ(f_taille, f_vetement.reqTaille());
}

TEST_F(UnVetement, ReqCouleur_retourValide)
{
  ASSERT_EQ(f_couleur, f_vetement.reqCouleur());
}

/**
 * \brief Test de l’opérateur bool operator==(const Vetement&) const
 *        Cas valides :
 *          - VetementsIdentiques_retourneTrue
 *          - VetementsDifferents_retourneFalse
 */
TEST_F(UnVetement, OperateurEgalite_VetementsIdentiques_retourneTrue)
{
  Vetement autre(f_description, f_prix, f_code, f_taille, f_couleur);
  ASSERT_TRUE(f_vetement == autre);
}

TEST_F(UnVetement, OperateurEgalite_VetementsDifferents_retourneFalse)
{
  Vetement autre(f_description, f_prix, f_code, "M", f_couleur);
  ASSERT_FALSE(f_vetement == autre);
}

/**
 * \brief Test de la méthode std::string reqProduitFormate() const
 *        Cas valides :
 *          - reqProduitFormate_formatConforme
 */
TEST_F(UnVetement, ReqProduitFormate_formatConforme)
{
  std::ostringstream os;
  os << "----------------------------" << std::endl;
  os << "Produit Vetement" << std::endl;
  os << f_vetement.Produit::reqProduitFormate() << std::endl;
  os << "Taille : " << f_taille << std::endl;
  os << "Couleur : " << f_couleur << std::endl;

  ASSERT_EQ(os.str(), f_vetement.reqProduitFormate());
}

/**
 * \brief Test de la méthode std::unique_ptr<Produit> clone() const
 *        Cas valides :
 *          - Clone_CopieProfonde : copie identique et indépendante
 */
TEST_F(UnVetement, Clone_CopieProfonde)
{
  std::unique_ptr<Produit> copie = f_vetement.clone();

  ASSERT_EQ(f_vetement.reqDescription(), copie->reqDescription());
  ASSERT_DOUBLE_EQ(f_vetement.reqPrix(), copie->reqPrix());
  ASSERT_EQ(f_vetement.reqCode(), copie->reqCode());

  f_vetement.asgPrix(59.00);

  ASSERT_DOUBLE_EQ(59.00, f_vetement.reqPrix());
  ASSERT_NE(f_vetement.reqPrix(), copie->reqPrix());
  ASSERT_NE(f_vetement.reqCode(), copie->reqCode());
}