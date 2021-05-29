/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#ifndef NTS_ICOMPONENT_
#define NTS_ICOMPONENT_

#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    enum pinType
    {
        INPUT,
        OUTPUT
    };

    class IComponent
    {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const = 0;
    };
} // namespace nts

#endif /* !NTS_ICOMPONENT_ */
