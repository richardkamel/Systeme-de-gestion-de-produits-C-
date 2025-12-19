/**
 * \file AccueilForm.cpp
 * \author Omar Mahamat
 * \date 8 décembre 2025
 * \brief Implémentation de la classe AccueilForm et de la fonction de chargement de catalogue.
 */


#include "AccueilForm.h"
#include "ElectroniqueForm.h"
#include "VetementForm.h"
#include "SupprimerProduitForm.h"
#include<QMessageBox>
#include <QInputDialog>  



using namespace commerce;
using namespace std;
using namespace util;


Catalogue chargerCatalogueDepuisFichier(const std::string& p_nomFichier);

/**
     * \brief Constructeur par défaut.
     *
     * Initialise la fenêtre principale et le widget généré par Qt Designer.
     * Le catalogue est initialisé avec un nom et la date d'aujourd'hui.
     */
AccueilForm::AccueilForm(): m_catalogue("Automne 2025", util::Date())
{

    widget.setupUi(this);

    
}
 /**
   * \brief Destructeur virtuel.
   */
AccueilForm::~AccueilForm() {
}
 /**
     * \brief Slot déclenché pour l'ajout d'un produit de type Electronique.
     *
     * Ouvre la boîte de dialogue ElectroniqueForm pour saisir les
     * informations du produit. Si la saisie est valide, crée un objet
     * Electronique et tente de l'ajouter au catalogue. En cas de doublon,
     * une ProduitDejaPresentException est interceptée et un message est
     * affiché à l'usager.
     */

void AccueilForm::slotElectronique()
{   
    
  ElectroniqueForm electroniqueForm;
  if(electroniqueForm.exec())
  {
      Electronique electro(electroniqueForm.reqDescription(), electroniqueForm.reqPrix(),electroniqueForm.reqCode(),electroniqueForm.reqGarantie(), electroniqueForm.reqRecontionne());
      try
        {
        m_catalogue.ajouterProduit(electro);
        
        m_catalogue.asgDerniereMiseAJour(util::Date());
        }
      catch(ProduitDejaPresentException &e)
        {
   
            QString message = e.what(); 
            QMessageBox::information(this, "ERREUR", message); 
        }
      
      widget.textBrowserCatalogue->setPlainText(m_catalogue.reqCatalogueFormate().c_str());
      
  }
}
   /**
     * \brief Slot déclenché pour l'ajout d'un produit de type Vetement.
     *
     * Ouvre la boîte de dialogue VetementForm pour saisir les informations
     * du vêtement, puis ajoute le produit au catalogue si les données sont
     * valides. En cas de doublon, un message d'erreur est affiché.
     */ 

void AccueilForm::slotVetement()
{
    VetementForm vetementForm;
    if (vetementForm.exec())
    {
        Vetement v(vetementForm.reqDescription(),vetementForm.reqPrix(),vetementForm.reqCode(),vetementForm.reqTaille(),vetementForm.reqCouleur());

        try {
            m_catalogue.ajouterProduit(v);
            m_catalogue.asgDerniereMiseAJour(util::Date());
        }
        catch (ProduitDejaPresentException& e) {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }

        widget.textBrowserCatalogue->setPlainText(m_catalogue.reqCatalogueFormate().c_str());
    }
}
   /**
     * \brief Slot déclenché pour la suppression d'un produit du catalogue.
     *
     * Ouvre la boîte de dialogue SupprimerProduitForm afin de saisir le
     * code du produit à supprimer. Si le produit est absent, une
     * ProduitAbsentException est interceptée et un message d'erreur est
     * affiché.
     */

void AccueilForm::slotSupprimerProduit()
{
    SupprimerProduitForm supprimeform;

    if (supprimeform.exec())
    {
        string code = supprimeform.reqCode();

        try {
            m_catalogue.supprimerProduit(code);
            m_catalogue.asgDerniereMiseAJour(util::Date());
            widget.textBrowserCatalogue->setPlainText(
                m_catalogue.reqCatalogueFormate().c_str()
            );
        }
        catch (ProduitAbsentException& e) {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }
    }
}
   /**
     * \brief Slot permettant de charger un catalogue à partir d'un fichier.
     *
     * Utilise la fonction libre chargerCatalogueDepuisFichier() pour
     * remplacer le catalogue courant par celui décrit dans le fichier
     * texte. L'affichage du catalogue est ensuite mis à jour.
     */
void AccueilForm::slotChargerCatalogue()
{
    
    m_catalogue = chargerCatalogueDepuisFichier("catalogue_produits_valide.txt");

   
    widget.textBrowserCatalogue->setPlainText(
        m_catalogue.reqCatalogueFormate().c_str()
    );
}
    
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

  
  string nomCatalogue;
  std::getline(fichier, nomCatalogue);

  
  int jour = 1;
  int mois = 1;
  int annee = 2000;
  fichier >> jour >> mois >> annee;
  fichier.ignore(numeric_limits<streamsize>::max(), '\n');

  Date dateCatalogue(jour, mois, annee);
  Catalogue catalogue(nomCatalogue, dateCatalogue);

  
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
      
      
      replace(prixStr.begin(), prixStr.end(), '.' , ',');
      double prix = stod(prixStr);

      if (type == "Electronique")
        {
          std::getline(ss, champ5, ','); 
          std::getline(ss, champ6, ',');  

          int garantie = stoi(champ5);
          bool reconditionne = (champ6 == "1");

          Electronique e(description, prix, code, garantie, reconditionne);
          catalogue.ajouterProduit(e);
        }
      else if (type == "Vetement")
        {
          std::getline(ss, champ5, ',');  
          std::getline(ss, champ6, ',');  

          Vetement v(description, prix, code, champ5, champ6);
          catalogue.ajouterProduit(v);
        }
      else
        {
    
        }
    }

  return catalogue;
}