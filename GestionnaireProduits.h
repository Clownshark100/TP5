

/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
* 
* Le gestionnaire de produits est une impl�mentation
* du gestionnaire g�n�rique pour le cas de nos Produits.
* Il impl�mente le conteneur comme une multimap et d�finit
* les foncteurs d'ajout et de suppression appropri�s.
* 
*******************************************/

#pragma once

#include <map>
#include <vector>
#include "GestionnaireGenerique.h"
#include "Produit.h"
#include "Foncteur.h"
#include <iterator>
#include <functional>


// TODO : Cr�er la classe GestionnaireProduits

// TODO : M�thodes :
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

class GestionnaireProduits 
	: public GestionnaireGenerique<Produit*, multimap<int, Produit*>, AjouterProduit, SupprimerProduit>{
	
	
	public:

	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher();
	double obtenirTotalAPayer();
	double obtenirTotalApayerPremium();
	Produit* trouverProduitPlusCher();
	vector<pair<int,Produit*>> obtenirProduitsEntre(double borne_Sup, double borne_Inf);
	Produit* obtenirProduitSuivant(Produit* produit);
	
};
