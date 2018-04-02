/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include <iostream>
#include <functional>
using namespace std;

// TODO : Créer la classe GestionnaireProduits
class GestionnaireProduits : GestionnaireGenerique<AjouterProduit,multimap<int, Produit*>, Produit*, SupprimerProduit<Produit*>> {
public:
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher();
	double obtenirTotalAPayer();
	double obtenirTotalApayerPremium();
	Produit* trouverProduitPlusCher();
	vector<pair<int,Produit*>>obtenirProduitsEntre(double borne_Sup, double borne_Inf);
	Produit* obtenirProduitSuivant(Produit* produit);

};
// TODO : Méthodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/