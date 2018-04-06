/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
GestionnaireProduits::GestionnaireProduits():GestionnaireGenerique<AjouterProduit, multimap<int, Produit*>, Produit, SupprimerProduit>(){
	conteneur_ = new multimap<int, Produit*>();
}
GestionnaireProduits::~GestionnaireProduits(){
	delete conteneur_;
}
void GestionnaireProduits::reinitialiserClient() {
	for(auto it = conteneur_->begin(); it!=conteneur_->end(); it++) { 
		ProduitAuxEncheres *pae = dynamic_cast<ProduitAuxEncheres *>(it->second);
		if (pae) {
			pae->modifierEncherisseur(nullptr);
			pae->modifierPrix(pae->obtenirPrixInitial());
		}
	}
	conteneur_->clear();
}

void GestionnaireProduits::reinitialiserFournisseur(){
	for (auto it = conteneur_->begin(); it != conteneur_->end(); it++){
		it->second->modifierFournisseur(nullptr);
	}
	conteneur_->clear();
}

void GestionnaireProduits::afficher(){
	for (auto it = conteneur_->begin(); it != conteneur_->end(); it++) {
		it->second->afficher(); 
	}
}

double GestionnaireProduits::obtenirTotalAPayer(){
	double montant = 0;
	for(auto it = conteneur_->begin(); it!= conteneur_->end(); it++) {
		montant += it->second->obtenirPrix(); 
	}
	return montant;
}

double GestionnaireProduits::obtenirTotalApayerPremium(){
	double montant =0;
	for(auto it = conteneur_->begin(); it!=conteneur_->end(); it++) {
		double prix = it->second->obtenirPrix();
		montant += prix < 5 ? 0 : prix - 5; 
	}
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






