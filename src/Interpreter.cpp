/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
**  Digital electronic simulator
*/

#include "../include/Interpreter.hpp"

Interpreter::Interpreter()
{
}

Interpreter::~Interpreter()
{
}

std::string Interpreter::read()
{
    std::string input;

    std::cout << "> ";
    getline(std::cin, input);
    this->logs.push_back(input);
    return input;
}

std::string Interpreter::getLastInput() const
{
    return this->logs.back();
}