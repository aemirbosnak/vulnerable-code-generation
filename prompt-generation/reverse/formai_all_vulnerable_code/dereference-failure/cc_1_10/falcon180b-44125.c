//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, portno, n, ret;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    if (argc!= 3) {
        printf("Usage:./client <IP Address> <Port Number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("Error: connection failed\n");
        exit(0);
    }

    char *request = "GET /speedtest HTTP/1.0\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        printf("Error: data reception failed\n");
        exit(0);
    }

    printf("Response: %s", buffer);

    close(sockfd);
    return 0;
}