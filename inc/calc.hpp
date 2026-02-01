#ifndef CALC_HPP

#define CALC_HPP
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cctype>
#include <algorithm>

class Calc
{
    public:
    int formatString(std::string &str);
    int evaluateString(std::string &str, float &out);

    private:
    int parseTokens(std::vector<std::string> &tokens, std::queue<std::string> &queue);
    bool hasGreaterOrSamePrecedence(char op1, char op2);
    float eval(float a, float b, char op);
    int tokenizeString(std::string &str, std::vector<std::string> &out);

    protected:
    bool isNumber(std::string &str);
};

#endif