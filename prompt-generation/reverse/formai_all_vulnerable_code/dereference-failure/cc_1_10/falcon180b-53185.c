//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage:./ftp_client <IP address> <port number>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        n = send(sockfd, send_buffer, strlen(send_buffer), 0);
        if (n == -1) {
            printf("Error sending command\n");
            return 1;
        }

        memset(recv_buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving response\n");
            return 1;
        }

        printf("%s", recv_buffer);
    }

    close(sockfd);
    return 0;
}