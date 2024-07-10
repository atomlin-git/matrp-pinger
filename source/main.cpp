#include "../includes/headers.hpp"

unsigned char data[400] = { 0 };
unsigned char to_send[400] = { 0 };
unsigned char matreshka_secret[58] = {0x72, 0xD6, 0x47, 0xF9, 0x6A, 0x6E, 0xAE, 0x33, 0x2E, 0x06, 0x22, 0x1D, 0x48, 0xF5, 0x77, 0xCC, 0x4C, 0xC9, 0x50, 0xA6, 0x6F, 0xD2, 0x2D, 0x28, 0x7D, 0x40, 0x94, 0x7E, 0xF3, 0x60, 0x96, 0x30, 0x71, 0x98, 0x1E, 0xDA, 0xA3, 0xD7, 0xA8, 0x11, 0x20, 0x58, 0xD6, 0x4B, 0xF9, 0x24, 0xA6, 0xF5, 0x52, 0xBD, 0x2A, 0x95, 0x06, 0xA7, 0x11, 0x12, 0x66, 0x43};

request req = { };

int main(int, char**)
{
    req.send((unsigned char[400])"MCRH3110", 400);

    struct sockaddr_in from_addr = { 0 };
    int fromlen = sizeof(from_addr);

    while (true) {
        if(recvfrom(req.get_sock(), (char*)data, 400, 0, (sockaddr*)&from_addr, &fromlen) == 8) {
            memcpy(&to_send, &data[4], 4);
            memcpy(&to_send[4], matreshka_secret, sizeof(matreshka_secret));

            unsigned int first = req.encrypt((unsigned char*)to_send, 62, 0);
            unsigned int second = req.encrypt((unsigned char*)to_send, 4, first);

            memcpy(&to_send, "MCRR", 4);
            memcpy(&to_send[4], &data[4], 4);

            *(unsigned int*)&to_send[8] = first;
            *(unsigned int*)&to_send[12] = second;

            req.send(to_send, 400);
            req.~request();
            break;
        };
    };
    return 1;
}
