/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#pragma once

// TODO : Créer la classe GestionnaireGenerique
template <typename A,typename C,typename T,typename S>
class GestionnaireGenerique {
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
	//TODO: implement forEachElement
protected:
	C* conteneur_;
};
