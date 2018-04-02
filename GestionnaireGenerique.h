/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#include "Gestionnaire.h"
#include "Foncteur.h"
#pragma once

// TODO : Créer la classe GestionnaireGenerique
template <typename A,typename C,typename T,typename S, typename Predicate>
class GestionnaireGenerique{
public:
	C* obtenirConteneur() {
		return conteneur_;
	};
	void ajouter(T* t) {
		 A(t);
	};
	void supprime(T* t) {
		 S(t);
	};
	void pourChaqueElement(Predicate* predicate) {
		for_each(conteneur_.begin(), conteneur_.end(), predicate);
	};
protected:
	C* conteneur_;
};
