//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[MAX_LINE_LENGTH];
    char receive_buffer[MAX_LINE_LENGTH];

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        return 1;
    }

    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char *login_request = "USER ";
    strcat(login_request, username);
    strcat(login_request, "\r\n");
    send(sockfd, login_request, strlen(login_request), 0);

    char *password_request = "PASS ";
    strcat(password_request, password);
    strcat(password_request, "\r\n");
    send(sockfd, password_request, strlen(password_request), 0);

    char *command_buffer = "LIST\r\n";
    send(sockfd, command_buffer, strlen(command_buffer), 0);

    int bytes_received;
    while ((bytes_received = recv(sockfd, receive_buffer, MAX_LINE_LENGTH, 0)) > 0) {
        receive_buffer[bytes_received] = '\0';
        printf("%s", receive_buffer);
    }

    close(sockfd);

    return 0;
}