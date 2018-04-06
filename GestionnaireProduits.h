/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include <iostream>
#include <functional>
#include "Foncteur.h"
#include <vector>
#include "ProduitAuxEncheres.h"
using namespace std;

// TODO : Créer la classe GestionnaireProduits
class GestionnaireProduits : 
	public GestionnaireGenerique <AjouterProduit, multimap<int, Produit*>, Produit, SupprimerProduit> {
public:
	GestionnaireProduits();
	~GestionnaireProduits();
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher();
	double obtenirTotalAPayer();
	double obtenirTotalApayerPremium();
	Produit* trouverProduitPlusCher();
	vector<pair<int,Produit*>> obtenirProduitsEntre(double borne_Sup, double borne_Inf);
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