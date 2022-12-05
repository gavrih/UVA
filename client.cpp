// Client side C/C++ program to demonstrate Socket
// 
#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include "client.hpp"


Client& Client::get_instance()
{

	static Client instance;
	return instance;
}

void Client::connecting_client(int port, const char *ip)
{

	struct sockaddr_in serv_addr;
	

	std::string hello = (char *)"ls\r\n";
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	// Convert IPv4 and IPv6 addresses from text to binary
	// form
	if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0)
	{
		printf(
			"\nInvalid address/ Address not supported \n");
		return;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr,
				sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return;
	}
}
void Client::send_to_simulator(const std::string &path, const std::string &value)
{
  std::string send_set = "set " + path + " " + value + "\r\n";
	send(sock, send_set.c_str(), send_set.length(), 0);

	std::cout << send_set << std::endl;
}
