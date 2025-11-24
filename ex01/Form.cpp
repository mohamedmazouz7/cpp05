#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), is_signed(false), grade_To_Sign(10), grade_To_Execute(4) {}

Form::Form(const std::string& name, int grade_To_Sign, int grade_To_Execute) : name(name), grade_To_Sign(grade_To_Sign), grade_To_Execute(grade_To_Execute)
{
    if (grade_To_Sign < 1 || grade_To_Execute < 1)
        throw GradeTooHighException();
    if (grade_To_Sign > 150 || grade_To_Execute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), is_signed(other.is_signed) ,grade_To_Sign(other.grade_To_Sign), grade_To_Execute(other.grade_To_Execute) {}

Form&       Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

Form::~Form() {}

void    Form::beSigned(const Bureaucrat& b)
{
    if (b.GetGrade() <= grade_To_Sign)
        is_signed = true;
    else
        throw GradeTooLowException();
}

std::string    Form::GetName() const
{
    return name;
}

bool    Form::GetIs_Signed() const
{
    return is_signed;
}

int   Form::GetSignedGrade() const
{
    return grade_To_Sign;
}

int   Form::GetExecuteGrade() const
{
    return grade_To_Execute;
}


const char*     Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const   char*   Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}


std::ostream&   operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.GetName()
    << ", signed: " << std::boolalpha << f.GetIs_Signed()
    << ", grade required to sign: " << f.GetSignedGrade()
    << ", grade required to execute: " << f.GetExecuteGrade();
    return os;
}