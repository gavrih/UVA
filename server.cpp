// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include "server.hpp"
#include "data_simulator.hpp"

//#define PORT 5400
int server_fd, new_socket, valread, counter;
char buffer[1024] = {0};
server *server::instance = 0;
server *server::get_instance()
{

	if (!instance)
	{
		instance = new server();
	}
	return instance;
}
std::vector<double> server::Splite_line(std::string line)
{
	std::vector<double> values;
	std::string word = " ";
	
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == ',')
		{
			values.push_back(std::stod(word));
			word = " ";
		}

		else
		{
			word.push_back(line[i]);
		}
		// values.push_back(std::stod(word));
	}
	return values;
};
void server::openServer(int port)
{
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char *hello = (char *)"Hello from server";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 5400
	if (setsockopt(server_fd, SOL_SOCKET,
				   SO_REUSEADDR | SO_REUSEPORT, &opt,
				   sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	// Forcefully attaching socket to the port 5400
	if (bind(server_fd, (struct sockaddr *)&address,
			 sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
							 (socklen_t *)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	std::thread th(server::get_instance()->read_data);
	th.detach();
}
void server::read_data()
{

	while (1)
	{

		valread = read(new_socket, buffer, 1024);
		std::vector<double> values = server::get_instance()->Splite_line(buffer);
		for (int i = 0; i < values.size(); i++)
		{
			data_simulator::get_instance()->simulator_table[server::get_instance()->paths[i]] = values[i];
		}

	}
};


