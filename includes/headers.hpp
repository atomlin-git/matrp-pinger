#pragma once

#ifdef _WIN32
    #include <winsock.h>
    #pragma comment (lib, "ws2_32.lib")
    typedef int socklen_t;
#elif __linux__
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <cstring>
#endif

#include "request.hpp"