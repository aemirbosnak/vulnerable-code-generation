//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char message[] = "USER john\r\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("pop3.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    memcpy((char*)&serveraddr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    n = write(sockfd, message, sizeof(message));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Received response: %s\n", buffer);

    close(sockfd);
    return 0;
}