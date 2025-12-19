/**
 * \file gestionCatalogue.cpp
 * \brief Programme principal minimaliste pour la gestion d'un catalogue de produits.
 * \author Omar Mahamat
 * \date 21 novembre 2025
 *
 * Ce programme :
 *  - charge un catalogue à partir d'un fichier texte;
 *  - affiche le catalogue initial;
 *  - demande à l'usager de saisir un Vetement et un Electronique valides;
 *  - ajoute ces produits au catalogue;
 *  - réaffiche le catalogue final.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <cctype>

#include "Catalogue.h"
#include "Vetement.h"
#include "Electronique.h"
#include "Date.h"
#include "validationFormat.h"
#include "ProduitException.h"


using namespace std;
using namespace commerce;
using namespace util;

/**
 * \brief Charge un catalogue à partir d'un fichier texte.
 *
 * Format attendu du fichier catalogue_produits_valide.txt :
 *  - Ligne 1 : nom du catalogue (ex.: "mon catalogue")
 *  - Ligne 2 : trois entiers "jour mois annee" (ex.: "21 8 2025")
 *  - Puis, une ligne par produit, au format CSV :
 *      Electronique,Description,prix,code,garantie,enRecond
 *      Vetement,Description,prix,code,taille,couleur
 *
 * Exemple :
 *  Electronique,Smartphone Galaxy,499.9,PRD-SMAR-60,24,0
 *  Vetement,T-shirt coton,19.95,PRD-TSHI-70,M,Blanc
 *
 * \param[in] p_nomFichier nom du fichier catalogue à charger
 * \return Un objet Catalogue initialisé avec les produits lus
 */
Catalogue chargerCatalogueDepuisFichier(const std::string& p_nomFichier)
{
  ifstream fichier(p_nomFichier.c_str());

  if (!fichier)
    {
      cerr << "Erreur : impossible d'ouvrir le fichier " << p_nomFichier << endl;
      exit(1);
    }

  // Lecture du nom du catalogue
  string nomCatalogue;
  std::getline(fichier, nomCatalogue);

  // Lecture de la date (jour mois annee)
  int jour = 1;
  int mois = 1;
  int annee = 2000;
  fichier >> jour >> mois >> annee;
  fichier.ignore(numeric_limits<streamsize>::max(), '\n');

  Date dateCatalogue(jour, mois, annee);
  Catalogue catalogue(nomCatalogue, dateCatalogue);

  // Lecture des produits
  string ligne;
  while (std::getline(fichier, ligne))
    {
      if (ligne.empty())
        {
          continue;
        }

      stringstream ss(ligne);
      string type;
      string description;
      string prixStr;
      string code;
      string champ5;
      string champ6;

      std::getline(ss, type, ',');
      std::getline(ss, description, ',');
      std::getline(ss, prixStr, ',');
      std::getline(ss, code, ',');

      double prix = stod(prixStr);

      if (type == "Electronique")
        {
          std::getline(ss, champ5, ',');  // garantie
          std::getline(ss, champ6, ',');  // reconditionné (0/1)

          int garantie = stoi(champ5);
          bool reconditionne = (champ6 == "1");

          Electronique e(description, prix, code, garantie, reconditionne);
          catalogue.ajouterProduit(e);
        }
      else if (type == "Vetement")
        {
          std::getline(ss, champ5, ',');  // taille
          std::getline(ss, champ6, ',');  // couleur

          Vetement v(description, prix, code, champ5, champ6);
          catalogue.ajouterProduit(v);
        }
      else
        {
          // Type de produit inconnu : on ignore la ligne
        }
    }

  return catalogue;
}

/**
 * \brief Valide si une taille de vêtement est parmi les valeurs admises.
 *
 * Tailles valides : XS, S, M, L, XL, XXL (en majuscules).
 *
 * \param[in] p_taille taille saisie
 * \return true si la taille est valide, false sinon
 */
bool tailleValide(const std::string& p_taille)
{
  return p_taille == "XS" || p_taille == "S" || p_taille == "M" ||
         p_taille == "L"  || p_taille == "XL" || p_taille == "XXL";
}

/**
 * \brief Saisie d'un nouveau Vetement auprès de l'usager.
 *
 * L'usager doit saisir :
 *  - une description non vide ;
 *  - un prix numérique >= 0 ;
 *  - un code produit valide (util::validerCodeProduit) ;
 *  - une taille parmi {XS, S, M, L, XL, XXL} ;
 *  - une couleur non vide.
 *
 * Les messages d'erreur et les invites sont inspirés de l'exemple d'exécution
 * fourni pour le TP2.
 *
 * \return Un objet Vetement construit avec des valeurs valides.
 */
Vetement saisirVetement()
{
  cout << "Enregistrement d'un nouveau produit Vetement :" << endl;

  char buffer[256];
  std::string description;
  std::string prixStr;
  std::string code;
  std::string taille;
  std::string couleur;
  double prix = 0.0;

  // Description : non vide
  while (true)
    {
      cout << "Description :" << endl;
      cin.getline(buffer, 256);
      description = buffer;

      if (!description.empty())
        {
          break;
        }
      cout << "La description ne doit pas être vide, recommencez" << endl;
    }

  // Prix : nombre >= 0
  while (true)
    {
      cout << "Prix : " << endl;
      cin.getline(buffer, 256);
      prixStr = buffer;

      if (prixStr.empty())
        {
          cout << "Le prix doit être un nombre positif ou nul, recommencez" << endl;
          continue;
        }

      bool formatValide = true;
      bool pointDejaVu = false;
      for (size_t i = 0; i < prixStr.size() && formatValide; ++i)
        {
          char c = prixStr[i];
          if (isdigit(static_cast<unsigned char>(c)))
            {
              continue;
            }
          if (c == '.' && !pointDejaVu)
            {
              pointDejaVu = true;
              continue;
            }
          formatValide = false;
        }

      if (!formatValide)
        {
          cout << "Le prix doit être un nombre positif ou nul, recommencez" << endl;
          continue;
        }

      prix = stod(prixStr);
      if (prix < 0)
        {
          cout << "Le prix doit être un nombre positif ou nul, recommencez" << endl;
          continue;
        }
      break;
    }


  while (true)
    {
      cout << "Code :" << endl;
      cin.getline(buffer, 256);
      code = buffer;

      if (util::validerCodeProduit(code, description, prix))
        {
          break;
        }
      cout << "Le code n'est pas valide, recommencez" << endl;
    }

  // Taille : XS, S, M, L, XL, XXL
  while (true)
    {
      cout << "taille :" << endl;
      cin.getline(buffer, 256);
      taille = buffer;

      for (size_t i = 0; i < taille.size(); ++i)
        {
          taille[i] = static_cast<char>(toupper(static_cast<unsigned char>(taille[i])));
        }

      if (tailleValide(taille))
        {
          break;
        }
      cout << "La taille n'est pas valide, recommencez" << endl;
    }

  // Couleur : non vide
  while (true)
    {
      cout << "Couleur : " << endl;
      cin.getline(buffer, 256);
      couleur = buffer;

      if (!couleur.empty())
        {
          break;
        }
      cout << "La couleur ne doit pas être vide, recommencez" << endl;
    }

  Vetement v(description, prix, code, taille, couleur);
  return v;
}

/**
 * \brief Saisie d'un nouveau Electronique auprès de l'usager.
 *
 * L'usager doit saisir :
 *  - une description non vide ;
 *  - un prix numérique >= 0 ;
 *  - un code produit valide ;
 *  - une garantie en mois (entier >= 0) ;
 *  - un indicateur de reconditionnement (1 pour oui, 0 pour non).
 *
 * \return Un objet Electronique construit avec des valeurs valides.
 */
Electronique saisirElectronique()
{
  cout << "Enregistrement d'un nouveau produit Electronique" << endl;

  char buffer[256];
  std::string description;
  std::string prixStr;
  std::string code;
  std::string garantieStr;
  std::string recondStr;
  double prix = 0.0;
  int garantie = 0;
  bool estReconditionne = false;


  while (true)
    {
      cout << "Description :" << endl;
      cin.getline(buffer, 256);
      description = buffer;

      if (!description.empty())
        {
          break;
        }
      cout << "La description ne doit pas être vide, recommencez" << endl;
    }


  while (true)
    {
      cout << "Prix : " << endl;
      cin.getline(buffer, 256);
      prixStr = buffer;

      if (prixStr.empty())
        {
          cout << "Le prix doit être un nombre positif ou nul, recommencez" << endl;
          continue;
        }

      bool formatValide = true;
      bool pointDejaVu = false;
      for (size_t i = 0; i < prixStr.size() && formatValide; ++i)
        {
          char c = prixStr[i];
          if (isdigit(static_cast<unsigned char>(c)))
            {
              continue;
            }
          if (c == '.' && !pointDejaVu)
            {
              pointDejaVu = true;
              continue;
            }
          formatValide = false;
        }

      if (!formatValide)
        {
          cout << "Le prix doit être un nombre positif ou nul, recommencez" << endl;
          continue;
        }

      prix = stod(prixStr);
      if (prix < 0)
        {
          cout << "Le prix doit être un nombre positif ou nul, recommencez" << endl;
          continue;
        }
      break;
    }

 
  while (true)
    {
      cout << "Code :" << endl;
      cin.getline(buffer, 256);
      code = buffer;

      if (util::validerCodeProduit(code, description, prix))
        {
          break;
        }
      cout << "Le code n'est pas valide, recommencez" << endl;
    }


  while (true)
    {
      cout << "Garantie : " << endl;
      cin.getline(buffer, 256);
      garantieStr = buffer;

      if (garantieStr.empty())
        {
          cout << "La garantie doit être un entier positif ou nul, recommencez" << endl;
          continue;
        }

      bool formatValide = true;
      for (size_t i = 0; i < garantieStr.size() && formatValide; ++i)
        {
          char c = garantieStr[i];
          if (!isdigit(static_cast<unsigned char>(c)))
            {
              formatValide = false;
            }
        }

      if (!formatValide)
        {
        cout << "La garantie doit être un entier positif ou nul, recommencez" << endl;
        continue;
        }

      garantie = stoi(garantieStr);
      break;
    }

  while (true)
    {
      cout << "Reconditionné? oui:1 non:0" << endl;
      cin.getline(buffer, 256);
      recondStr = buffer;

      if (recondStr == "1")
        {
          estReconditionne = true;
          break;
        }
      if (recondStr == "0")
        {
          estReconditionne = false;
          break;
        }

      cout << "La valeur doit être 1 (oui) ou 0 (non), recommencez" << endl;
    }

  Electronique e(description, prix, code, garantie, estReconditionne);
  return e;
}

/**
 * \brief Fonction principale du programme.
 */
int main()
{
  // Chargement du catalogue initial
  Catalogue catalogue = chargerCatalogueDepuisFichier("catalogue_produits_valide.txt");

  // Affichage du catalogue initial
  cout << catalogue.reqCatalogueFormate();
  
  Electronique electro("Smartphone Galaxy", 499.90, "PRD-SMAR-60", 24, false);
  
  try
  {
  catalogue.ajouterProduit(electro);
  }
  catch(ProduitDejaPresentException &e)
  {
      string message = e.what();
      
      cout<< message;
  }
  /* Enregistrement d’un nouveau Vetement
  Vetement v = saisirVetement();
  catalogue.ajouterProduit(v);

  // Enregistrement d’un nouveau Electronique
  Electronique e = saisirElectronique();
  catalogue.ajouterProduit(e);

  // Réaffichage du catalogue modifié
  cout << catalogue.reqCatalogueFormate();
   */  

  return 0;
}



