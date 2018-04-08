#include "ProduitSolde.h"
// constructeur par parametres
ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}
// constructeur par parametres
ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}
// Applique un rabais sur un prix
double ProduitSolde::obtenirPrix() const
{
    return (prix_ * (100 - pourcentageRabais_)) / 100.0;
}
//Affiche le rabais 
void ProduitSolde::afficher() const
{
    Produit::afficher();
    cout << "\t\trabais:\t\t" << pourcentageRabais_ << "%" << endl;
}
