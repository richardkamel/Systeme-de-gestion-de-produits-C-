/**
 * \file AccueilForm.h
 * \author Omar Mahamat
 * \date 8 novembre 2025
 * \brief Interface de la classe AccueilForm.
 */



#ifndef _ACCUEILFORM_H
#define _ACCUEILFORM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <cctype>


#include "ui_AccueilForm.h"
#include "Catalogue.h"
#include "Date.h"
#include "Electronique.h"
#include "Vetement.h"
#include "ProduitException.h"

/**
 * \class AccueilForm
 * \brief Fenêtre principale de l'application de gestion de catalogue.
 *
 * AccueilForm hérite de QMainWindow et encapsule l'interface graphique
 * principale. Elle gère un objet commerce::Catalogue et connecte les actions
 * de l'usager (menus, boutons, boîtes de dialogue) aux opérations offertes
 * par la classe Catalogue (ajout, suppression, chargement, affichage).
 */

class AccueilForm : public QMainWindow {
    Q_OBJECT
public:
    AccueilForm();
    virtual ~AccueilForm();
    
private slots:
    void slotElectronique();
    void slotVetement();          
    void slotSupprimerProduit();   
    void slotChargerCatalogue();
    
    
private:
    Ui::AccueilForm widget;
    commerce::Catalogue m_catalogue;
};

#endif /* _ACCUEILFORM_H */
