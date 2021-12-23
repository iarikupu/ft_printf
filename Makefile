NAME = libftprintf.a

AR = ar
ARFLAGS = crs

RM = rm
RMFLAG = -f

INCLUDES = ./ft_printf.h

SRCS= \
	./ft_printf.c	\
	./ft_printf_utils.c	\
	./ft_atoi.c \
	./ft_char.c	\
	./ft_string.c	\
	./ft_int.c	\
	./ft_unsigned.c	\
	./ft_hex.c	\
	./ft_pointer.c	\
	./num_share.c	\
	./shared.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

bonus : all

re:		fclean all
.PHONY: all clean fclean re

