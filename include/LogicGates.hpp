/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#ifndef NTS_LOGICGATES_
#define NTS_LOGICGATES_

#include "Component.hpp"

namespace LogicGate {
    nts::Tristate And(nts::Tristate first, nts::Tristate second);
    nts::Tristate Or(nts::Tristate first, nts::Tristate second);
    nts::Tristate Nor(nts::Tristate first, nts::Tristate second);
    nts::Tristate Xor(nts::Tristate first, nts::Tristate second);
    nts::Tristate Nand(nts::Tristate first, nts::Tristate second);
    nts::Tristate Xnor(nts::Tristate first, nts::Tristate second);
    nts::Tristate Not(nts::Tristate first);
};

#endif /* !NTS_LOGICGATES_ */
