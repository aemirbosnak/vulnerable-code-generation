//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {

    // Check if argument count is correct
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket is correctly created
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Extract server name and port number
    char *server_name = argv[1];
    int port_number = atoi(argv[2]);

    // Get server details from the name using getaddrinfo
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(server_name, argv[2], &hints, &servinfo);

    if (status != 0) {
        perror("getaddrinfo failed");
        exit(1);
    }

    // Try each possible address until successfully connected
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }
        break;
    }

    // Check if successful connection has been established
    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    // Free memory used by server details
    freeaddrinfo(servinfo);

    // HTTP GET request
    char message[BUFSIZE];
    snprintf(message, BUFSIZE, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", server_name);

    // Send the message to the server
    send(sockfd, message, strlen(message), 0);

    // Receive the response from the server
    int recv_len = 0;
    char response[BUFSIZE];

    while ((recv_len = recv(sockfd, response, BUFSIZE, 0)) > 0) {
        printf("%.*s", recv_len, response);
    }

    // Close the socket
    close(sockfd);

    return 0;
}