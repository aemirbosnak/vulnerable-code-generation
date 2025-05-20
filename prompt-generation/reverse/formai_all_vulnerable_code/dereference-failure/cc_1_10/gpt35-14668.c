//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // lookup server IP address
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    // zero out the server_addr variable
    bzero((char *) &server_addr, sizeof(server_addr));

    // set server_addr settings
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // connect to the server
    if (connect(sockfd,(struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // send message to server
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "Hello, server!");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message to server");
        exit(1);
    }

    // set up asynchronous event
    fd_set readfds;
    struct timeval timeout;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    // wait for server response in an asynchronous way
    int activity = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (activity < 0) {
        perror("ERROR in selecting socket");
        exit(1);
    } else if (activity == 0) {
        printf("Timeout reached waiting for server response\n");
        exit(1);
    } else {
        // receive and display server's response
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("ERROR receiving message from server");
            exit(1);
        }
        printf("Server response: %s\n", buffer);
    }

    // close the socket
    close(sockfd);
    return 0;
}