#Makefile to compile tetris program
CFLAGS = -Wall -Iinclude -g -Isrc
CC = g++
INCLUDE = include
SRC = src
BUILD = build
BIN = bin

$(BIN)/TEST: $(BUILD)/Main.o $(BUILD)/Tblock.o $(BUILD)/Board_template.o $(BUILD)/Interface.o
	$(CC) $(CFLAGS) $(BUILD)/Main.o $(BUILD)/Tblock.o $(BUILD)/Board_template.o $(BUILD)/Interface.o -o $(BIN)/TEST

$(BUILD)/Main.o: $(SRC)/Main.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Board_template.hpp $(INCLUDE)/Tblock.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Main.cpp -o $(BUILD)/Main.o

$(BUILD)/Tblock.o: $(SRC)/Tblock.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Tblock.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Tblock.cpp -o $(BUILD)/Tblock.o

$(BUILD)/Board_template.o: $(SRC)/Board_template.cpp $(INCLUDE)/Board_template.hpp $(INCLUDE)/Tblock.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Board_template.cpp -o $(BUILD)/Board_template.o

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/PROGRAM
	rm -f $(BIN)/TEST
	rm -f $(BIN)/PROGRAM

PROGRAM: $(BUILD)/Mainu.o $(BUILD)/Tblock.o $(BUILD)/Board_template.o $(BUILD)/Interface.o
	$(CC) $(CFLAGS) $(BUILD)/Mainu.o $(BUILD)/Tblock.o $(BUILD)/Board_template.o $(BUILD)/Interface.o -o $(BIN)/PROGRAM

$(BUILD)/Interface.o: $(SRC)/Interface.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Tblock.hpp $(INCLUDE)/Interface.hpp $(INCLUDE)/Board_template.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Interface.cpp -o $(BUILD)/Interface.o	

$(BUILD)/Mainu.o:$(SRC)/Main.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Board_template.hpp $(INCLUDE)/Tblock.hpp
	$(CC) -Duser=1 $(CFLAGS) -c $(SRC)/Main.cpp -o $(BUILD)/Mainu.o

