/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/

#include "GestionnaireUsagers.h"
//Calcul le total des TotalAPayer des usager du gestionnaire
double GestionnaireUsagers::obtenirChiffreAffaires() const {
	double chiffreAffaires = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		chiffreAffaires += (*it)->obtenirTotalAPayer();
	}
	return chiffreAffaires;
}
//Met a jour une enchere
void GestionnaireUsagers::encherir(Client* client, ProduitAuxEncheres *produit, double montant) const {
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}
//reinitialise chaque usager
void GestionnaireUsagers::reinitialiser() {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it)->reinitialiser();
	}
}
//Affiche le profil des usagers du gestionnaire
void GestionnaireUsagers::afficherProfils() const {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		(*it)->afficher();
	}
	cout << endl;
}