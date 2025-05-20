//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
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

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int addrlen, n;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));

        if (n < 0) {
            perror("read failed");
            exit(1);
        }

        buffer[n] = '\0';
        printf("Received from server: %s\n", buffer);

        if (n == 0) {
            break;
        }
    }

    close(sockfd);
    exit(0);
}