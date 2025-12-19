

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <istream>
#include <string>
namespace util {
bool validerCodeProduit(const std::string& p_code, const std::string& p_nom, double p_prix); 

bool validerFormatFichier(std::istream& p_is);


std::string genererCodeProduit(const std::string& p_nom, double p_prix);

}
#endif /* VALIDATIONFORMAT_H */

