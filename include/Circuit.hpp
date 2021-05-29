/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#ifndef NTS_CIRCUIT_
#define NTS_CIRCUIT_

#include "Component.hpp"
#include "Interpreter.hpp"
#include <map>

//A NTS circuit which holds components
namespace nts {
    class Circuit {
        public:
            Circuit();
            ~Circuit();

            Interpreter interpreter;
            void interpretFunction(const std::string);

            //Interpreter functions
            void simulate();
            void display() const;

            //Create component
            std::unique_ptr<nts::IComponent> createComponent(const std::string& type);
            void getCircuitDataFromFile(std::vector<std::string> fileContent);
            void createComponentsFromFile(std::vector<std::string> fileContent);
            void linkComponentsFromFile(std::vector<std::string> fileContent);

            //Simulate for a single every component
            void run();

            //Repeats the run member function until the loop ceases
            void loop();

            //Getters
            //Get elapsed ticks
            size_t getTick() const { return this->tick; };

            //Printers
            void printInputs() const;
            void printOutputs() const;

            //Function pointer typedef
            typedef std::unique_ptr<IComponent> (Circuit::*fptr)() const;

        private:
            std::unique_ptr<IComponent> createFalse() const noexcept;
            std::unique_ptr<IComponent> createTrue() const noexcept;
            std::unique_ptr<IComponent> createOutput() const noexcept;
            std::unique_ptr<IComponent> createInput() const noexcept;
            std::unique_ptr<IComponent> create2716() const noexcept;
            std::unique_ptr<IComponent> create4001() const noexcept;
            std::unique_ptr<IComponent> create4008() const noexcept;
            std::unique_ptr<IComponent> create4011() const noexcept;
            std::unique_ptr<IComponent> create4013() const noexcept;
            std::unique_ptr<IComponent> create4030() const noexcept;
            std::unique_ptr<IComponent> create4040() const noexcept;
            std::unique_ptr<IComponent> create4069() const noexcept;
            std::unique_ptr<IComponent> create4071() const noexcept;
            std::unique_ptr<IComponent> create4081() const noexcept;
            std::unique_ptr<IComponent> create4094() const noexcept;
            std::unique_ptr<IComponent> create4512() const noexcept;
            std::unique_ptr<IComponent> create4514() const noexcept;
            std::unique_ptr<IComponent> create4801() const noexcept;

        protected:
            //Number of ticks elapsed since the beginning of the simulation
            std::size_t tick;
            //List of the components inside the circuit
            std::map<std::string, std::unique_ptr<nts::IComponent>> CircuitComponents;
            //Map holding function pointers to construct each components
            std::map<std::string, fptr> ComponentConstructor;
    };
}

#endif /* !NTS_CIRCUIT_ */
