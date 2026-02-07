CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = static_oop
SRCS = cat.c dog.c static_oop.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
