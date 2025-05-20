//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
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
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./ftp_client <IP Address> <Username> <Password>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char login_cmd[50] = "USER ";
    strcat(login_cmd, argv[2]);
    strcat(login_cmd, "\r\n");
    send(sockfd, login_cmd, strlen(login_cmd), 0);

    char pass_cmd[50] = "PASS ";
    strcat(pass_cmd, argv[3]);
    strcat(pass_cmd, "\r\n");
    send(sockfd, pass_cmd, strlen(pass_cmd), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    printf("Server response: %s", buffer);

    close(sockfd);
    return 0;
}