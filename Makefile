NAME := Yonmoku
CXX :=clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDE := -I./includes

SRCDIR := ./srcs/
SRCNAME := main.cpp \
		   Board.cpp \
		   Player.cpp \
		   Master.cpp \

SRCS := $(addprefix $(SRCDIR),$(SRCNAME))
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

RM := rm -rf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -MMD -MP  -o $@ $<

-include $(DEPS)
.PHONY: clean
clean:
	$(RM) *.dSYM
	$(RM) $(OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
# debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: CXXFLAGS += -g
debug: re
