/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#ifndef NTS_PARSER_
#define NTS_PARSER_

#include "Circuit.hpp"

class Parser {
    public:
        ~Parser();

        //Creates a component and adds it to a given circuit based on a .nts file
        void addComponent(std::string file, nts::Circuit& circuit);
};

#endif /* !NTS_PARSER_ */
