//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024
#define PORT "8080"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recv_len;
    char buffer[MAX_DATA_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    char *message = "GET / HTTP/1.1\r\nHost:\r\nConnection: close\r\n\r\n";

    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to %s:%s\n", argv[1], PORT);
        exit(1);
    }

    send(sockfd, message, strlen(message), 0);

    clilen = sizeof(cli_addr);
    recv_len = recv(sockfd, buffer, MAX_DATA_SIZE, 0);

    printf("Received %d bytes of data\n", recv_len);

    close(sockfd);

    return 0;
}