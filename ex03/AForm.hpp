
#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                is_signed;
        const int           grade_To_Sign;
        const int           grade_To_Execute;
    public:
        AForm();
        AForm(const std::string& name, int grade_To_Sign, int grade_To_Execute);
        AForm(const AForm& other);
        AForm&    operator=(const AForm& other);
        virtual ~AForm();


        void            beSigned(const Bureaucrat& b);
        virtual void    execute(Bureaucrat const & executor) const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                const char*  what() const throw();
        };

};

std::ostream&       operator<<(std::ostream& os, const AForm& f);

#endif