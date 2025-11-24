#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
   
    AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
    
    if (shrubbery)
        delete shrubbery;
    
    AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotomy)
        delete robotomy;

    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (pardon)
        delete pardon;
    
    AForm* unknown = someRandomIntern.makeForm("ice cream application", "Dessert");
    if (unknown)
        delete unknown;
    return 0;
}