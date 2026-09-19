CC = gcc
CFLAGS = -Wall -I../include
OBJ = ../obj
BIN = ../bin

all: $(BIN)/client

$(BIN)/client: $(OBJ)/main.o $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	$(CC) $(OBJ)/main.o $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o -o $(BIN)/client

$(OBJ)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJ)/main.o

$(OBJ)/mystrfunctions.o: mystrfunctions.c
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $(OBJ)/mystrfunctions.o

$(OBJ)/myfilefunctions.o: myfilefunctions.c
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $(OBJ)/myfilefunctions.o

clean:
	rm -f $(OBJ)/*.o $(BIN)/client
