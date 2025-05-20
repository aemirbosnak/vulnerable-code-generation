//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <ctype.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    struct addrinfo hints, *result, *rp;
    char hostname[1024];
    int sockfd, numbytes;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    printf("Enter the SMTP server hostname: ");
    scanf("%s", hostname);

    if ((numbytes = getaddrinfo(hostname, NULL, &hints, &result))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(numbytes));
        exit(1);
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    freeaddrinfo(result);

    printf("Connected to SMTP server.\n");

    while (1) {
        printf("Enter your command: ");
        fgets(sendbuffer, BUFFER_SIZE, stdin);

        if (strcasecmp(sendbuffer, "QUIT") == 0) {
            break;
        }

        numbytes = send(sockfd, sendbuffer, strlen(sendbuffer), 0);

        if (numbytes == -1) {
            perror("send");
            exit(1);
        }

        memset(recvbuffer, 0, BUFFER_SIZE);
        numbytes = recv(sockfd, recvbuffer, BUFFER_SIZE, 0);

        if (numbytes == -1) {
            perror("recv");
            exit(1);
        }

        printf("Server response: %s", recvbuffer);
    }

    close(sockfd);
    return 0;
}