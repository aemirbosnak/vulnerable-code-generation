//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT "21"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    int bytes_sent, bytes_recv;

    if (argc < 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, argv[2], strlen(argv[2]), 0);
    send(sockfd, argv[3], strlen(argv[3]), 0);

    while (1) {
        memset(recv_buffer, 0, BUFFER_SIZE);
        bytes_recv = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (bytes_recv <= 0) {
            printf("Disconnected from server\n");
            break;
        }
        printf("%s", recv_buffer);
    }

    close(sockfd);
    return 0;
}