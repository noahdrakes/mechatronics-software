#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>

using namespace std;

#define TX_BYTECOUNT    1024

// NOTE:
// HOST_IP_ADDRESS = "169.254.255.252"
// PS IP ADDRESS    (ETH1) = "169.254.10.0"
//                  (ETH2) = "169.254.9.0"        

int main(int argc, char *argv[]) {

    if (argc < 2){
        cout << "Error: need to pass IP address as an arguement" << endl;
        return 0;
    }

    const char* ipAddress = argv[1];

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    inet_pton(AF_INET, ipAddress, &server_address.sin_addr);

    uint8_t randomBytes[TX_BYTECOUNT];


    for (int i = 1; i < TX_BYTECOUNT; i++){
        randomBytes[i] = i ;
    }
    
    connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
 
    send(client_socket, randomBytes, sizeof(randomBytes), 0);

    close(client_socket);

    return 0;
}

