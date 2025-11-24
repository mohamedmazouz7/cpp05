#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;


class Bureaucrat
{
    private:
        const std::string name;
        int     grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat&  operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const       std::string&  GetName() const;
        int         GetGrade() const;
        void        incrementGrade();
        void        decrementGrade();

        void    signForm(AForm& f);
        void    executeForm(AForm const &form) const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char*  what() const throw();

        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

std::ostream&    operator<<(std::ostream& os, const Bureaucrat& bure);
#endif