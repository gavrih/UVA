CC   = g++
OBJS = main.cpp parser.cpp lexer.cpp command.cpp server.cpp client.cpp data_simulator.cpp
CFLAGS = -pthread
main:   $(OBJS)
	$(CC) -o main $(OBJS) $(CFLAGS)
