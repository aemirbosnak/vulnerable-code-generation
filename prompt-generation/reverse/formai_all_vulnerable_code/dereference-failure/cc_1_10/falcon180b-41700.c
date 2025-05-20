//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    int port;
    char *ip_address;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "password";

    if (argc!= 4) {
        printf("Usage:./ftp_client <IP Address> <Port Number> <Command>\n");
        exit(1);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);
    strcpy(buffer, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Unable to create socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Unable to connect to server.\n");
        exit(1);
    }

    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    send(sockfd, buffer, strlen(buffer), 0);

    close(sockfd);

    return 0;
}