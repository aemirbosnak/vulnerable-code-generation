//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_socket, port_number, client_socket, bytes_received;
    struct sockaddr_in server_address, client_address;
    int opt = 1;

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address structure
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, 5);

    // Accept a connection
    port_number = atoi(argv[1]);
    printf("Server listening on port %d...\n", port_number);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&bytes_received);
        if (client_socket == -1) {
            perror("ERROR on accepting");
            exit(1);
        }

        // Receive data from the client
        bzero((char *)&server_address, sizeof(server_address));
        bzero((char *)&client_address, sizeof(client_address));
        char buffer[256];
        memset(buffer, 0, 256);

        bytes_received = recv(client_socket, buffer, 255, 0);
        if (bytes_received == -1) {
            perror("ERROR receiving data");
            exit(1);
        }

        // Send data back to the client
        send(client_socket, buffer, bytes_received, 0);
        close(client_socket);
    }

    return 0;
}