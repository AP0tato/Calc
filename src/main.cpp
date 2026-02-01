#include "calc.hpp"
#include "alg.hpp"
#include <string>
#include <fstream>
#include <iostream>

int evaluateExpression(std::string inputFileStr, std::string outputFileStr);
int evaluateEquation(std::string inputFileStr, std::string outputFileStr);

int main(int argc, char const *argv[])
{
    std::string inputFile = "in.txt", outputFile = "out.txt";
    evaluateEquation(inputFile, outputFile);

    return 0;
}

int evaluateEquation(std::string inputFileStr, std::string outputFileStr)
{
    Alg *a = new Alg();
    std::string line;
    std::fstream inputFile(inputFileStr);
    std::ofstream outputFile(outputFileStr);

    if(!inputFile.is_open() || !outputFile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return -1;
    }

    while(std::getline(inputFile, line))
    {
        float result = 0.0f;
        std::cout << line << std::endl;
        std::vector<std::string> left, right;
        a->splitEquation(line, left, right);
    }
}

int evaluateExpression(std::string inputFileStr, std::string outputFileStr)
{
    Calc *c = new Calc();
    std::string line;
    std::fstream inputFile(inputFileStr);
    std::ofstream outputFile(outputFileStr);

    if(!inputFile.is_open() || !outputFile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return -1;
    }

    while(std::getline(inputFile, line))
    {
        float result = 0.0f;
        std::cout << line << std::endl;
        if(c->evaluateString(line, result) != 0)
        {
            std::cout << "Syntax Error" << std::endl;
            outputFile << "Syntax Error" << std::endl;
        }
        else
        {
            std::cout << result << std::endl;
            outputFile << result << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}