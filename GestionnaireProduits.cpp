/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"

void GestionnaireProduits::reinitialiserClient() {
	for_each(conteneur_->begin(), conteneur_->end(), [](int i, Produit* produit) { 
		ProduitAuxEncheres *pae = dynamic_cast<ProduitAuxEncheres *>(produit);
		if (pae) {
			pae->modifierEncherisseur(nullptr);
			pae->modifierPrix(pae->obtenirPrixInitial());
		}
	});
	conteneur_->clear();
}

void GestionnaireProduits::reinitialiserFournisseur(){
	for_each(conteneur_->begin(), conteneur_->end(), [](int i, Produit* produit) {produit->modifierFournisseur(nullptr); });
	conteneur_->clear();
}

void GestionnaireProduits::afficher(){
	for_each(conteneur_->begin(), conteneur_->end(), [](int i, Produit*produit) {produit->afficher();});
}

double GestionnaireProduits::obtenirTotalAPayer(){
	double montant = 0;
	for_each(conteneur_->begin(), conteneur_->end(), [&montant](int i, Produit* produit) {montant += produit->obtenirPrix(); });
	return montant;
}

double GestionnaireProduits::obtenirTotalApayerPremium(){
	double montant =0;
	for_each(conteneur_->begin(), conteneur_->end(), [&montant](int i, Produit* produit) {double prix = produit->obtenirPrix();
	montant += prix < 5 ? 0 : prix - 5; });
	return montant;
}

Produit * GestionnaireProduits::trouverProduitPlusCher(){
	Produit* produitCher;
	max_element(conteneur_->begin(), conteneur_->end(), [&produitCher](int i, Produit* produit) {
		if (produit->obtenirPrix() > produitCher->obtenirPrix()) { produitCher = produit;} 
	});
	return produitCher;
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borne_Sup, double borne_Inf){
	vector<pair<int, Produit*>> produitsEntre;
	copy_if(conteneur_->begin(), conteneur_->end(), back_inserter(produitsEntre), FoncteurIntervalle(borne_Inf, borne_Sup));
	return produitsEntre;
}

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit * produit){
	Produit* produitSuivant;
	auto it = find_if(conteneur_->begin(), conteneur_->end(), bind(equal_to<int>(), produit->obtenirReference() + 1,
		[&produitSuivant](Produit* produitS) {produitS->obtenirReference(); produitSuivant = produitS; }));
	return produitSuivant;
}






