/**
 * \file ElectroniqueForm.cpp
 * \author Omar Mahamat
 * \date 8 décembre 2025
 * \brief Implémentation de la boîte de dialogue ElectroniqueForm.
 */


#include<QMessageBox>
#include "ElectroniqueForm.h"
#include "Electronique.h"
#include "validationFormat.h"

using namespace std;
using namespace util;
using namespace commerce;

/**
 *\brief Constructeur par défaut.
 * Initialise l'interface utilisateur générée à partir du fichier .ui.
 */
ElectroniqueForm::ElectroniqueForm() {
    widget.setupUi(this);
}
 /**
   * \brief Destructeur virtuel.
   */
ElectroniqueForm::~ElectroniqueForm() {
}
 /**
   * \brief Slot appelé lorsque l'usager clique sur le bouton OK.
   * Valide la combinaison (code, description, prix) à l'aide de la
   * fonction util::validerCodeProduit(). En cas d'erreur, un message
   * d'information est affiché et la boîte de dialogue reste ouverte.
   * En cas de succès, la boîte de dialogue est acceptée.
   */

void ElectroniqueForm::slotOK()
{
    if(!validerCodeProduit(reqCode(), reqDescription(), reqPrix()))
    {
      QString message = "La combinaison Code, Description et Prix est invalide "; 
      QMessageBox::information(this, "ERREUR", message);
      return;
        
    }
    accept();
    
}
  /**
    * \brief Retourne la description saisie.
    * \return La description du produit sous forme de std::string.
    */
string ElectroniqueForm::reqDescription()const
{
    return widget.lineEditDesc->text().toStdString();
        
}
 /**
   * \brief Retourne le prix saisi.
   * \return Le prix du produit sous forme de double.
   */
double ElectroniqueForm::reqPrix()const
{
    return widget.lineEditPrix->text().toDouble();
        
 }
   /**
     * \brief Retourne le code saisi.
     * \return Le code du produit.
     */
string ElectroniqueForm::reqCode()const
{
    return widget.lineEditCode->text().toStdString();
        
 }
  /**
    * \brief Retourne la durée de garantie saisie.
    * \return La durée de garantie en mois.
    */

int ElectroniqueForm::reqGarantie()const
{
    return widget.lineEditGaran->text().toInt();
        
 }
/**
  * \brief Indique si le produit est coché comme reconditionné.
  * \return true si le produit est reconditionné, false sinon.
  */

bool ElectroniqueForm::reqRecontionne()const
{
    return widget.checkBoxRecon->isChecked();
        
 }

