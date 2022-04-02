
NAME 			=	libunit
NAME_DBG 		=	libunit_d

# Config
# ****************************************************************************

SHELL 		=	/bin/bash
CC 			=	gcc

CFLAGS		=	-Wall -Wextra $(INCLUDE)
DBFLAGS		=	$(CFLAGS) -g3 -fsanitize=address

INCLUDE		=	-Iincludes -Ilibft

# Source files
# ****************************************************************************

SRCSDIR		=	src
LIBUNIT		=	launch_tests.c load_test.c

LIBFT		=	libft
#LinkLists
LINKLISTDIR	=	link_list
LINKLIST	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c				\
				ft_lstsize.c ft_lstlast.c ft_lstmap.c ft_lstnew.c
#IO
IODIR		=	io
IO			=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_get_next_line.c			\
				ft_putchar.c ft_puts.c ft_putnbr.c ft_putstr.c ft_print_matrix.c
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

#DEPENDS		=	$(SRCS:.o=.d)

TESTDIR		=	tests
TESTSRC		=	strlen/00_launcher.c

# Recipe
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

all: 		$(NAME)

$(NAME):	$(OBJS)
	@printf "$(_BLUE)\nCompiled debug source files\n"
	@ar -rcs $(NAME) $(OBJS)
	@printf "$(_GREEN)Finish compiling $(NAMED)!$(_END)\n"

clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@rm -rf $(OBJSDIR) $(OBJSDIRD)
	@rm -rf *.dSYM

fclean:		clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@rm -rf $(NAME) $(NAMED)

re:			fclean all

test:

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

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
