/********************************************
* Titre: Travail pratique #5 - Client.cpp
* Date: 9 mars 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include "GestionnaireGenerique.h"
#include <iostream>

//Constructeur par parametres
Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient), panier_(new GestionnaireProduits)
{
	panier_ = new GestionnaireProduits();
}
//Constructeur par parametres
Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient), panier_(new GestionnaireProduits)
{
	panier_ = new GestionnaireProduits();
}
// Destructeur
Client::~Client() {
	delete panier_;
}
// Accesseur de codeClient_
unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}
// Accesseur de panier_
GestionnaireProduits* Client::obtenirPanier() const
{
    return panier_;
}
// Retourne le total a payer du panier
double Client::obtenirTotalAPayer() const
{
    double montant = 0;
	montant = panier_->obtenirTotalAPayer();
	return montant;
}
// Affiche les elements du paniers
void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	panier_->afficher();
}
// Affiche les informations de l'usager et la quantite d'elements dans le panier
void Client::afficher() const
{
    Usager::afficher();
	cout << "\t\tcode client:\t" << codeClient_ << endl
		<< "\t\tpanier:\t\t" << panier_->obtenirConteneur().size() << " elements" << endl;

}
// Modificateur de codeClient_
void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}
//Supprime un produit du panier
void Client::enleverProduit(Produit *produit)
{
	panier_->supprimer(produit);
}
//Ajoute un produit au panier
void Client::ajouterProduit(Produit *produit)
{
	panier_->ajouter(produit);
}
// Reinitialise le panier du client
void Client::reinitialiser()
{
	panier_->reinitialiserClient();
}
//Retourne le produit le plus cher du panier
Produit*Client::trouverProduitPlusCher() const {
	return panier_->trouverProduitPlusCher();
}
