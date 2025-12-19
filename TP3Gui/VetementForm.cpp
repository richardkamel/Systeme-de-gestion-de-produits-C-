/**
 * \file VetementForm.cpp
 * \author Omar Mahamat
 * \date 8 décembre 2025
 * \brief Implémentation de la boîte de dialogue VetementForm.
 */



#include <QMessageBox>
#include "VetementForm.h"
#include "validationFormat.h"

using namespace std;
using namespace util;
/**
  * \brief Constructeur par défaut.
  * Initialise l'interface utilisateur générée à partir de VetementForm.ui.
  */

VetementForm::VetementForm() {
    widget.setupUi(this);
}
  /**
    * \brief Destructeur virtuel.
    */
VetementForm::~VetementForm() {
}
 /**
  * \brief Slot appelé lorsque l'usager clique sur OK.
  * Valide la combinaison (code, description, prix). Si la validation
  * échoue, affiche un message d'erreur. Sinon, la boîte de dialogue
  * est acceptée.
  */
void VetementForm::slotOK()
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
   */

string VetementForm::reqDescription()const
{
    return widget.lineEditDesc->text().toStdString();
        
}
/**
  * \brief Retourne le prix saisi.
  */

double VetementForm::reqPrix()const
{
    return widget.lineEditPrix->text().toDouble();
        
 }

/**
  * \brief Retourne le code saisi.
  */
string VetementForm::reqCode()const
{
    return widget.lineEditCode->text().toStdString();
        
 }

/**
  * \brief Retourne la taille sélectionnée.
  */

string VetementForm::reqTaille() const
{
    return widget.comboBoxTaille->currentText().toStdString();
}
/**
  * \brief Retourne la couleur saisi.
  */

string VetementForm::reqCouleur() const
{
    return widget.lineEditCouleur->text().toStdString();
}