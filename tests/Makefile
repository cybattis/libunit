
NAME		=	tester

LIBUNIT		=	libunit.a

# Config
# ****************************************************************************

SHELL 		=	/bin/bash
CC 			=	gcc

CFLAGS		=	-Wall -Wextra -MD $(INCLUDE)
DBFLAGS		=	$(CFLAGS) -g3 -fsanitize=address

INCLUDE		=	-I../includes -I../libft -Iincludes

# Source files
# ****************************************************************************

TESTDIR		=	src
TEST_STRLEN	=	strlen/00_launcher.c strlen/01_basic_test.c main.c

TEST_SRCS	=	$(addprefix $(TESTDIR)/, $(TEST_STRLEN))

OBJDIR_TEST	=	objt
OBJSTEST	=	$(addprefix $(OBJDIR_TEST)/, $(notdir $(TEST_SRCS:.c=.o)))

$(OBJDIR_TEST)/%.o:	$(TESTDIR)/%.c | $(OBJDIR_TEST)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJDIR_TEST)/%.o:	$(TESTDIR)/*/%.c | $(OBJDIR_TEST)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

all: 		$(NAME)

$(NAME):	$(OBJSTEST)
	@$(CC) $(CFLAGS) $(OBJSTEST) ../$(LIBUNIT) -o $(NAME)

# Action
# ****************************************************************************

clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@rm -rf $(OBJDIR_TEST)
	@rm -rf *.dSYM

fclean:		clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@rm -rf $(NAME)

re:		fclean all

$(OBJDIR_TEST):
	@mkdir -p $(OBJDIR_TEST)

.PHONY: all clean fclean re debug libft test

# Misc
# =====================

print-%:	; @echo $* = $($*)

# Colors
# ****************************************************************************

_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

# ****************************************************************************
