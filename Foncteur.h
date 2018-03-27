/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <utility>
#include "Produit.h"
using namespace std;
// TODO : Créer le FoncteurEgal
template< typename T >
class FoncteurEgal {
public:
	FoncteurEgal(T* t)
		: t_(t) {};
	bool operator()(pair <int, T*> pairEgal) {
		if (pairEgal.first == pairEgal.second)
			return true
		else
			return false
	};
private:
	T* t_;
};

// TODO : Créer le FoncteurGenerateurId
class FoncteurGenerateurId {
public:
	FoncteurGenerateurId() : id_(0) {};
	void operator()() {
		id_++;
	};
private:
	int id_;
};


// TODO : Créer le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent {
public:
	FoncteurDiminuerPourcent(int pourcentage) :pourcentage_(pourcentage) {};
	void operator()(pair<int, Produit*> reductionPair) {
		double prixReduit = reductionPair.second->Produit::obtenirPrix()
			+ reductionPair.first / 100 * reductionPair.second->Produit::obtenirPrix();
		reductionPair.second->modifierPrix(prixReduit);
	};
private:
	int pourcentage_;
};
/*
Attributs :
- pourcentage_;
Méthodes :
- operator(); Calule le nouveau prix du Produit de la pair passé en paramètre et le modifie
*/

// TODO : Créer le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
Méthodes :
- operator(); Vérifie que le Produit associé à la pair passé en paramètre est compris entre les bornes borneInf_ et borneSup_ (retourne un booléen)
*/

// TODO : Créer le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Ajoute dans la multimap la pair passé par paramètre et retourne la multimap_;
*/

// TODO : Créer le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/

//TODO : Créer le Foncteur AjouterUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
