//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_SIZE 1024

void receive_file(int sock_fd, char* filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    char buffer[MAX_SIZE];
    ssize_t nread;
    while ((nread = recv(sock_fd, buffer, MAX_SIZE, 0)) > 0) {
        if (write(fd, buffer, nread) < nread) {
            perror("write error");
            exit(EXIT_FAILURE);
        }
    }
    close(fd);
}

void send_file(int sock_fd, char* filename) {
    int fd = open(filename, O_RDONLY);
    char buffer[MAX_SIZE];
    ssize_t nread;
    while ((nread = read(fd, buffer, MAX_SIZE)) > 0) {
        if (send(sock_fd, buffer, nread, 0) < nread) {
            perror("send error");
            exit(EXIT_FAILURE);
        }
    }
    close(fd);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "usage: ./ftpclient <server_ip> <port_num> <file_path>\n");
        exit(EXIT_FAILURE);
    }
    char* server_ip = argv[1];
    int port_num = atoi(argv[2]);
    char* file_path = argv[3];
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_num);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        perror("invalid server IP address");
        exit(EXIT_FAILURE);
    }
    if (connect(sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    char filename[MAX_SIZE];
    strcpy(filename, strrchr(file_path, '/') + 1);
    char* command = (char*) malloc(MAX_SIZE);
    sprintf(command, "RETR %s\n", file_path);
    send(sock_fd, command, strlen(command), 0);
    free(command);
    receive_file(sock_fd, filename);
    printf("Download completed successfully.\n");
    close(sock_fd);
    return 0;
}