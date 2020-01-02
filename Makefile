NAME = pathfinder

INC = pathfinder.h

INCI = inc/pathfinder.h

SRC = main.c\
	mx_file_to_str.c\
	mx_split.c\

SRCS = $(addprefix src/, main.c\
	mx_file_to_str.c\
	mx_split.c)

OBJ = main.o\
	mx_file_to_str.o\
	mx_split.o\

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C libmx
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@mkdir -p obj
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mv $(OBJ) ./obj

uninstall:
	@make uninstall -C libmx
	@rm -rf $(NAME)

clean:
	@make clean -C libmx
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf $(OBJ)
	@rm -rf ./obj
reinstall: uninstall all
