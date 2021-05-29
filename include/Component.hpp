/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#ifndef NTS_COMPONENT_
#define NTS_COMPONENT_

#include "IComponent.hpp"

namespace nts
{
    //Logic gate expected to be put insude a Component class
    class Gate
    {
    };

    //Generic component class, which holds logic gate, links and pins
    class Component : public nts::IComponent
    {
    public:
        Component(std::string);
        ~Component();

        //Simulate one tick of the component
        void simulate(std::size_t tick);

        //Compute once
        nts::Tristate compute(std::size_t pin);

        //Link the indicated pin of the component to an indicated pin of another component
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        //Display the component's current tick and the value of all inputs and outputs
        void display();

        //Get the type of the component, it can be regular or one of the special types, check the chipType
        std::string getType();

    protected:
        unsigned int _id;
        std::string _type;
        std::size_t tick;

        //List of pins, each being an input or output pin
        std::vector<std::pair<std::size_t, nts::Tristate>> pins;

        //List of links inside the component, a link holds a pair indicating what it links
        std::map<std::unique_ptr<pinType>, std::unique_ptr<pinType>> internalLinks;

        //List of links linking to other components, a link holds a pair indicating what it links
        std::map<std::unique_ptr<pinType>, std::unique_ptr<pinType>> externalLinks;
    };

    class False : public nts::Component {
        public:
            False(std::string);
    };
}

#endif /* !NTS_COMPONENT_ */
