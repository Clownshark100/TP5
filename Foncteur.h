/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <utility>
#include "Produit.h"
using namespace std;
// TODO : Cr�er le FoncteurEgal
template< typename T >
class FoncteurEgal {
public:
	FoncteurEgal(T* t)
		: t_(t) {};
	bool operator()(pair <int, T*> pairEgal) {
		if (pairEgal.second == t_)
			return true
		else
			return false
	};
private:
	T* t_;
};

// TODO : Cr�er le FoncteurGenerateurId
class FoncteurGenerateurId {
public:
	FoncteurGenerateurId() : id_(0) {};
	void operator()() {
		id_++;
	};
private:
	int id_;
};


// TODO : Cr�er le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent {
public:
	FoncteurDiminuerPourcent(int pourcentage) :pourcentage_(pourcentage) {};
	void operator()(pair<int, Produit*> reductionPair) {
		double prixReduit = reductionPair.second->Produit::obtenirPrix()
			+ pourcentage_* reductionPair.second->Produit::obtenirPrix()/100;
		reductionPair.second->modifierPrix(prixReduit);
	};
private:
	int pourcentage_;
};

// TODO : Cr�er le FoncteurIntervalle
class FoncteurIntervalle {
public:
	FoncteurIntervalle(double borneInf, double borneSup) 
		: borneInf_(borneInf), borneSup_(borneSup){};
	bool operator()(pair<int, Produit*> prixCompIntervalle) {
		return (prixCompIntervalle.second->Produit::obtenirPrix() >= borneInf_
			&& prixCompIntervalle.second->Produit::obtenirPrix() <= borneSup_);
	};
private:
	double borneInf_;
	double borneSup_;
};

// TODO : Cr�er le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
*/

// TODO : Cr�er le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
*/

//TODO : Cr�er le Foncteur AjouterUsager
/*
Attributs :
- &set;
M�thodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
