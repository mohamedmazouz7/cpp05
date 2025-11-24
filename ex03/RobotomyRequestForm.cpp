#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!GetIs_Signed())
        throw FormNotSignedException();
    if (executor.GetGrade() > GetExecuteGrade())
        throw GradeTooLowException();
    
    std::cout << "* Drilling noises... BZZZZZT *" << std::endl;
    if (rand() % 2 == 0)
        std::cout << target << " has been rebotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}