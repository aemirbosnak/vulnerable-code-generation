//Falcon-180B DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[4096];
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket created\n");

    // Set the port number
    portno = 8080;

    // Set the IP address
    strcpy(buffer, "127.0.0.1");

    // Convert IP address from string to binary form
    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("No such host\n");
        exit(EXIT_FAILURE);
    }

    // Fill serv_addr structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Receive data from server
    clilen = sizeof(cli_addr);
    if (getsockname(sockfd, (struct sockaddr *)&cli_addr, &clilen) < 0) {
        perror("getsockname");
        exit(EXIT_FAILURE);
    }
    printf("Client IP address: %s\n", inet_ntoa(cli_addr.sin_addr));

    // Receive data from server
    while (1) {
        bzero(buffer, 4096);
        read(sockfd, buffer, 4096);
        printf("Received data: %s\n", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}