#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(0));

    try
    {
        Bureaucrat Nirou("Nirou", 1);

        std::cout << "\033[33m----mShrubbery----\033[0m" << std::endl;
        ShrubberyCreationForm shrub("home");
        Nirou.signForm(shrub);
        Nirou.executeForm(shrub);

        std::cout << std::endl;

        std::cout << "\033[34m----Robotomy----\033[0m" << std::endl;
        RobotomyRequestForm robot("Bender");
        Nirou.signForm(robot);
        Nirou.executeForm(robot);

        std::cout << std::endl;

        std::cout << "\033[31m----Presidential Pardon----\033[0m" << std::endl;
        PresidentialPardonForm pardon("Michael Scofield");
        Nirou.signForm(pardon);
        Nirou.executeForm(pardon);

    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}