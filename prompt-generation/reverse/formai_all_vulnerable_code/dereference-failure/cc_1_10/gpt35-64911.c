//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int client_socket, port_number, status;
    char buffer[MAX_BUFFER];
    struct sockaddr_in server_address;

    if(argc != 3) {
        printf("Usage: %s <ip_address> <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port_number = atoi(argv[2]);

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(client_socket == -1){
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Set server details
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);

    status = inet_pton(AF_INET, argv[1], &server_address.sin_addr);

    if(status == -1){
        perror("Error setting server address");
        exit(EXIT_FAILURE);
    } else if(status == 0){
        printf("Invalid address format\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if(status == -1){
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    const char *http_request = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    send(client_socket, http_request, strlen(http_request), 0);
    
    // Receive HTTP response
    while(recv(client_socket, buffer, MAX_BUFFER, 0) > 0){
        printf("%s", buffer);
    }

    // Close the socket
    close(client_socket);

    return 0;
}