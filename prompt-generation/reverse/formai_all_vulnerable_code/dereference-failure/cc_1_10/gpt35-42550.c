//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1024

int recv_file(int sockfd, char *filename) {
    char buffer[BUFSIZE];
    int filefd;
    int read_bytes, write_bytes;

    if ((filefd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR)) < 0) {
        perror("open file failed");
        return -1;
    }

    while ((read_bytes = recv(sockfd, buffer, BUFSIZE, 0)) > 0) {
        if ((write_bytes = write(filefd, buffer, read_bytes)) < 0) {
            perror("write file error");
            close(filefd);
            return -1;
        }
        memset(buffer, 0, BUFSIZE);
    }

    if (read_bytes < 0) {
        perror("recv file error");
        close(filefd);
        return -1;
    }

    close(filefd);
    printf("File received successfully!\n");
    return 0;
}

int send_file(int sockfd, char *filename) {
    char buffer[BUFSIZE];
    int filefd;
    int read_bytes, send_bytes;

    if ((filefd = open(filename, O_RDONLY)) < 0) {
        perror("open file failed");
        return -1;
    }

    while ((read_bytes = read(filefd, buffer, BUFSIZE)) > 0) {
        if ((send_bytes = send(sockfd, buffer, read_bytes, 0)) < 0) {
            perror("send file error");
            close(filefd);
            return -1;
        }
        memset(buffer, 0, BUFSIZE);
    }

    if (read_bytes < 0) {
        perror("read file error");
        close(filefd);
        return -1;
    }

    close(filefd);
    printf("File sent successfully!\n");
    return 0;
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int server_port;
    char *server_ip;
    char *filename;
    char command[BUFSIZE];

    if (argc < 4) {
        printf("Usage: %s {send|recv} <server_ip> <server_port> <filename>\n", argv[0]);
        return -1;
    }

    if (strcmp(argv[1], "send") != 0 && strcmp(argv[1], "recv") != 0) {
        printf("Usage: %s {send|recv} <server_ip> <server_port> <filename>\n", argv[0]);
        return -1;
    }

    server_ip = argv[2];
    server_port = atoi(argv[3]);
    filename = argv[4];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("create socket error");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        close(sockfd);
        return -1;
    }

    if (strcmp(argv[1], "send") == 0) {
        sprintf(command, "get %s", filename);
        send(sockfd, command, strlen(command), 0);
        recv_file(sockfd, filename);
    }

    if (strcmp(argv[1], "recv") == 0) {
        sprintf(command, "put %s", filename);
        send(sockfd, command, strlen(command), 0);
        send_file(sockfd, filename);
    }

    close(sockfd);
    return 0;
}