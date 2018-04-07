/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include <algorithm>

template <class T, class C, class A, class S>

class GestionnaireGenerique{

public:

	void ajouter(const T ajout);
	void supprimer(const T aSupprimer);
	
	template<class Predicate> void pourChaqueElement(Predicate& fun);
	
	C& obtenirConteneur(){
		return conteneur_;
	}
	
protected:
	
	C conteneur_;
	
};

template <class T, class C, class A, class S>
void GestionnaireGenerique<T, C, A, S>::ajouter(const T ajout){
	A foncteurAjout(conteneur_);
	foncteurAjout(ajout);
}

template <class T, class C, class A, class S>
void GestionnaireGenerique<T,C,A,S>::supprimer(const T aSupprimer){
	S foncteurSuppression(conteneur_);
	foncteurSuppression(aSupprimer);
}

template <class T, class C, class A, class S>
template<class Predicate> void GestionnaireGenerique<T,C,A,S>::pourChaqueElement(Predicate& fun){
	for_each(conteneur_.begin(), conteneur_.end(), fun);
}
