CC = gcc
CFLAGS = -Wall -I../include
OBJ = ../obj
BIN = ../bin
LIB = ../lib

all: $(BIN)/client_static

$(BIN)/client_static: $(OBJ)/main.o $(LIB)/libmyutils.a
	$(CC) $(OBJ)/main.o -L$(LIB) -lmyutils -o $(BIN)/client_static

$(LIB)/libmyutils.a: $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	ar rc $(LIB)/libmyutils.a $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	ranlib $(LIB)/libmyutils.a

$(OBJ)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJ)/main.o

$(OBJ)/mystrfunctions.o: mystrfunctions.c
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $(OBJ)/mystrfunctions.o

$(OBJ)/myfilefunctions.o: myfilefunctions.c
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $(OBJ)/myfilefunctions.o

clean:
	rm -f $(OBJ)/*.o $(LIB)/libmyutils.a $(BIN)/client_static
