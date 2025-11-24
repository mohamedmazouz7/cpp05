NAME = Maggots

C = c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS= main.cpp Bureaucrat.cpp Form.cpp 
HEADER= Bureaucrat.hpp Form.hpp

all:$(NAME)
$(NAME) : $(SRCS) $(HEADER)
	$(C) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re:  fclean all