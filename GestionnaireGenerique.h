/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#include "Gestionnaire.h"
#include "Foncteur.h"
#pragma once

// TODO : Cr�er la classe GestionnaireGenerique
template <typename A,typename C,typename T,typename S>
class GestionnaireGenerique{
public:
	void ajouter(T* t) {
		
	};
protected:
	C* conteneur_;
};
// TODO : M�thodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/