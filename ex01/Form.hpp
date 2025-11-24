
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                is_signed;
        const int           grade_To_Sign;
        const int           grade_To_Execute;
    public:
        Form();
        Form(const std::string& name, int grade_To_Sign, int grade_To_Execute);
        Form(const Form& other);
        Form&    operator=(const Form& other);
        ~Form();


        void            beSigned(const Bureaucrat& b);

        std::string       GetName() const;
        bool              GetIs_Signed() const;
        int               GetSignedGrade()const ;
        int               GetExecuteGrade() const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char*  what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char*  what() const throw();
        };

};

std::ostream&       operator<<(std::ostream& os, const Form& f);

#endif