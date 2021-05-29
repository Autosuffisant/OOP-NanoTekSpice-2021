/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital Electronic Simulator
*/

#include "../include/NtsExceptions.hpp"

nts::exception::exception(std::string const &message) : _message(message) {}