#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , target("default_T") {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!GetIs_Signed())
        throw FormNotSignedException();
    if (executor.GetGrade() > GetExecuteGrade())
        throw GradeTooLowException();
    
    std::ofstream Myfile((target + "_shrubbery").c_str());
    Myfile << "      /\\      " << std::endl
           << "     /**\\     " << std::endl
           << "    /****\\    " << std::endl
           << "   /******\\   " << std::endl
           << "  /********\\  " << std::endl
           << "      ||       " << std::endl;
    Myfile.close();
}