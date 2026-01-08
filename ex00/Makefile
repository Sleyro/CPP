NAME    = megaphone
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS    = megaphone.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
