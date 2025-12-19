/**
 * \file SupprimerProduitForm.h
 * \author Omar Mahamat
 * \date 8 décembre 2025
 * \brief Déclaration de la boîte de dialogue de suppression d'un Produit.
 */

#ifndef _SUPPRIMERPRODUITFORM_H
#define _SUPPRIMERPRODUITFORM_H

#include "ui_SupprimerProduitForm.h"

/**
 * \class SupprimerProduitForm
 * \brief Boîte de dialogue pour saisir le code d'un produit à supprimer.
 * Cette boîte de dialogue demande à l'usager d'entrer le code d'un
 * produit à supprimer du catalogue. Le code saisi est récupéré grâce
 * à la méthode reqCode().
 */


class SupprimerProduitForm : public QDialog {
    Q_OBJECT
public:
    SupprimerProduitForm();
    virtual ~SupprimerProduitForm();
    
    std::string reqCode() const;
    
private slots:
    void slotSupprimer();
    
private:
    Ui::SupprimerProduitForm widget;
};

#endif /* _SUPPRIMERPRODUITFORM_H */
