#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
class AForm;

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);
};

#endif