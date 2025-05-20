//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
// A Chat Application using TCP/IP Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    
    if(argc != 3) {
        printf("Usage: %s <ip> <port>", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create Socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up Server Address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to Server
    connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    char buffer[BUFFER_SIZE];

    // Receive Message from Server
    recv(network_socket, &buffer, sizeof(buffer), 0);
    printf("Connected to Server! Message from Server: %s\n", buffer);

    while(1) {
        
        // Send Message to Server
        printf("Enter Message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(network_socket, buffer, strlen(buffer), 0);

        // Receive Reply from Server
        memset(buffer, 0, sizeof(buffer));
        recv(network_socket, &buffer, sizeof(buffer), 0);

        // Check for Exit Command
        if(strncmp(buffer, "EXIT", strlen("EXIT")) == 0) {
            printf("Server Closed Connection. Exiting...\n");
            break;
        }

        printf("Server Reply: %s", buffer);

    }

    // Close Socket
    close(network_socket);
    return 0;

}