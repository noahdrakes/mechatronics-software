#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

using namespace std; 

#define RX_BYTECOUNT    1024

int main(int argc, char *argv[]) {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(server_socket, 1);

    std::cout << "Server listening..." << std::endl;

    int client_socket = accept(server_socket, NULL, NULL);
    
    uint8_t buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);

    std::cout << "Received data: " << buffer[5] << std::endl;

    close(server_socket);
    close(client_socket);

    return 0;
}
