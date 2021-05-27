NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s	\

OBJ	= $(SRCS:.s=.o)

OBJS	= $(addprefix $(OBJDIR), $(OBJ))

OBJDIR	= objs/

FLAGS_ASM	= nasm -f macho64

FLAGS	= -Wall -Wextra -Werror


$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)


$(OBJDIR)%.o:	%.s Makefile
				@mkdir -p $(OBJDIR)
				$(FLAGS_ASM) $< -o $@

all:		$(NAME)

clean:
			rm -rf $(OBJDIR)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

.PHONY:	fclean clean re all


