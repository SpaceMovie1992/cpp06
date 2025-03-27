NAME = identify
CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g3
INCLUDES = -I ./inc

SRCS = $(wildcard src/*.cpp)

OBJDIR = objs
SRCDIR = src

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

.SILENT:

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	echo $(GREEN) "Building $(NAME)"$(DEFAULT);

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

fclean: clean
	rm -f $(NAME)
	echo $(RED)"Removing $(NAME)"$(DEFAULT);

re: fclean all
	echo $(GREEN)"Rebuilding everything"$(DEFAULT)

.PHONY: all clean fclean re

# Colors
DEFAULT = "\033[39m"
GREEN = "\033[0;32m"
RED = "\033[0;31m"