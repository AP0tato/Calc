#include "alg.hpp"

int Alg::tokenizeString(std::string &str, std::vector<std::string> &out, char &var)
{
    formatString(str);
    out.push_back(std::string(1, str[0]));
    for(size_t i = 1, j = 0; i < str.length(); i++)
    {
        if((str[i]=='.' && out[j].find('.')!=std::string::npos))
            return -1;
        if( (isNumber(out[j]) && std::isdigit(str[i])) || (str[i]=='.' && out[j].find('.')==std::string::npos) )
        {
            out[j] += str[i];
        }
        else
        {
            if(('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
                var = str[i];
            out.push_back(std::string(1, str[i]));
            j++;
        }
    }
    return 0;
}

int Alg::formatString(std::string &str)
{
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());

    char prev = 'a';
    int i = 0;
    for(char c : str)
    {
        if(!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '(' && c != ')' && c != '=' && c != '.' && !(( 'a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')))
        {
            return -1;
        }
        if( (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) && isdigit(prev) )
        {
            str.insert(i, "*");
            i++;
        }
        prev = c;
        i++;
    }

    return 0;
}

int Alg::splitEquation(std::string &str, std::vector<std::string> &outLeft, std::vector<std::string> &outRight)
{
    std::string left, right;
    size_t pos = str.find('=');
    if(pos == std::string::npos)
        return -1;

    left = str.substr(0, pos);
    right = str.substr(pos + 1);

    Calc::formatString(left);
    Calc::formatString(right);

    std::vector<std::string> rightTkn, leftTkn;
    char var = '\0';
    if(tokenizeString(left, leftTkn, var) != 0 || tokenizeString(right, rightTkn, var) != 0)
        return -1;

    if(var == '\0')
        return -1;

    return 0;
}

int Alg::isolateVariable(std::vector<std::string> &left, std::vector<std::string> &right, std::string var, std::vector<std::string> &out)
{

}