//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *server_info;
    struct addrinfo hints;
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *host = "ftp.example.com";
    char *filename = "README.txt";
    char *local_filename = "README.txt";
    FILE *fp;
    int bytes_read;
    char buffer[BUFFER_SIZE];
    char send_buffer[BUFFER_SIZE];
    int len;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(host, "21", &hints, &server_info);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }

    status = connect(sockfd, server_info->ai_addr, server_info->ai_addrlen);
    if (status == -1) {
        fprintf(stderr, "connect error\n");
        exit(1);
    }

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    send(sockfd, "RETR ", 5, 0);
    send(sockfd, filename, strlen(filename), 0);

    fp = fopen(local_filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "fopen error\n");
        exit(1);
    }

    while ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_read, fp);
    }

    fclose(fp);

    printf("File downloaded successfully!\n");

    close(sockfd);

    return 0;
}