SOURCES = src/hashing.c \
		  src/linked_list.c \
		  src/hash_table.c

CFLAGS = -Wall -Wextra -Werror -O3

all:
	mkdir lib || true;
	gcc -shared -fPIC ${CFLAGS} ${SOURCES} -o lib/libmylib.so

