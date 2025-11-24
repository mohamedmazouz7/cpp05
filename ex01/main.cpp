#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat Nirou("Nirou", 50);
        Form taxForm("TaxForm", 40, 30);

        std::cout << Nirou << std::endl;
        std::cout << taxForm << std::endl;

        Nirou.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat bob("Bob", 20);
        std::cout << bob << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}