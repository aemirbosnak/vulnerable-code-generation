//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int create_socket(const char* address, int port) {
    struct sockaddr_in server;
    int sock;

    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    inet_pton(AF_INET, address, &server.sin_addr);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    return sock;
}

int main(int argc, char *argv[]) {
    int sock;
    char *server_address;
    int port;
    char buffer[BUFFER_SIZE];
    struct hostent* host;
    int file;

    if (argc != 4) {
        printf("Usage: %s <ftp server address> <port> <file name>\n", argv[0]);
        return 1;
    }

    server_address = argv[1];
    port = atoi(argv[2]);

    host = gethostbyname(server_address);
    sock = create_socket(inet_ntoa(*(struct in_addr*)host->h_addr), port);

    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Connection Failed\n");
        return 1;
    }

    sprintf(buffer, "RETR %s\n", argv[3]);

    send(sock, buffer, strlen(buffer), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);

    if (strncmp(buffer, "550", 3) == 0) {
        printf("Error: File not found\n");
        return 1;
    }

    file = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        write(file, buffer, bytes_received);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(file);
    close(sock);

    return 0;
}