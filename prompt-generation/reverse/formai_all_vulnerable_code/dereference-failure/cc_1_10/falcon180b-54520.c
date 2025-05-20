//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    if (argc!= 4)
    {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        exit(0);
    }

    strcpy(send_buffer, "USER ");
    strcat(send_buffer, argv[2]);
    strcat(send_buffer, "\r\n");

    printf("Sending username: %s\n", send_buffer);

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0)
    {
        printf("Error sending username\n");
        exit(0);
    }

    strcpy(send_buffer, "PASS ");
    strcat(send_buffer, argv[3]);
    strcat(send_buffer, "\r\n");

    printf("Sending password: %s\n", send_buffer);

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0)
    {
        printf("Error sending password\n");
        exit(0);
    }

    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", recv_buffer);

    close(sockfd);
    exit(0);
}