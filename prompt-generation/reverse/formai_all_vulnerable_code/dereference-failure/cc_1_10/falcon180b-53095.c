//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Usage:./ftp_client <IP_address> <port> <file_name>\n");
        exit(1);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);
    char *file_name = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct addrinfo *server_info;
    memset(&server_info, 0, sizeof(server_info));
    server_info->ai_family = AF_INET;
    server_info->ai_socktype = SOCK_STREAM;
    server_info->ai_protocol = IPPROTO_TCP;
    server_info->ai_flags = AI_PASSIVE;

    getaddrinfo(ip_address, NULL, &server_info, NULL);

    connect(sockfd, server_info->ai_addr, server_info->ai_addrlen);
    freeaddrinfo(server_info);

    char *command = "RETR ";
    strcat(command, file_name);
    send(sockfd, command, strlen(command), 0);

    char buffer[BUFFER_SIZE];
    int bytes_read = 0;

    while ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}