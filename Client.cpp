#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
	panier_ = new GestionnaireProduits();
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
	panier_ = new GestionnaireProduits();
}


unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

GestionnaireProduits* Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
    double montant = panier_->obtenirTotalAPayer();
    return montant;
}

void Client::afficherPanier() const
{
	// TODO : � modifier
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
	panier_->afficher();
}
void Client::afficher() const
{
	// TODO : � modifier
    Usager::afficher();
	cout << "\t\tcode client:\t" << codeClient_ << endl
         << "\t\tpanier:\t\t" << panier_->obtenirConteneur()->size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
	// TODO : � modifier
	panier_->supprime(produit);
}

void Client::ajouterProduit(Produit *produit)
{
	// TODO : � modifier
	panier_->ajouter(produit);
}

void Client::reinitialiser()
{
	// TODO : � modifier
	panier_->reinitialiserClient();
}
