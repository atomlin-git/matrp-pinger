#pragma once

#ifdef _WIN32
    #include <winsock.h>
    #pragma comment (lib, "ws2_32.lib")
#elif
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#endif

#include "request.hpp"