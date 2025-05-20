//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    if (argc < 4) {
        printf("Usage:./ftp_client <hostname> <username> <password>\n");
        exit(1);
    }

    strcpy(send_buffer, "USER ");
    strcat(send_buffer, argv[2]);
    strcat(send_buffer, "\r\n");

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        printf("Error sending data.\n");
        exit(1);
    }

    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    strcpy(send_buffer, "PASS ");
    strcat(send_buffer, argv[3]);
    strcat(send_buffer, "\r\n");

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        printf("Error sending data.\n");
        exit(1);
    }

    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    strcpy(send_buffer, "LIST\r\n");

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        printf("Error sending data.\n");
        exit(1);
    }

    while (1) {
        recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        printf("%s", recv_buffer);
    }

    close(sockfd);
    return 0;
}