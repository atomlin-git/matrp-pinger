#include "../includes/headers.hpp"

sockaddr_in Request::returnSocketAddr(std::string address, unsigned short port)
{
	struct sockaddr_in sock{};

	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);
    sock.sin_addr.s_addr = inet_addr(address.c_str());

	return sock;
}

SOCKET Request::createSocketConnection(std::string address, unsigned short port, unsigned long timeout)
{
	WSADATA wsaData{};
	DWORD TOGGLE = 1;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET SOCKET_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (SOCKET_ == INVALID_SOCKET)
		exit(1);

	if (ioctlsocket(SOCKET_, FIONBIO, &TOGGLE) == INVALID_SOCKET)
		exit(2);

	return SOCKET_;
}