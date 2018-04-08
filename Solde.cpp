#include "Solde.h"
//constructeur par parametres
Solde::Solde(int pourcentageRabais)
    : pourcentageRabais_(pourcentageRabais)
{
}
//destructeur
Solde::~Solde() {}
//Accesseur de pourcentageRabais_
double Solde::obtenirPourcentageRabais() const
{
    return pourcentageRabais_;
}
//Modificateur de pourcentageRabais_
void Solde::modifierPourcentageRabais(int pourcentageRabais)
{
    pourcentageRabais_ = pourcentageRabais;
}