//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define PORT 80

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFF_SIZE];
    char recv_buffer[BUFF_SIZE];

    if (argc!= 3) {
        printf("Usage:./client <IP address> <file name>\n");
        exit(0);
    }

    strcpy(send_buffer, "GET /");
    strcat(send_buffer, argv[2]);
    strcat(send_buffer, " HTTP/1.1\r\nHost: ");
    strcat(send_buffer, argv[1]);
    strcat(send_buffer, "\r\nConnection: close\r\n\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: socket failed\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: connect failed\n");
        exit(0);
    }

    send(sockfd, send_buffer, strlen(send_buffer), 0);

    while ((n = recv(sockfd, recv_buffer, BUFF_SIZE, 0)) > 0) {
        recv_buffer[n] = '\0';
        printf("%s", recv_buffer);
    }

    close(sockfd);
    return 0;
}