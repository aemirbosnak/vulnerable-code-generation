//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER "localhost"
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./client username password\n");
        return 1;
    }

    strcpy(sendbuffer, argv[1]);
    strcat(sendbuffer, "\r\n");
    strcat(sendbuffer, argv[2]);
    strcat(sendbuffer, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    if (send(sockfd, sendbuffer, strlen(sendbuffer), 0) < 0) {
        printf("send failed\n");
        exit(1);
    }

    bzero(recvbuffer, BUFFER_SIZE);
    n = recv(sockfd, recvbuffer, BUFFER_SIZE, 0);

    if (n < 0) {
        printf("recv failed\n");
        exit(1);
    }

    printf("Server response: %s\n", recvbuffer);

    close(sockfd);

    return 0;
}