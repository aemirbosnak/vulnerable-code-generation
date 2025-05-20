//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void send_command(int sock, char* command) {
    send(sock, command, strlen(command), 0);
}

char* receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    return strdup(buffer);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char* username = "anonymous";
    char* password = "anonymous@example.com";
    send_command(sock, "USER ");
    send_command(sock, username);
    char* response = receive_response(sock);
    if (strcmp(response, "331")!= 0) {
        printf("Invalid username\n");
        exit(1);
    }

    send_command(sock, "PASS ");
    send_command(sock, password);
    response = receive_response(sock);
    if (strcmp(response, "230")!= 0) {
        printf("Invalid password\n");
        exit(1);
    }

    char* local_file = "test.txt";
    char* remote_file = "test.txt";
    send_command(sock, "STOR ");
    send_command(sock, remote_file);
    FILE* fp = fopen(local_file, "rb");
    if (fp == NULL) {
        printf("Error opening local file\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    char buffer[BUFFER_SIZE];
    while (file_size > 0) {
        int bytes_read = fread(buffer, 1, BUFFER_SIZE, fp);
        if (bytes_read <= 0) {
            printf("Error reading local file\n");
            exit(1);
        }
        send(sock, buffer, bytes_read, 0);
        file_size -= bytes_read;
    }
    fclose(fp);

    response = receive_response(sock);
    if (strcmp(response, "226")!= 0) {
        printf("Error uploading file\n");
        exit(1);
    }

    close(sock);
    return 0;
}