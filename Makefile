NAME = pathfinder

INC = pathfinder.h

INCI = inc/pathfinder.h

SRC = main.c\
	mx_file_to_str.c\
	mx_split.c\
	mx_parser.c\
	mx_atoi.c\
	mx_printerr.c\
	mx_rec_struct.c\
	mx_isdigit.c\
	mx_get_index.c\
	mx_m_distance.c\
	mx_floyd.c

SRCS = $(addprefix src/, main.c\
	mx_file_to_str.c\
	mx_split.c\
	mx_parser.c\
	mx_atoi.c\
	mx_printerr.c\
	mx_rec_struct.c\
	mx_isdigit.c\
	mx_get_index.c\
	mx_m_distance.c\
	mx_floyd.c)

OBJ = main.o\
	mx_file_to_str.o\
	mx_split.o\
	mx_parser.o\
	mx_atoi.o\
	mx_printerr.o\
    mx_rec_struct.o\
    mx_isdigit.o\
    mx_get_index.o\
    mx_m_distance.o\
    mx_floyd.o

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
