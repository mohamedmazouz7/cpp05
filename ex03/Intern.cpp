#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other) {}
    return *this;
}

static AForm*  createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static  AForm*  createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

static  AForm*  createPresidontial(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(std::string name, std::string target)
{
    std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm*  (*makers[3])(std::string) = {createShrubbery, createRobotomy, createPresidontial};

    for (int i = 0; i < 3; i++)
    {
        if (form[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return makers[i](target);
        }
    }
    std::cout << "Error: form '" << name << "' does not exist." << std::endl;
    return NULL;
}


Intern::~Intern() {}