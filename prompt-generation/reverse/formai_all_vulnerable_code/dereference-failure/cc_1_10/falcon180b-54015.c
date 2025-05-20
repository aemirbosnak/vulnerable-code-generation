//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recv_len;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting\n");
        exit(0);
    }

    while (1) {
        bzero(buffer, MAX);
        recv_len = recv(sockfd, buffer, MAX, 0);
        if (recv_len <= 0) {
            printf("Disconnected\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}