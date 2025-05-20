//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Declarations
    int client_socket;
    struct sockaddr_in server_address;
    char *host, *port;
    char buffer[1024];

    // Usage check
    if (argc != 3)
    {
        printf("Usage: %s <host> <port>", argv[0]);
        return 1;
    }

    // Grab host and port
    host = argv[1];
    port = argv[2];

    // Establish the connection
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("Socket creation failed!");
        return 1;
    }

    // Fill server address
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0)
    {
        printf("Invalid host address: %s", host);
        return 1;
    }

    // Fire the gun!
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed!");
        return 1;
    }

    // Fire off a ping message
    strcpy(buffer, "PING");
    send(client_socket, buffer, strlen(buffer), 0);

    // Wait for response
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Mission accomplished!
    close(client_socket);
    printf("Ping test complete.");

    return 0;
}