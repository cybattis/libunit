
NAME			=	real_tester
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

STRLEN_DIR		=	ft_strlen
SRC_STRLEN		=	00_ft_strlen_launcher.c 01_ft_strlen_basic_test.c 02_ft_strlen_null_test.c						\
					03_ft_strlen_big_string_test.c
TEST_STRLEN		=	$(addprefix $(STRLEN_DIR)/, $(SRC_STRLEN))

ATOI_DIR		=	ft_atoi
SRC_ATOI		=	00_ft_atoi_launcher.c 01_ft_atoi_basic_test.c 02_ft_atoi_minus_sign.c 03_ft_atoi_plus_sign.c	\
					04_ft_atoi_multi_minus_sign.c 05_ft_atoi_with_space.c 06_ft_atoi_with_space_and_sign.c
TEST_ATOI		=	$(addprefix $(ATOI_DIR)/, $(SRC_ATOI))

STRLCAT_DIR		=	ft_strlcat
SRC_STRLCAT		=	00_ft_strlcat_launcher.c 01_ft_strlcat_null_test.c 02_ft_strlcat_null_test_2.c					\
					03_ft_strlcat_null_test_3.c 04_ft_strlcat_basic_test.c 05_ft_strlcat_long_dst_test.c			\
					06_ft_strlcat_long_src_test.c 07_ft_strlcat_size_test.c 08_ft_strlcat_size_test_2.c
TEST_STRLCAT	=	$(addprefix $(STRLCAT_DIR)/, $(SRC_STRLCAT))

TEST_SRCS		=	$(addprefix $(SRCDIR)/, main.c)					\
					$(addprefix $(SRCDIR)/, $(TEST_STRLEN))			\
					$(addprefix $(SRCDIR)/, $(TEST_ATOI))			\
					$(addprefix $(SRCDIR)/, $(TEST_STRLCAT))

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
