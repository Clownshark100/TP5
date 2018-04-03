/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"
double GestionnaireUsager::obtenirChiffreAffaires() const {
	double chiffreAffaires = 0;
	for_each(conteneur_->begin(), conteneur_->end(), [&chiffreAffaires](Usager* usager) {chiffreAffaires += usager->obtenirTotalAPayer(); });
	return chiffreAffaires;
}
void GestionnaireUsager::encherir(Client* client, ProduitAuxEncheres *produit, double montant) const {
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}

void GestionnaireUsager::reinitialiser(){
	for_each(conteneur_->begin(), conteneur_->end(), [](Usager* usager) {usager->reinitialiser(); });
}

void GestionnaireUsager::afficherProfils() const {
	for_each(conteneur_->begin(), conteneur_->end(), [](Usager* usager) {usager->afficher(); cout << endl; });
}

