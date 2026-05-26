CC = gcc

CFLAGS = -Wall -Wextra -g

SRC_DIR = src
BIN_DIR = bin

SERVER = $(BIN_DIR)/server
CLIENT = $(BIN_DIR)/client

all: directories $(SERVER) $(CLIENT)

directories:
	mkdir -p $(BIN_DIR)

$(SERVER): $(SRC_DIR)/server.c
	$(CC) $(CFLAGS) $< -o $@

$(CLIENT): $(SRC_DIR)/client.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)

run-server:
	./$(SERVER)

run-client:
	./$(CLIENT)

.PHONY: all clean run-server run-client directories
