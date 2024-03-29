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
#include "database.hpp"

//#define PORT 5400
int server_fd, new_socket, counter, valread;

Server &Server::get_instance()
{
	static Server instance;
	return instance;
}

// void launchFG() {
//           system("fgfs --telnet=socket,in,10,127.0.0.1,5402,tcp --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small");
// 		  }

void Server::openServer(int port)
{

	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	std::string hello = (char *)"Hello from server";

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

	std::thread th(&Server::read_data, this);
	th.detach();
}

void Server::read_data()
{
	char c;
	std::string buffer;
	while (1)
	{
		bool ok = true;
		c = {0};
		valread = 0;
		buffer.clear();

		while (c != '\n')
		{
			valread = read(new_socket, &c, 1);

			buffer += c;
			if (c < 0)
			{
				ok = false;
				break;
			}
		}

		if (ok)
		{
			std::vector<double> values = splite_line(buffer);
			for (size_t i = 0; i < values.size(); i++)
			{
				DB::get_instance().setData(paths[i], values[i]);
			}
		}
	}
}

std::vector<double> Server::splite_line(const std::string &line)
{
	std::vector<double> values;
	std::string word = " ";

	for (size_t i = 0; i < line.length(); ++i)
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
	}
	return values;
}
