#include "Produit.h"
#include "Fournisseur.h"
#include <iostream>
#include <string>
//Constructeur par parametres
Produit::Produit(Fournisseur *fournisseur, const string &nom, int reference, double prix)
    : fournisseur_(fournisseur),
      nom_(nom),
      reference_(reference),
      prix_(prix)
{
    if (fournisseur_ != nullptr)
        fournisseur_->ajouterProduit(this);
}
//Accesseur nom_
string Produit::obtenirNom() const
{
    return nom_;
}
//Accesseur reference_
int Produit::obtenirReference() const
{
    return reference_;
}
//Accesseur prix_
double Produit::obtenirPrix() const
{
    return prix_;
}
//Accesseur fournisseur_
Fournisseur *Produit::obtenirFournisseur() const
{
    return fournisseur_;
}
//Affiche l'information du produit
void Produit::afficher() const
{
    cout << "\t" << nom_ << endl
         << "\t\treference:\t" << reference_ << endl
         << "\t\tprix:\t\t" << "$" << prix_ << endl;
    if (fournisseur_ != nullptr)
        cout << "\t\tfournisseur:\t" << fournisseur_->obtenirNom() << endl;
}
//Modificateur de nom_
void Produit::modifierNom(const string &nom)
{
    nom_ = nom;
}
//Modificateur de reference_
void Produit::modifierReference(int reference)
{
    reference_ = reference;
}
//Modificateur de prix_
void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}
//Modificateur de fournisseur_
void Produit::modifierFournisseur(Fournisseur *fournisseur)
{
    fournisseur_ = fournisseur;
}
