#ifndef UDP_LISTENER
#define UDP_LISTENER


#include <iostream>
#include <sys/types.h> //This header file contains definitions of a number of data types used in system calls. These types are used in the next two include files.
#include <sys/socket.h> //The header file socket.h includes a number of definitions of structures needed for sockets.
#include <netinet/in.h> //The header file in.h contains constants and structures needed for internet domain addresses.
#include <arpa/inet.h>
#include <cstring>
class UnicastReceiver 
{
public:	
	void initializerUDP(std::string,int16_t,bool,bool);
	void UDPSocket();
	void readData(char* data, size_t size);

private:
	
	std::string ip;
	int16_t port;
	enum { max_length = 1024 };
	char data_[max_length];
	bool isConsoleLogging = false;
	bool isFileLogging = false;
};





#endif // !_UDP_LISTENER


