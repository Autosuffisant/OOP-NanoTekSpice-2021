/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#include "../include/LogicGates.hpp"


nts::Tristate LogicGate::And(nts::Tristate first, nts::Tristate second)
{
	if (first == nts::Tristate::TRUE && second == nts::Tristate::TRUE)
		return nts::Tristate::TRUE;
	else if (first == nts::Tristate::FALSE || second == nts::Tristate::FALSE)
		return nts::Tristate::FALSE;
	return nts::Tristate::UNDEFINED;
}

nts::Tristate LogicGate::Or(nts::Tristate first, nts::Tristate second)
{
	if (first == nts::Tristate::TRUE || second == nts::Tristate::TRUE)
		return nts::Tristate::TRUE;
	else if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
		return nts::Tristate::UNDEFINED;
	return nts::Tristate::FALSE;
}

nts::Tristate LogicGate::Nor(nts::Tristate first, nts::Tristate second)
{
	return Not(Or(first, second));
}

nts::Tristate LogicGate::Xor(nts::Tristate first, nts::Tristate second)
{
	if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
		return nts::Tristate::UNDEFINED;
	else if (first != second)
		return nts::Tristate::TRUE;
	return nts::Tristate::FALSE;
}

nts::Tristate LogicGate::Nand(nts::Tristate first, nts::Tristate second)
{
	return Not(And(first, second));
}

nts::Tristate LogicGate::Xnor(nts::Tristate first, nts::Tristate second)
{
	return Not(Xor(first, second));
}

nts::Tristate LogicGate::Not(nts::Tristate first)
{
	if (first == nts::Tristate::TRUE)
		return nts::Tristate::FALSE;
	else if (first == nts::Tristate::FALSE)
		return nts::Tristate::TRUE;
	return nts::Tristate::UNDEFINED;
}