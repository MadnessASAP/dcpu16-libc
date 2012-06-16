CFLAGS = -O -g -Wall -Iinclude -S -target dcpu16

CC = clang
AS = dcpu16-as
AR = dcpu16-ar

S_SRCS = libc/string/memmove.s \
	libc/string/memcpy.s

C_SRCS = libc/stdlib/malloc.c \
	libc/stdlib/realloc.c \
	libc/string/string.c \
	libc/dcpu.c \
	libc/stdio/putchar.c \
	libc/stdio/puts.c \
	libc/stdio/initconsole.c \
	libc/stdio/itoa.c

S_PRODUCED = $(C_SRCS:.c=.s)

OBJS = $(C_SRCS:.c=.o) $(S_SRCS:.s=.o)

libc.a: $(OBJS)
	$(AR) rs libc.a $(OBJS)

$(S_PRODUCED): %.s: %.c
	$(CC) -o $@ $< $(CFLAGS)

$(OBJS): %.o: %.s
	$(AS) -o $@ $<

clean:
	rm -f $(OBJS) $(S_PRODUCED) libc.a
