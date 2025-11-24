NAME = Maggots

C = c++
CPPFLAGS= -Wall -Wextra -Werror  -std=c++98

SRCS= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
HEADER= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp  PresidentialPardonForm.hpp Intern.hpp

all:$(NAME)
$(NAME) : $(SRCS) $(HEADER)
	$(C) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re:  fclean all