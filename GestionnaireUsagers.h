/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
* 
* Le gestionnaire d'Usagers est une impl�mentation
* du gestionnaire g�n�rique pour le cas de nos Produits.
* Il impl�mente le conteneur comme un set et d�finit
* les foncteurs d'ajout et de suppression appropri�s.
* 
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Usager.h"
#include <set>
#include "Foncteur.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"


// TODO : Cr�er la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup � la classe Gestionnaire
/*
Les m�thodes retrouv�es de la classe Gestionnaire sont :
- double obtenirChiffreAffaires() const;
- void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
- void reinitialiser();
- void afficherProfils() const;
*/

class GestionnaireUsagers : public GestionnaireGenerique<Usager*,set<Usager*>, AjouterUsager, SupprimerUsager> {

public:
	double obtenirChiffreAffaires() const;
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	void reinitialiser();
	void afficherProfils() const;
	
};
