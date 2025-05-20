//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in servaddr;
    char sendbuffer[BUFFER_SIZE], recvbuffer[BUFFER_SIZE];

    if(argc!= 4) {
        printf("Usage:./ftp_client <IP address> <Username> <Password>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        printf("Error in socket creation\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(PORT);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error in connecting\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, argv[2], strlen(argv[2]), 0);
    send(sockfd, argv[3], strlen(argv[3]), 0);

    memset(recvbuffer, 0, BUFFER_SIZE);
    recv(sockfd, recvbuffer, BUFFER_SIZE, 0);

    printf("Server response: %s\n", recvbuffer);

    close(sockfd);

    return 0;
}