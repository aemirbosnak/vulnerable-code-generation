//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int addrlen, n;

    if(argc < 3) {
        printf("Usage:./client_server <IP address> <port number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        error_handling("Error creating socket");
    }

    printf("Socket created\n");

    // Set server address
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        error_handling("Error getting host by name");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error connecting to server");
    }

    printf("Connected to server\n");

    // Receive data from server
    while(1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);
        if(n < 0) {
            error_handling("Error reading from server");
        }
        printf("Received message from server: %s\n", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}