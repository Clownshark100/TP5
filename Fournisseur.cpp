/********************************************
* Titre: Travail pratique #5 - Fournisseur.cpp
* Date: 9 mars 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/
#include "Fournisseur.h"
#include <iostream>
////Constructeur par default
Fournisseur::Fournisseur()
    : Usager(),catalogue_(new GestionnaireProduits)
{
}
//Constructeur par parametres
Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal), catalogue_(new GestionnaireProduits)
{
}
//Destructeur
Fournisseur::~Fournisseur() {
	delete catalogue_;
}
//Accesseur de catalogue
GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}
// Affiche le contenu du catalogue
void Fournisseur::afficherCatalogue() const
{
	// TODO : À modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	catalogue_->afficher();
	cout << endl;
}
// Affiche le profil du Fournisseur
void Fournisseur::afficher() const
{
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}
//Reinitialise le Fournisseur
void Fournisseur::reinitialiser()
{
	catalogue_->reinitialiserFournisseur();
}
//Ajoute un produit au catalogue si le produit n'est pas deja dans le catalogue ou remplace le produit si c un fournisseur different
void Fournisseur::ajouterProduit(Produit *produit)
{
	for (auto it = catalogue_->obtenirConteneur().begin(); it != catalogue_->obtenirConteneur().end(); it++) {
		if(it->second == produit)
			return;
	}
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	catalogue_->ajouter(produit);
}
//Supprime le produit du catalogue
void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
	catalogue_->supprimer(produit);
}
//Retourne le produit le plus cher du catalogue
Produit * Fournisseur::trouverProduitPlusCher() const
{
	return catalogue_->trouverProduitPlusCher();
}
//Diminuele prix de chaque element du catalogue d'un certain pourcentage
void Fournisseur::DiminuerPrix(int pourcent) const
{
	FoncteurDiminuerPourcent dimPourcent(pourcent);
	catalogue_->pourChaqueElement(dimPourcent);
}
