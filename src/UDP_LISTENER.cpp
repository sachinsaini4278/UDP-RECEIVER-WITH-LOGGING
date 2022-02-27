
#include "UDP_LISTENER.h"
#include "logging/NanoLog.hpp"
void UnicastReceiver::initializerUDP(std::string _ip, int16_t _port, bool console_logging, bool file_logging)
{
	this->ip = _ip;
	this->port = _port;
	this->isConsoleLogging = console_logging;
	this->isFileLogging = file_logging;	
	std::cout << "IP	:" << this->ip << std::endl;
	std::cout << "Port	:" << this->port << std::endl;
	std::cout << "Console Logging:" << this->isConsoleLogging << std::endl;
	std::cout << "File Logging	 :" << this->isFileLogging << std::endl;
	UDPSocket();
}

void UnicastReceiver::UDPSocket()
{
	struct sockaddr_in clientAddress,serverAddr; //A sockaddr_in is a structure containing an internet address. This structure is defined in netinet/in.h.
	socklen_t clientAddressLength; 
	
	/**
	* The socket() system call creates a new socket.It takes three arguments.The first is the address domain of the socket. AF_INET for IPv4/ AF_INET6 for IPv6
	* The second argument is the type of socket. (SOCK_DGRAM: UDP, SOCK_STREAM: TCP)
	* The third argument is the protocol. If this argument is zero (and it always should be except for unusual circumstances), the operating system will choose the most appropriate protocol. It will choose TCP for stream sockets and UDP for datagram sockets.
	* Return Value: The socket system call returns an entry into the file descriptor table (i.e. a small integer). This value is used for all subsequent references to this socket. If the socket call fails, it returns -1.
	*/
	int socketFileDescripter = socket(AF_INET, SOCK_DGRAM, 0);
	if (socketFileDescripter == -1)
	{
		perror("Socket creation Failed");
		return;
	}
	memset(&clientAddress, 0, sizeof(clientAddress));
	//Filling Server information
	serverAddr.sin_family = AF_INET; // IPv4
	//servaddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());
	serverAddr.sin_port = htons(port);
	
	if (bind(socketFileDescripter, (const struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
	{
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}
	clientAddressLength = sizeof(clientAddress);
	//Reading Infinitly
	while (1)
	{
		memset(data_, 0, max_length);
		size_t received = recvfrom(socketFileDescripter,data_,sizeof(data_), 0, (struct sockaddr*)&clientAddress, &clientAddressLength);
		std::cout << data_ << std::endl;
		if(isConsoleLogging)
		{
		}
		if (isFileLogging)
		{
			LOG_INFO << "[RCVD]" << data_;
		}
	}
}