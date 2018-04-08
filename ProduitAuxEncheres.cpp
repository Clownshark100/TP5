#include "ProduitAuxEncheres.h"
//constructeur par parametes
ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}
//constructeur par parametes
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}
//Accesseur prixInitial_
double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}
//Accesseur encherisseur_
Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}
//Affiche l'information du produit, le prix initial et son encherisseur
void ProduitAuxEncheres::afficher() const
{
    Produit::afficher();
    cout << "\t\tprix initial:\t" << prixInitial_ << endl
         << "\t\tencherisseur:\t" << encherisseur_->obtenirNom() << endl;
}
//Modificateur de prixInitial_
void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}
//Modificateur de encherisseur_
void ProduitAuxEncheres::modifierEncherisseur(Client *encherisseur)
{
    encherisseur_ = encherisseur;
}
//Met a jour l'enchere
void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
    if (encherisseur_ == encherisseur)
        return;
    prix_ = nouveauPrix;
    encherisseur->ajouterProduit(this);
    if (encherisseur_ != nullptr)
        encherisseur_->enleverProduit(this);
    encherisseur_ = encherisseur;
}
