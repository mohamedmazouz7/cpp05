#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 20);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        john.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\033[33m--------------------------------------\033[0m" << std::endl;
    try
    {
        Bureaucrat Nirou("Nirou", 149);
        std::cout << Nirou << std::endl;

        Nirou.decrementGrade();
        std::cout << "After Decrment Grade: " << Nirou << std::endl;
        
        Nirou.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught with Nirou: " << e.what() << std::endl;
    }

    std::cout << "\033[36m--------------------------------------\033[0m" << std::endl;
    try
    {
        Bureaucrat wrong1("Error1", 0);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception creating wrong1: " << e.what() << std::endl;
    }
    std::cout << "\033[31m--------------------------------------\033[0m" << std::endl;
    try
    {
        Bureaucrat wrong2("Error2", 200);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception creating wrong2: " << e.what() << std::endl;
    }
    return 0;
}