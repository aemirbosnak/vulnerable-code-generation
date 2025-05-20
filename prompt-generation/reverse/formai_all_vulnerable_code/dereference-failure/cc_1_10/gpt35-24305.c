//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXSIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAXSIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host.\n");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server.");
    }

    printf("Connected to FTP server.\n");
    printf("Enter FTP command: ");

    while (fgets(buffer, MAXSIZE, stdin) != NULL) {
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("Error writing to socket.");
        }

        memset(buffer, 0, MAXSIZE);
        n = read(sockfd, buffer, MAXSIZE-1);
        if (n < 0) {
            error("Error reading from socket.");
        }

        printf("%s\n", buffer);
        printf("Enter FTP command: ");
    }

    close(sockfd);
    return 0;
}