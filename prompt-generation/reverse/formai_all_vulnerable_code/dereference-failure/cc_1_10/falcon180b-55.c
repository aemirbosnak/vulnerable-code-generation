//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define SERVER_PORT 8080

int main() {
    int sockfd, newsockfd, portno, clilen, ret, sd;
    char buffer[MAX_LINE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    puts("Socket created");

    // Set the reuse address option
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Connect to the server
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    puts("Connected to the server");

    // Create a new socket
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    puts("New socket created");

    // Set the reuse address option
    opt = 1;
    setsockopt(newsockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Read from the client
    ret = read(newsockfd, buffer, MAX_LINE);
    if (ret < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    puts("Received data from the client");

    // Write to the client
    ret = write(newsockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    puts("Data sent to the client");

    // Close the socket
    close(newsockfd);

    puts("Socket closed");

    return 0;
}