#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), is_signed(false), grade_To_Sign(10), grade_To_Execute(4) {}

AForm::AForm(const std::string& name, int grade_To_Sign, int grade_To_Execute) : name(name), grade_To_Sign(grade_To_Sign), grade_To_Execute(grade_To_Execute)
{
    if (grade_To_Sign < 1 || grade_To_Execute < 1)
        throw GradeTooHighException();
    if (grade_To_Sign > 150 || grade_To_Execute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), is_signed(other.is_signed) ,grade_To_Sign(other.grade_To_Sign), grade_To_Execute(other.grade_To_Execute) {}

AForm&       AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

AForm::~AForm() {};

void    AForm::beSigned(const Bureaucrat& b)
{
    if (b.GetGrade() <= grade_To_Sign)
        is_signed = true;
    else
        throw GradeTooLowException();
}

std::string    AForm::GetName() const
{
    return name;
}

bool    AForm::GetIs_Signed() const
{
    return is_signed;
}

int   AForm::GetSignedGrade() const
{
    return grade_To_Sign;
}

int   AForm::GetExecuteGrade() const
{
    return grade_To_Execute;
}


const char*     AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const   char*   AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const   char*   AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream&   operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm: " << f.GetName()
    << ", signed: " << std::boolalpha << f.GetIs_Signed()
    << ", grade required to sign: " << f.GetSignedGrade()
    << ", grade required to execute: " << f.GetExecuteGrade();
    return os;
}