/**
 * \file VetementForm.h
 * \author Omar Mahamat
 * \date 8 décembre 2025
 * \brief Déclaration de la boîte de dialogue d'ajout d'un Vetement.
 */

#ifndef _VETEMENTFORM_H
#define _VETEMENTFORM_H

#include "ui_VetementForm.h"

/**
 * \class VetementForm
 * \brief Boîte de dialogue pour saisir un produit de type Vetement.
 *
 * VetementForm fournit une interface graphique pour collecter les
 * informations nécessaires à la création d’un objet Vetement :
 * description, prix, code, taille et couleur.
 */
class VetementForm : public QDialog {
    Q_OBJECT
public:
    VetementForm();
    virtual ~VetementForm();
    
    std::string reqDescription() const;
    double reqPrix() const;
    std::string reqCode() const;
    std::string reqTaille() const;
    std::string reqCouleur() const;
    
private slots:
    void slotOK();
    
private:
    Ui::VetementForm widget;
};

#endif /* _VETEMENTFORM_H */
