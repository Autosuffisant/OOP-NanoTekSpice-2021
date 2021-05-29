/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Digital electronic simulator
*/

#ifndef NTS_EXCEPTIONS_
#define NTS_EXCEPTIONS_

#include <string>

namespace nts {
    class exception : public std::exception {
        public:
            exception(std::string const &message);

            const char *what() const noexcept { return _message.c_str(); }
        private:
            std::string _message;
    };
}

#endif /* !NTS_EXCEPTIONS_ */
