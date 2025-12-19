/**
 * \file SupprimerProduitForm.cpp
 * \author Omar Mahamat
 * \date 8 décembre 2025
 * \brief Implémentation de la boîte de dialogue SupprimerProduitForm.
 */

#include <QMessageBox>
#include "SupprimerProduitForm.h"

using namespace std;


/**
 * \brief Constructeur par défaut.
 * Initialise l'interface générée à partir du fichier .ui.
 */
SupprimerProduitForm::SupprimerProduitForm()
{
    widget.setupUi(this);
}
/**
 * \brief Destructeur virtuel.
 */
SupprimerProduitForm::~SupprimerProduitForm()
{
}
 /**
   * \brief Slot déclenché lorsque l'usager demande la suppression.
   * Vérifie que le code n'est pas vide. En cas de champ vide, un
   * message d'erreur est affiché et la boîte de dialogue reste
   * ouverte. Sinon, la boîte de dialogue est acceptée.
   */
void SupprimerProduitForm::slotSupprimer()
{
    if (reqCode().empty()) {
        QMessageBox::information(this, "ERREUR", "Le code du produit ne doit pas être vide.");
        return; 
    }

    accept();
}

/**
 * \brief Retourne le code saisi par l'usager.
 * \return Le code du produit à supprimer.
 */

std::string SupprimerProduitForm::reqCode() const
{
    return widget.lineEditCode->text().toStdString();
}