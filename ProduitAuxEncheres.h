/********************************************
* Titre: Travail pratique #5 - ProduitAuxEncheres.h
* Date: 9 mars 2018
* Auteur: Loic LeBlanc et Daniel Nahum
* 
* Un Produit aux encheres est un produit ayant les
* fonctionalités necéssaires pour être mit aux enchères.
* Soit il possède un attribut enchérisseur, prix initial
* et prix présent.
* 
*******************************************/

#ifndef PRODUIT_AUX_ENCHERES_H
#define PRODUIT_AUX_ENCHERES_H

#include <string>
#include <iostream>
#include "Produit.h"
#include "Client.h"

using namespace std;

class ProduitAuxEncheres : public Produit
{
  public:
    ProduitAuxEncheres(double prix = 0.0);
    ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom, int reference,
                       double prix = 0.0);

    virtual double obtenirPrixInitial() const;
    Client *obtenirEncherisseur() const;
    virtual void afficher() const;

    void modifierPrixInitial(double prixInitial);
    void modifierEncherisseur(Client* encherisseur);
    void mettreAJourEnchere(Client *encherisseur, double nouveauPrix);

  private:
    double prixInitial_;
    Client *encherisseur_;
};

#endif
