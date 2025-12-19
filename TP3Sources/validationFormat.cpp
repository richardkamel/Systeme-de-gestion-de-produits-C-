#include "validationFormat.h"
#include <iostream>
#include <string>
#include <cctype> 
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

namespace util {
bool validerCodeProduit(const string& p_code, const string& p_nom, double p_prix)
{
    if (p_code.length() != 11 || p_code.substr(0, 4) != "PRD-") {
        return false;
    }
    string code = "PRD-";
    string name = "";
    int somme = 0;

    // Extraire les 4 premières lettres du nom
   for (char c : p_nom) {
        if (isalpha(static_cast<unsigned char>(c))) {
            name += static_cast<char>(toupper(c));
            if (name.size() == 4) break;
        }
    }

    // Ajouter les valeurs ASCII (A=1, B=2... Z=26)
    for (char c : name) {
        int valeur = static_cast<int>(c) - 64; // 'A' = 65 → 65-64=1
        somme += valeur;
    }

    code += name + "-";

    // Récupérer les cents
    int totalCents = static_cast<int>(round(p_prix * 100));
    int cents = totalCents % 100;
    int dizaine = cents / 10;
    int unite  = cents % 10;

    somme += dizaine + unite;

    // Clé de contrôle = somme % 100
    int cle = somme % 100;

    if (cle < 10)
        code += "0";
    code += to_string(cle);

    return (code == p_code);
}



bool validerFormatFichier(std::istream& p_is)
{
    if (!p_is.good()) { // fichier non ouvert / invalide
        return false;
    }

    bool valide = true;
    std::string ligne;
    int numLigne = 0;

    // petite fonction locale pour nettoyer
    auto trim = [](std::string& s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end   = s.find_last_not_of(" \t\r\n");
        if (start == std::string::npos) {
            s.clear();
        } else {
            s = s.substr(start, end - start + 1);
        }
    };

    while (std::getline(p_is, ligne) && valide) {
        numLigne++;
        trim(ligne);

        if (ligne.empty()) {
            valide = false;
            break;
        }

        if (numLigne == 1) {
            if (ligne.find_first_not_of(" \t\r\n") == std::string::npos) {
                valide = false;
                break;
            }
        }
        else if (numLigne == 2) {
            std::istringstream iss(ligne);
            int jj, mm, aaaa;
            if (!(iss >> jj >> mm >> aaaa)) {
                valide = false;
                break;
            }
            if (jj <= 0 || mm <= 0 || aaaa <= 0 || mm > 12 || jj > 31) {
                valide = false;
                break;
            }
        }
        else {
            std::string champs[6];
            std::istringstream ss(ligne);
            std::string champ;
            int count = 0;

            while (std::getline(ss, champ, ',')) {
                trim(champ);
                if (count < 6) champs[count] = champ;
                count++;
            }

            if (count != 6) {
                valide = false;
                break;
            }

            std::string type        = champs[0];
            std::string nom         = champs[1];
            std::string prixStr     = champs[2];
            std::string codeProduit = champs[3];
            std::string attr1       = champs[4];
            std::string attr2       = champs[5];

            if (type != "Electronique" && type != "Vetement") {
                valide = false;
                break;
            }

            double prix = 0.0;
            try {
                for (char& c : prixStr) if (c == ',') c = '.';
                prix = std::stod(prixStr);
            } catch (...) {
                valide = false;
                break;
            }

            if (!validerCodeProduit(codeProduit, nom, prix)) {
                valide = false;
                break;
            }

            if (type == "Vetement") {
                trim(attr1);
                trim(attr2);
                for (char& c : attr1) c = std::toupper(static_cast<unsigned char>(c));

                if (!(attr1 == "XS" || attr1 == "S" || attr1 == "M" ||
                      attr1 == "L"  || attr1 == "XL" || attr1 == "XXL")) {
                    valide = false;
                    break;
                }
                if (attr2.empty()) {
                    valide = false;
                    break;
                }
            }
            else if (type == "Electronique") {
                int garantie, recond;
                try {
                    garantie = std::stoi(attr1);
                    recond   = std::stoi(attr2);
                } catch (...) {
                    valide = false;
                    break;
                }
                if (garantie < 0 || (recond != 0 && recond != 1)) {
                    valide = false;
                    break;
                }
            }
        }
    }

    return valide;
}
string genererCodeProduit(const string& p_nom, double p_prix)
{
    string code = "PRD-";
    string name;
    int somme = 0;

    // Extraire les 4 premières lettres alphabétiques du nom, en majuscules
    for (char c : p_nom)
    {
        if (isalpha(static_cast<unsigned char>(c)))
        {
            name += static_cast<char>(toupper(static_cast<unsigned char>(c)));
            if (name.size() == 4)
            {
                break;
            }
        }
    }

 
    for (char c : name)
    {
        int valeur = static_cast<int>(c) - 64; // 'A'=65 → 1, etc.
        somme += valeur;
    }

    code += name + "-";

  
    int totalCents = static_cast<int>(std::round(p_prix * 100));
    int cents = totalCents % 100;
    int dizaine = cents / 10;
    int unite  = cents % 10;

    somme += dizaine + unite;


    int cle = somme % 100;

    if (cle < 10)
    {
        code += "0";
    }
    code += to_string(cle);

    return code;
}


}


