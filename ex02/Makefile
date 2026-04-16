NAME = account

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(DEBUG), 1)
    CXXFLAGS += -g -O0 -fsanitize=address
else
    CXXFLAGS += -O2
endif

SRC += Account.cpp
SRC += tests.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Account.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f *.gch

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re
