/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#include "../include/Circuit.hpp"
#include "../include/GetFileContent.hpp"
#include "../include/NtsExceptions.hpp"

int main(int ac, char **av)
{
    nts::Circuit circuit;
    std::vector<std::string> fileContent;

    if (ac == 2)
        fileContent = getFileContent(av[1]);
        if (!fileContent.empty()) {
            circuit.getCircuitDataFromFile(fileContent);
        }
    else
        throw nts::exception("File empty or missing");
    while (circuit.interpreter.read() != "exit") {
        circuit.interpretFunction(circuit.interpreter.getLastInput());
    }
    return 0;
}