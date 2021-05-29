/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
**  Digital electronic simulator
*/

#include "../include/Circuit.hpp"
#include "../include/NtsExceptions.hpp"

nts::Circuit::Circuit()
{
    this->tick = 0;
    ComponentConstructor["false"] = &nts::Circuit::createFalse;
    ComponentConstructor["true"] = &nts::Circuit::createTrue;
    ComponentConstructor["output"] = &nts::Circuit::createOutput;
    ComponentConstructor["input"] = &nts::Circuit::createInput;
    ComponentConstructor["2716"] = &nts::Circuit::create2716;
    ComponentConstructor["4001"] = &nts::Circuit::create4001;
    ComponentConstructor["4008"] = &nts::Circuit::create4008;
    ComponentConstructor["4011"] = &nts::Circuit::create4011;
    ComponentConstructor["4013"] = &nts::Circuit::create4013;
    ComponentConstructor["4030"] = &nts::Circuit::create4030;
    ComponentConstructor["4040"] = &nts::Circuit::create4040;
    ComponentConstructor["4069"] = &nts::Circuit::create4069;
    ComponentConstructor["4071"] = &nts::Circuit::create4071;
    ComponentConstructor["4081"] = &nts::Circuit::create4081;
    ComponentConstructor["4094"] = &nts::Circuit::create4094;
    ComponentConstructor["4512"] = &nts::Circuit::create4512;
    ComponentConstructor["4514"] = &nts::Circuit::create4514;
    ComponentConstructor["4801"] = &nts::Circuit::create4801;
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::interpretFunction(const std::string input)
{
    if (input == "simulate")
        this->simulate();
    if (input == "display")
        this->display();
}

void nts::Circuit::display() const
{
    std::cout << "tick: " << this->getTick() << std::endl;
    std::cout << "input(s):" << std::endl;
    this->printInputs();
    std::cout << "output(s):" << std::endl;
    this->printOutputs();
}

void nts::Circuit::simulate()
{
    std::cout << "Simulating..." << std::endl;
    this->tick++;
    return;
}

void nts::Circuit::printInputs() const
{
    return;
}

void nts::Circuit::printOutputs() const
{
    return;
}

void nts::Circuit::getCircuitDataFromFile(std::vector<std::string> fileContent)
{
    std::string currentLine;
    std::vector<std::string> clearedFile;

    for (std::vector<std::string>::iterator fileIt = fileContent.begin(); fileIt != fileContent.end(); fileIt++) {
        currentLine = *fileIt;
        if (currentLine[0] != '#' && !currentLine.empty()) {
            clearedFile.push_back(currentLine);
        }
    }
    this->createComponentsFromFile(clearedFile);
}

void nts::Circuit::createComponentsFromFile(std::vector<std::string> fileContent)
{
    std::vector<std::string>::iterator it = fileContent.begin();
    std::string currentLine;
    std::string componentType = "";
    std::string componentName = "";
    std::string::iterator currentLineIt;

    //std::cout << *it << std::endl;
    if (*it != ".chipsets:")
        throw nts::exception("No chipset inside file");
    it++;
    while (it != fileContent.end() && *it != ".links:") {
        currentLine = *it;
        for (currentLineIt = currentLine.begin(); currentLineIt != currentLine.end() && *currentLineIt != ' '; currentLineIt++)
            componentType += *currentLineIt;
        //std::cout << "Component type is :" << componentType << std::endl;
        //Raise exception here
        if (currentLineIt == currentLine.end())
            throw nts::exception("Component information missing");
        while (*currentLineIt == ' ' && currentLineIt != currentLine.end())
            currentLineIt++;
        for (;currentLineIt != currentLine.end(); currentLineIt++)
            componentName += *currentLineIt;
        it++;
        //std::cout << "Component name is: " << componentName << std::endl;
        fptr ptr = ComponentConstructor[componentType];
        if (!ptr)
            throw nts::exception("One of the component type does not exist");
        this->CircuitComponents.insert(std::pair<std::string, std::unique_ptr<IComponent>>
        (componentName, (this->*ptr)()));
        componentType.clear();
        componentName.clear();
    }
    if (this->CircuitComponents.empty())
        throw nts::exception("No component were given");

    std::vector<std::string> linksContent;
    for (;it != fileContent.end() && *it != ".links:"; it++);
    for (;it != fileContent.end(); it++)
        linksContent.push_back(*it);
    if (linksContent.empty())
        throw nts::exception("No links were given");
    this->linkComponentsFromFile(linksContent);
}

void nts::Circuit::linkComponentsFromFile(std::vector<std::string> fileContent)
{
    auto fileIt = fileContent.begin();
    std::string currentLine;
    std::string firstName;
    std::string secondName;
    size_t firstPin;
    size_t secondPin;
    std::string buffer;

    if (*fileIt != ".links:")
        throw nts::exception("Wrong file syntax");
    fileIt++;
    for (; fileIt != fileContent.end(); fileIt++) {
        currentLine = *fileIt;
        auto currentLineIt = currentLine.begin();
        for (; currentLineIt != currentLine.end() && *currentLineIt != ':'; currentLineIt++)
            firstName += *currentLineIt;
        if (currentLineIt == currentLine.end())
            throw nts::exception("Missing pin information in .links: section");
        currentLineIt++;
        for (; currentLineIt != currentLine.end() && *currentLineIt != ' '; currentLineIt++)
            buffer += *currentLineIt;
        if (currentLineIt == currentLine.end())
            throw nts::exception("Second linked pin to " + firstName + "is missing");
        firstPin = std::stoi(buffer);
        if (this->CircuitComponents.find(firstName) == this->CircuitComponents.end())
            throw nts::exception("Link can't be done " + firstName + " doesn't exist");

        for (; currentLineIt != currentLine.end() && *currentLineIt == ' '; currentLineIt++);
        if (currentLineIt == currentLine.end())
            throw nts::exception("Second linked pin to " + firstName + "is missing");

        for (; currentLineIt != currentLine.end() && *currentLineIt != ':'; currentLineIt++)
            secondName += *currentLineIt;
        if (currentLineIt == currentLine.end())
            throw nts::exception("Missing pin information in .links: section");
        currentLineIt++;
        buffer.clear();
        for (; currentLineIt != currentLine.end() && *currentLineIt != ' '; currentLineIt++)
            buffer += *currentLineIt;
        secondPin = std::stoi(buffer);
        CircuitComponents.find(firstName)->second->setLink(firstPin,
        *this->CircuitComponents.find(secondName)->second.get(), secondPin);
    }
}