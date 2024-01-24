#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>

using namespace std;


int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    inet_pton(AF_INET, "169.254.255.254", &server_address.sin_addr);
    // hello

    // int i = 3;
    // i += 3;

    

    connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    const char* message = "Hello, server!";
    send(client_socket, message, strlen(message), 0);

    close(client_socket);

    cout << "are we here " << endl;

    return 0;
}

