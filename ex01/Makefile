SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = ffix

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re