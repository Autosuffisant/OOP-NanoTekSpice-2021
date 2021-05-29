/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCY-4-1-tekspice-aurelien.schulz [WSL: Ubuntu-20.04]
** File description:
** Component
*/

#include "../include/Circuit.hpp"

nts::Component::Component(std::string type)
{
    this->_type = type;
    return;
}

nts::Component::~Component()
{
    return;
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::cout << pin << ":" << otherPin << std::endl;
    return;
}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    return nts::Tristate::UNDEFINED;
}

void nts::Component::simulate(std::size_t tick)
{
    return;
}

void nts::Component::dump() const
{
    return;
}

std::unique_ptr<nts::IComponent> nts::Circuit::createFalse() const noexcept
{
    //std::cout << "Created false" << std::endl;
    return std::make_unique<nts::False>("False");
}

nts::False::False(std::string type) : Component(type)
{
    this->pins.push_back(std::pair<size_t, nts::Tristate>(1, nts::Tristate::UNDEFINED));
}

std::unique_ptr<nts::IComponent> nts::Circuit::createTrue() const noexcept
{
    //std::cout << "Created true" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::createOutput() const noexcept
{
    //std::cout << "Created Output" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::createInput() const noexcept
{
    //std::cout << "Created Input" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create2716() const noexcept
{
    //std::cout << "Created 2716" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4001() const noexcept
{
    //std::cout << "Created 4001" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4008() const noexcept
{
    //std::cout << "Created 4008" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4011() const noexcept
{
    //std::cout << "Created 4011" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4013() const noexcept
{
    //std::cout << "Created 4013" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4030() const noexcept
{
    //std::cout << "Created 4030" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4040() const noexcept
{
    //std::cout << "Created 4040" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4069() const noexcept
{
    //std::cout << "Created 4069" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4071() const noexcept
{
    //std::cout << "Created 4071" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4081() const noexcept
{
    //std::cout << "Created 4081" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4094() const noexcept
{
    //std::cout << "Created 4094" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4512() const noexcept
{
    //std::cout << "Created 4512" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4514() const noexcept
{
    //std::cout << "Created 4514" << std::endl;
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Circuit::create4801() const noexcept
{
    //std::cout << "Created 4801" << std::endl;
    return nullptr;
}
