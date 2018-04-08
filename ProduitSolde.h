/********************************************
* Titre: Travail pratique #5 - ProduitSolde.h
* Date: 9 mars 2018
* Auteur: Loic LeBlanc et Daniel Nahum
* 
* Un produitSolde est un produit dont le prix est
* affecté par un solde. Son prix est donc différent de
* ce qu'il serait normalement.
* 
*******************************************/

#ifndef PRODUIT_SOLDE_H
#define PRODUIT_SOLDE_H

#include <string>
#include <iostream>
#include "Solde.h"
#include "Produit.h"

using namespace std;

class ProduitSolde : public Produit, public Solde
{
  public:
    ProduitSolde(int pourcentageRabais = 0);
    ProduitSolde(Fournisseur *fournisseur, const string &nom, int reference,
                 double prix, int pourcentageRabais = 0);

    virtual double obtenirPrix() const;
    virtual void afficher() const;
};

#endif
