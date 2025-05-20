//Falcon-180B DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int maxfd;
    fd_set readfds;
    char *message;

    // Initialize the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    puts("Socket created");

    // Set the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    puts("Connected to server");

    // Initialize the buffer
    memset(buffer, 0, BUFFER_SIZE);

    // Send a request to the server
    if (send(sockfd, "GET / HTTP/1.1\r\n", strlen("GET / HTTP/1.1\r\n"), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    puts("Request sent");

    // Initialize the read set
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    // Receive a response from the server
    if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0) {
        perror("select failed");
        exit(EXIT_FAILURE);
    }

    if (FD_ISSET(sockfd, &readfds)) {
        // Read the response
        if ((message = malloc(BUFFER_SIZE)) == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }

        if ((addrlen = recv(sockfd, message, BUFFER_SIZE, 0)) < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        printf("Received response:\n%s\n", message);
    }

    free(message);
    close(sockfd);

    return 0;
}