/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <utility>
#include "Produit.h"
#include <map>
#include "Usager.h"
#include<algorithm>
#include<set>
using namespace std;
// TODO : Cr�er le FoncteurEgal
template< typename T >
class FoncteurEgal {
public:
	FoncteurEgal(T* t)
		: t_(t) {};
	bool operator()(pair <int, T*> pairEgal) {
		if (pairEgal.second == t_)
			return true;
		else
			return false;
	};
private:
	T* t_;
};

// TODO : Cr�er le FoncteurGenerateurId
class FoncteurGenerateurId {
public:
	FoncteurGenerateurId() : id_(0) {};
	int operator()() {
		return id_++;
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
class AjouterProduit {
public:
	AjouterProduit(multimap<int, Produit*>& multimap):multimap_(multimap) {};
	multimap<int, Produit*>& operator()(pair<int,Produit*> produit) {
		multimap_.insert(produit);
		return multimap_ ;
	};
private:
	multimap<int, Produit*>& multimap_;
};

// TODO : Cr�er le Foncteur SupprimerProduit
class SupprimerProduit {
public:
	SupprimerProduit(multimap<int, Produit*>& multimap) : multimap_(multimap) {};
	multimap<int, Produit*>& operator()(Produit* produit) {
		auto it = find_if(multimap_.begin(), multimap_.end(), FoncteurEgal<Produit>(produit));
		multimap_.erase(it);
		return multimap_;
	};
private:
	multimap<int, Produit*>& multimap_;
};

//TODO : Cr�er le Foncteur AjouterUsager
class AjouterUsager {
public:
	AjouterUsager(set<Usager*>& set) :set_(set) {};
	set<Usager*>& operator()(Usager* usager) {
		set_.insert(usager);
		return set_;
	};
private:
	set<Usager*>& set_;
};
//Foncteur SupprimerUsager
template< typename T >
class SupprimerUsager {
public:
	SupprimerUsager(set<Usager*>& set) :set_(set) {};
	set<Usager*>& operator()(Usager* usager) {
		auto it = find_if(set_.begin(), set_.end(), FoncteurEgal(usager));
		set_.erase(*it);
		return set_;
	};
private:
	set<Usager*>& set_;
};

