
NAME			=	bonus_tester
LIBUNIT			=	libunit.a

# Config
# ****************************************************************************

SHELL 			=	/bin/bash
CC 				=	gcc

CFLAGS			=	-Wall -Wextra -MD $(INCLUDE)

INCLUDE			=	-I../framework/includes -I../libft -I includes

# Source files
# ****************************************************************************

SRCDIR			=	src

COLOR_DIR		=	print_color
SRC_COLOR		=	00_print_color_launcher.c 01_print_ok_test.c 02_print_ko_test.c		\
					03_print_sig_test.c
TEST_COLOR		=	$(addprefix $(COLOR_DIR)/, $(SRC_COLOR))

PUTSTR_DIR		=	ft_putstr_fd
SRC_PUTSTR		=	00_ft_putstr_fd_launcher.c 01_ft_putstr_fd_basic_test.c
TEST_PUTSTR		=	$(addprefix $(PUTSTR_DIR)/, $(SRC_PUTSTR))

TIMEOUT_DIR		=	timeout
SRC_TIMEOUT		=	00_timeout_launcher.c 01_timeout_test.c
TEST_TIMEOUT		=	$(addprefix $(TIMEOUT_DIR)/, $(SRC_TIMEOUT))

SIGNAL_DIR		=	signal
SRC_SIGNAL		=	00_sig_launcher.c 01_sigabort_test.c 02_sigfpe_test.c 03_sigpipe_test.c	\
					04_sigill_test.c
TEST_SIGNAL		=	$(addprefix $(SIGNAL_DIR)/, $(SRC_SIGNAL))

TEST_SRCS		=	$(addprefix $(SRCDIR)/, main.c)					\
					$(addprefix $(SRCDIR)/, $(TEST_COLOR))			\
					$(addprefix $(SRCDIR)/, $(TEST_PUTSTR))			\
					$(addprefix $(SRCDIR)/, $(TEST_TIMEOUT))		\
					$(addprefix $(SRCDIR)/, $(TEST_SIGNAL))

OBJDIR_TEST		=	objt
OBJSTEST		=	$(addprefix $(OBJDIR_TEST)/, $(notdir $(TEST_SRCS:.c=.o)))

$(OBJDIR_TEST)/%.o:	$(SRCDIR)/%.c | $(OBJDIR_TEST)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJDIR_TEST)/%.o:	$(SRCDIR)/*/%.c | $(OBJDIR_TEST)
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
