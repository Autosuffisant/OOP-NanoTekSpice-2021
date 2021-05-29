/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#ifndef NTS_INTERPRETER_
#define NTS_INTERPRETER_

#include <iostream>
#include <string>
#include <vector>

class Interpreter {
    public:
        Interpreter();
        ~Interpreter();

        std::string read();

        std::string getLastInput() const;
        std::vector<std::string> getLogs() const;
    protected:
    private:
        std::vector<std::string> logs;
};

#endif /* !NTS_INTERPRETER_ */
