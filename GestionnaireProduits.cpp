/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"

using namespace placeholders;
//Vide le conteneur_ et reninitialise les produits aux encheres qui sont dans le conteneur
void GestionnaireProduits::reinitialiserClient() {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		ProduitAuxEncheres *pae = dynamic_cast<ProduitAuxEncheres *>(it->second);
		if (pae) {
			pae->modifierEncherisseur(nullptr);
			pae->modifierPrix(pae->obtenirPrixInitial());
		}
	}
	conteneur_.clear();
}
//Reinintialise le fournisseur et vide le conteneur du fournisseur
void GestionnaireProduits::reinitialiserFournisseur() {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		it->second->modifierFournisseur(nullptr);
	}
	conteneur_.clear();
}
//Affiche les elements du conteneurs
void GestionnaireProduits::afficher() {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		it->second->afficher();
	}
}
//Calcul le total du prix de tout les elements du conteneur
double GestionnaireProduits::obtenirTotalAPayer() {
	double montant = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		montant += it->second->obtenirPrix();
	}
	return montant;
}
//Calcul le total du prix de tout les elements d'un conteneur apparetenant a un usager premium
double GestionnaireProduits::obtenirTotalApayerPremium() {
	double montant = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		double prix = it->second->obtenirPrix();
		montant += prix < 5 ? 0 : prix - 5;
	}
	return montant;
}
//Retourne le produit le plus cher du conteneur
Produit * GestionnaireProduits::trouverProduitPlusCher() {
	auto it =max_element(conteneur_.begin(), conteneur_.end(), [](pair<int, Produit*> produit1, pair<int, Produit*> produit2) {
		return produit1.second->obtenirPrix() < produit2.second->obtenirPrix();
	});
	 return it->second;
}
//Liste des produits dont leur prix est compris dans un intervalle
vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borne_Inf, double borne_Sups) {
	vector<pair<int, Produit*>> produitsEntre;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(produitsEntre), FoncteurIntervalle(borne_Inf, borne_Sups));
	return produitsEntre;
}
//Va chercher le produit suivant 
Produit* GestionnaireProduits::obtenirProduitSuivant(Produit * produit) {
	auto greaterInt = greater<int>();
	auto it = find_if(conteneur_.begin(), conteneur_.end(),bind(greater<pair<int,Produit*>>(), _1, pair<int,Produit*>(produit->obtenirReference(), produit)));
	return it->second;
}
