
CC=gcc
CF=-Wall -Wextra -pedantic -g -std=iso9899:1999

BIND=../bin
BINS=$(addprefix $(BIND)/, $(patsubst %.c, %.o, $(wildcard *.c)))

OUT=clipedia

all: $(BIND) $(BINS) $(OUT)

$(BIND):
	mkdir $(BIND)

$(OUT): $(BINS)
	$(CC) $(BINS) -o $(OUT) $(CF)

$(BIND)/%.o: %.c
	$(CC) $(CF) -c $< -o $@

clean:
	rm -rf $(wildcard *.o) bins
	rm $(OUT)
