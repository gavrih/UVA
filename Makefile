CC   = g++
TARGET = main.o parser.o lexer.o command.o server.o client.o database.o tools.o ShuntingYardToken.o

# OBJS = main.cpp parser.cpp lexer.cpp command.cpp server.cpp client.cpp database.cpp tools.cpp ShuntingYardToken.cpp 
CFLAGS = -std=c++17 -Wall -pedantic -c
main:   $(TARGET)
	$(CC) -o main $(TARGET) -pthread

main.o: main.cpp parser.cpp lexer.cpp
		$(CC)  $(CFLAGS) main.cpp			

parser.o: parser.cpp lexer.cpp
		$(CC) $(CFLAGS) parser.cpp

lexer.o: lexer.cpp
		$(CC) $(CFLAGS) lexer.cpp 

command.o: command.cpp parser.cpp server.cpp client.cpp database.cpp ShuntingYardToken.cpp tools.cpp
		$(CC) $(CFLAGS) command.cpp

server.o: server.cpp  database.cpp 
		$(CC) $(CFLAGS) server.cpp -pthread

tools.o: tools.cpp
		$(CC) $(CFLAGS) tools.cpp

client.o: client.cpp
		$(CC) $(CFLAGS) client.cpp

database.o: database.cpp
		$(CC) $(CFLAGS) database.cpp
ShuntingYardToken.o: ShuntingYardToken.cpp
		$(CC) $(CFLAGS) ShuntingYardToken.cpp


clean:
		rm *.o main