//Falcon-180B DATASET v1.0 Category: Networking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, BUF_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        recv(sockfd, buffer, BUF_SIZE, 0);
        printf("Received message: %s", buffer);
    }

    close(sockfd);
    return 0;
}