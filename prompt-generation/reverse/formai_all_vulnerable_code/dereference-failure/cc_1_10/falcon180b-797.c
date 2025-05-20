//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USERNAME "anonymous"
#define PASSWORD "anonymous@example.com"

void error(const char *message) {
    perror(message);
    exit(1);
}

void ftp_connect(int *socket_fd) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "ftp.example.com", &server_addr.sin_addr);

    *socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*socket_fd == -1) {
        error("socket");
    }

    if (connect(*socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }
}

void ftp_login(int socket_fd) {
    char username[20] = USERNAME;
    char password[50] = PASSWORD;
    send(socket_fd, username, strlen(username), 0);
    send(socket_fd, password, strlen(password), 0);
}

void ftp_get_file(int socket_fd, const char *filename) {
    char command[50];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send(socket_fd, command, strlen(command), 0);
}

void ftp_download_file(const char *filename) {
    int socket_fd;
    ftp_connect(&socket_fd);
    ftp_login(socket_fd);
    ftp_get_file(socket_fd, filename);

    FILE *output_file;
    output_file = fopen(filename, "wb");

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(output_file);
    close(socket_fd);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    ftp_download_file(argv[1]);

    return 0;
}