#ifndef ALG_HPP

#define ALG_HPP
#include "calc.hpp"

class Alg : private Calc
{
    public:

    // private:
    int isolateVariable(std::vector<std::string> &left, std::vector<std::string> &right, std::string var, std::vector<std::string> &out);
    int splitEquation(std::string &str, std::vector<std::string> &outLeft, std::vector<std::string> &outRight);
    int tokenizeString(std::string &str, std::vector<std::string> &out, char &var);
    int formatString(std::string &str);
};

#endif