/********************************************
* Titre: Travail pratique #5 - ClientPremium.cpp
* Date: 9 mars 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/
#include "ClientPremium.h"
#include <iostream>
//Constructeur par parametres
ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}
//Constructeur par parametres
ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}
//Accesseur de joursRestants_
unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}
//Retourne le total a payer d'un panier d'un client premium
double ClientPremium::obtenirTotalAPayer() const
{
    double montant = 0;
	montant = panier_->obtenirTotalApayerPremium();
	return montant;
}
//Affiche le profil du client Premium 
void ClientPremium::afficherProfil() const
{
    Client::afficher();
    cout << "\t\tjours restants:\t" << joursRestants_ << endl;
}
//Modificateur de joursRestants_
void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
