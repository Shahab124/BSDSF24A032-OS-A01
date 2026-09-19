CC = gcc
CFLAGS = -Wall -fPIC -I../include
OBJ = ../obj
BIN = ../bin
LIB = ../lib

all: $(BIN)/client_static $(BIN)/client_dynamic

$(BIN)/client_static: $(OBJ)/main.o $(LIB)/libmyutils.a
	$(CC) -static $(OBJ)/main.o $(LIB)/libmyutils.a -o $(BIN)/client_static

$(BIN)/client_dynamic: $(OBJ)/main.o $(LIB)/libmyutils.so
	$(CC) $(OBJ)/main.o -L$(LIB) -lmyutils -o $(BIN)/client_dynamic

$(LIB)/libmyutils.a: $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	ar rc $(LIB)/libmyutils.a $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	ranlib $(LIB)/libmyutils.a

$(LIB)/libmyutils.so: $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
	$(CC) -shared $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o -o $(LIB)/libmyutils.so

$(OBJ)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJ)/main.o

$(OBJ)/mystrfunctions.o: mystrfunctions.c
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $(OBJ)/mystrfunctions.o

$(OBJ)/myfilefunctions.o: myfilefunctions.c
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $(OBJ)/myfilefunctions.o

clean:
	rm -f $(OBJ)/*.o $(LIB)/libmyutils.a $(LIB)/libmyutils.so $(BIN)/client_static $(BIN)/client_dynamic
