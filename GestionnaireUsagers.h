/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"

// TODO : Créer la classe GestionnaireUsager

class GestionnaireUsager : public GestionnaireGenerique<AjouterUsager, set<Usager*>,Usager*, SupprimerUsager<Usager*>> {
public:
	double obtenirChiffreAffaires() const;
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	void reinitialiser();
	void afficherProfils() const;
};
// TODO : La classe ressemble beaucoup à la classe Gestionnaire
/*
Les méthodes retrouvées de la classe Gestionnaire sont :
- double obtenirChiffreAffaires() const;
- void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
- void reinitialiser();
- void afficherProfils() const;
*/