//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct hostent *host;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get host by name
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: host not found\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr *) host->h_addr);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Receive banner from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        printf("Error: failed to receive banner\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send user credentials
    printf("User: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(client_socket, buffer, strlen(buffer), 0);

    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(client_socket, buffer, strlen(buffer), 0);

    // Check for authentication failure
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (strstr(buffer, "-ERR") != NULL) {
        printf("Error: authentication failed\n");
        exit(EXIT_FAILURE);
    }

    // Retrieve message count
    printf("\n");
    send(client_socket, "STAT\r\n", 6, 0);
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    // Quit connection
    send(client_socket, "QUIT\r\n", 6, 0);
    close(client_socket);

    return 0;
}