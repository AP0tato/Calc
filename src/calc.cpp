#include "calc.hpp"

int Calc::formatString(std::string &str)
{
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());

    for(char c : str)
    {
        if(!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '(' && c != ')' && c != '=' && c != '.')
        {
            return -1;
        }
    }

    return 0;
}

bool Calc::isNumber(std::string &str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && (std::isdigit(*it) || *it == '.')) ++it;
    return !str.empty() && it == str.end();
}

int Calc::tokenizeString(std::string &str, std::vector<std::string> &out)
{
    if(formatString(str) != 0)
        return -1;
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
            out.push_back(std::string(1, str[i]));
            j++;
        }
    }
    return 0;
}

bool Calc::hasGreaterOrSamePrecedence(char op1, char op2)
{
    std::map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3},
    };

    if(op1 == '(' || op2 == '(')
        return false;
    return precedence[op1] >= precedence[op2];
}

int Calc::parseTokens(std::vector<std::string> &tokens, std::queue<std::string> &queue)
{
    std::stack<char> stack;
    for(std::string token : tokens)
    {
        if(isNumber(token))
        {
            queue.push(token);
        }
        else if(token == ")")
        {
            while(stack.top() != '(')
            {
                queue.push(std::string(1, stack.top()));
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            while(!stack.empty())
            {
                if(hasGreaterOrSamePrecedence(stack.top(), token[0]))
                {
                    queue.push(std::string(1, stack.top()));
                    stack.pop();
                    continue;
                }
                break;
            }
            stack.push(token[0]);
        }
    }

    while(!stack.empty())
    {
        queue.push(std::string(1, stack.top()));
        stack.pop();
    }

    return 0;
}

float Calc::eval(float a, float b, char op)
{
    switch(op)
    {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
        case '^': return pow(b, a);
    }
    return 0.0f;
}

int Calc::evaluateString(std::string &str, float &out)
{
    std::stack<float> stack;
    std::vector<std::string> tokens;
    if(tokenizeString(str, tokens) != 0)
        return -1;
    std::queue<std::string> rpn;
    if(parseTokens(tokens, rpn) != 0)
        return -1;

    while(!rpn.empty())
    {
        if(isNumber(rpn.front()))
        {
            stack.push(std::stof(rpn.front()));
        }
        else
        {
            float a = stack.top();
            stack.pop();
            float b = stack.top();
            stack.pop();
            stack.push(eval(a, b, rpn.front()[0]));
        }
        rpn.pop();
    }

    out = stack.top();

    return 0;
}