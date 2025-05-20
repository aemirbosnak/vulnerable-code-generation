//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1025];
    int n;

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket failed\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(0);
    }

    // Connect to remote server
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: connect failed\n");
        exit(0);
    }

    printf("Connected to server\n");

    // Receive messages from server
    while (1) {
        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            printf("Error: read failed\n");
            exit(0);
        }
        printf("Received message: %s\n", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}