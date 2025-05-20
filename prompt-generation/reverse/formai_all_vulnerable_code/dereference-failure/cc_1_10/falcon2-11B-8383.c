//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

int send_message(int socket_fd, const char *message) {
    int n = write(socket_fd, message, strlen(message));
    if (n < 0) {
        perror("Error sending message");
        return -1;
    }
    return 0;
}

int recv_message(int socket_fd, char *buffer, int max_size) {
    int n = read(socket_fd, buffer, max_size);
    if (n < 0) {
        perror("Error receiving message");
        return -1;
    }
    return n;
}

int main() {
    int socket_fd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to address
    if (bind(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(socket_fd, 5);
    printf("Listening for connections...\n");

    // Accept incoming connection
    portno = accept(socket_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
    if (portno < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    printf("Connection from %s port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    // Send email
    send_message(portno, "Welcome to C Email Client!");

    // Receive email
    char buffer[256];
    int size = recv_message(portno, buffer, sizeof(buffer));
    if (size < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", buffer);

    // Close connection
    close(portno);

    return 0;
}