//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 4096

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <server-ip> <server-port>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    char buffer[MAX_BUFFER];
    int bytes_received;
    char command[MAX_BUFFER];

    printf("IMAP Client\n");

    recv(client_socket, buffer, MAX_BUFFER, 0); // receive the welcome message
    printf("%s", buffer);

    // Send the login command 
    printf("> ");
    fgets(command, MAX_BUFFER, stdin);
    sprintf(buffer, "%s", command);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive the response
    bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send the list command
    sprintf(buffer, "list\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive the response
    bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send the select command
    printf("> ");
    fgets(command, MAX_BUFFER, stdin);
    sprintf(buffer, "%s", command);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive the response
    bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send the fetch command
    printf("> ");
    fgets(command, MAX_BUFFER, stdin);
    sprintf(buffer, "%s", command);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive the response
    bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send the logout command
    sprintf(buffer, "logout\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive the bye message
    bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    close(client_socket);

    return 0;
}