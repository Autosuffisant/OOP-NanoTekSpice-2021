/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#include "../include/GetFileContent.hpp"

std::vector<std::string> getFileContent(std::string fileName)
{
    std::vector<std::string> fileContent;
    std::string line;
    std::ifstream file(fileName, std::ios::in);
    char output = 0;

    if (!file.is_open())
        return fileContent;
    while(file.get(output)) {
        if (output == '\n') {
            fileContent.push_back(line);
            line.clear();
        } else
            line += output;
    }
    return fileContent;
}

