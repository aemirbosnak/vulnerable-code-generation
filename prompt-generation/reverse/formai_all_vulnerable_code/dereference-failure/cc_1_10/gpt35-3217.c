//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if user input server hostname and port number
    if (argc != 3) {
        printf("Usage: %s <server_hostname> <server_port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a TCP socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error creating socket!\n");
        exit(1);
    }

    // Get server IP address from hostname
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Error resolving hostname!\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to the IMAP server
    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server!\n");
        exit(1);
    }

    // Receive server greeting
    char response[MAX_SIZE];
    recv(socket_fd, response, MAX_SIZE, 0);
    printf("%s", response);

    // Send login command to the server
    char login_cmd[MAX_SIZE] = "LOGIN username password\n";
    send(socket_fd, login_cmd, strlen(login_cmd), 0);

    // Receive server response to the login command
    recv(socket_fd, response, MAX_SIZE, 0);
    printf("%s", response);

    // Send select command to the server
    char select_cmd[MAX_SIZE] = "SELECT INBOX\n";
    send(socket_fd, select_cmd, strlen(select_cmd), 0);

    // Receive server response to the select command
    recv(socket_fd, response, MAX_SIZE, 0);
    printf("%s", response);

    // Send fetch command to the server
    char fetch_cmd[MAX_SIZE] = "FETCH 1 BODY[TEXT]\n";
    send(socket_fd, fetch_cmd, strlen(fetch_cmd), 0);

    // Receive server response to the fetch command
    recv(socket_fd, response, MAX_SIZE, 0);
    printf("%s", response);

    // Close the TCP socket
    close(socket_fd);

    return 0;
}