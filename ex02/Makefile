NAME    = account
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS    = tests.cpp Account.cpp
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
