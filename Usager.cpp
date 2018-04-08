#include "Usager.h"
#include <iostream>
//Constructeur par parametres
Usager::Usager(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
    : nom_(nom),
      prenom_(prenom),
      reference_(identifiant),
      codePostal_(codePostal)
{
}
//Accesseur de nom_
string Usager::obtenirNom() const
{
    return nom_;
}
//Accesseur de prenom_
string Usager::obtenirPrenom() const
{
    return prenom_;
}
//Accesseur de reference_
int Usager::obtenirReference() const
{
    return reference_;
}
//Accesseur de codePostal_
string Usager::obtenirCodePostal() const
{
    return codePostal_;
}
//Un usager n'a pas de panier donc son total a payer est 0
double Usager::obtenirTotalAPayer() const
{
    return 0;
}
//Affiche l'information de l'usager
void Usager::afficher() const
{
    cout << "\t" << nom_ << ", " << prenom_ << " (" << reference_ << ")" << endl
        << "\t\tcode postal:\t" << codePostal_ << endl;
}
//Modificateur de nom_
void Usager::modifierNom(const string &nom)
{
    nom_ = nom;
}
//Modificateur de prenom_
void Usager::modifierPrenom(const string &prenom)
{
    prenom_ = prenom;
}
//Modificateur de reference_
void Usager::modifierReference(int reference)
{
	reference_ = reference;
}
//Modificateur de codePostal_
void Usager::modifierCodePostal(const string &codePostal)
{
    codePostal_ = codePostal;
}
