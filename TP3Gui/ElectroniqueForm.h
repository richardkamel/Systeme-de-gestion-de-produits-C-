/**
 * \file ElectroniqueForm.h
 * \author Omar Mahamat
 * \date 8 décembre 2025
 * \brief Déclaration de la boîte de dialogue d'ajout d'un produit Electronique.
 */

#ifndef _ELECTRONIQUEFORM_H
#define _ELECTRONIQUEFORM_H

#include "ui_ElectroniqueForm.h"
/**
 * \class ElectroniqueForm
 * \brief Boîte de dialogue pour saisir un produit électronique.
 *
 * Cette classe encapsule la boîte de dialogue Qt permettant de saisir
 * les informations nécessaires à la création d'un objet Electronique :
 * description, prix, code, durée de garantie et indication de
 * reconditionnement.
 *
 * Les méthodes d'accès (reqDescription(), reqPrix(), etc.) permettent à
 * la fenêtre principale de récupérer les valeurs saisies par l'usager
 * après validation.
 */

class ElectroniqueForm : public QDialog {
    Q_OBJECT
public:
    ElectroniqueForm();
    virtual ~ElectroniqueForm();
    
    std::string reqDescription()const;
    double reqPrix()const;
    std::string reqCode()const;
    int reqGarantie()const;
    bool reqRecontionne()const;
    
private slots:
    void slotOK();
    
    
private:
    Ui::ElectroniqueForm widget;
};

#endif /* _CATALOGUEFORM_H */
