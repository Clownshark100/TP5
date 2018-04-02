/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"
double GestionnaireUsager::obtenirChiffreAffaires() const {
	double chiffreAffaires = 0;
	for_each(conteneur_->begin(), conteneur_->end(), [&chiffreAffaires](Usager* usager) {chiffreAffaires += usager->obtenirTotalAPayer(); });
	return chiffreAffaires;
}
void GestionnaireUsager::encherir(Client* client, ProduitAuxEncheres *produit, double montant) const {

}