
NAME 			=	libunit.a

# Config
# ****************************************************************************

SHELL 		=	/bin/bash
CC 			=	gcc

CFLAGS		=	-Wall -Wextra -MD $(INCLUDE)
DBFLAGS		=	$(CFLAGS) -g3 -fsanitize=address

INCLUDE		=	-Iframework/includes -Ilibft

# Source files
# ****************************************************************************

SRCSDIR		=	framework/src
LIBUNIT		=	launch_tests.c launch_tests_utils.c launch_tests_logs.c load_test.c

LIBFT		=	libft
#LinkLists
LINKLISTDIR	=	link_list
LINKLIST	=	ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstsize.c ft_lstnew.c

#IO
IODIR		=	io
IO			=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar.c ft_puts.c		\
				ft_putnbr.c ft_putstr.c
#Printf
PRINTFDIR	=	io/printf
PRINTF		=	ft_printf.c conv_func.c conv_func2.c get_flags.c print_flags.c print_flags2.c				\
				utils.c
#Memory
MEMORYDIR	=	memory
MEMORY		=	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c						\
				ft_memmove.c ft_memset.c mem_utils.c
#C strings
CSTRINGSDIR	=	strings/
CSTRINGS	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c		\
 				ft_split.c ft_strchr.c ft_strichr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c		\
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c	\
				ft_substr.c ft_tolower.c ft_toupper.c ft_strndup.c ft_strnrev.c ft_strrev.c ft_atol.c		\
				ft_nbrlen.c ft_isspace.c ft_atoi_base.c ft_strtoupper.c ft_strtolower.c

SRCS		=	$(addprefix $(SRCSDIR)/, $(LIBUNIT))		\
				$(addprefix $(LINKLISTDIR)/, $(LINKLIST))	\
				$(addprefix $(IODIR)/, $(IO)) 				\
				$(addprefix $(PRINTFDIR)/, $(PRINTF)) 		\
				$(addprefix $(MEMORYDIR)/, $(MEMORY)) 		\
				$(addprefix $(CSTRINGSDIR)/, $(CSTRINGS)) 	\
				$(addprefix $(SRCSDIR)/, $(LIBUNIT)) 		\

OBJSDIR		=	obj
OBJS		=	$(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))

# Libunit
# ****************************************************************************

$(OBJSDIR)/%.o:	$(SRCSDIR)/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJSDIR)/%.o:	$(LIBFT)/*/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJSDIR)/%.o:	$(LIBFT)/*/*/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

all:	header	$(NAME)

$(NAME):	$(OBJS)
	@printf "$(_BLUE)\nCompiled libunit source files\n"
	@ar -rcs $(NAME) $(OBJS)
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

clean:
	@printf "$(_YELLOW)Removing object files for libunit...$(_END)\n"
	@rm -rf $(OBJSDIR) $(OBJSDIRD) $(OBJDIR_TEST)
	@rm -rf *.dSYM
	@$(MAKE) -C tests clean
	@$(MAKE) -C real_test clean
	@$(MAKE) -C bonus clean

fclean:		clean
	@printf "$(_RED)Removing libunit static lib file...$(_END)\n"
	@rm -rf $(NAME) $(NAMED) $(TESTER)
	@$(MAKE) -C tests fclean
	@$(MAKE) -C real_test fclean
	@$(MAKE) -C bonus fclean

re:		fclean all

test:		all
	@$(MAKE) -j4 -C tests -r -R --warn-undefined-variables
	@printf "\n=========== Launching framwork test suite ============\n\n"
	@./tests/tester

real_test:	all
	@$(MAKE) -j4 -C real_test -r -R --warn-undefined-variables
	@printf "\n=========== Launching real test suite ============\n\n"
	@./real_test/real_tester

bonus:		all
	@$(MAKE) -j4 -C bonus -r -R --warn-undefined-variables
	@printf "\n=========== Launching bonus suite ============\n\n"
	@./bonus/bonus_tester

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

.PHONY: all clean fclean re debug libft test run-test

# Misc
# =====================

print-%:	; @echo $* = $($*)

header:
	@printf "\n"
	@printf "$(_YELLOW)\t __       ______ _______  __    __ __    __ ______ ________  $(_END)\n"
	@printf "$(_YELLOW)\t|  \     |      \       \|  \  |  \  \  |  \      \        \ $(_END)\n"
	@printf "$(_YELLOW)\t| ▓▓      \▓▓▓▓▓▓ ▓▓▓▓▓▓▓\ ▓▓  | ▓▓ ▓▓\ | ▓▓\▓▓▓▓▓▓\▓▓▓▓▓▓▓▓ $(_END)\n"
	@printf "$(_YELLOW)\t| ▓▓       | ▓▓ | ▓▓__/ ▓▓ ▓▓  | ▓▓ ▓▓▓\| ▓▓ | ▓▓    | ▓▓    $(_END)\n"
	@printf "$(_YELLOW)\t| ▓▓       | ▓▓ | ▓▓    ▓▓ ▓▓  | ▓▓ ▓▓▓▓\ ▓▓ | ▓▓    | ▓▓    $(_END)\n"
	@printf "$(_YELLOW)\t| ▓▓       | ▓▓ | ▓▓▓▓▓▓▓\ ▓▓  | ▓▓ ▓▓\▓▓ ▓▓ | ▓▓    | ▓▓    $(_END)\n"
	@printf "$(_YELLOW)\t| ▓▓_____ _| ▓▓_| ▓▓__/ ▓▓ ▓▓__/ ▓▓ ▓▓ \▓▓▓▓_| ▓▓_   | ▓▓    $(_END)\n"
	@printf "$(_YELLOW)\t| ▓▓     \   ▓▓ \ ▓▓    ▓▓\▓▓    ▓▓ ▓▓  \▓▓▓   ▓▓ \  | ▓▓    $(_END)\n"
	@printf "$(_YELLOW)\t \▓▓▓▓▓▓▓▓\▓▓▓▓▓▓\▓▓▓▓▓▓▓  \▓▓▓▓▓▓ \▓▓   \▓▓\▓▓▓▓▓▓   \▓▓    $(_END)\n"
	@printf "\n"

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
