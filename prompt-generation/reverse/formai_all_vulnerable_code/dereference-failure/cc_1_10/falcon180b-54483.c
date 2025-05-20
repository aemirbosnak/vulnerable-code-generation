//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void send_data(int sock, char *data) {
    int sent = send(sock, data, strlen(data), 0);
    if (sent < 0) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        exit(1);
    }
}

void receive_data(int sock, char *buffer) {
    int received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (received < 0) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        exit(1);
    }
    buffer[received] = '\0';
}

void process_data(int sock, char *buffer) {
    if (strcmp(buffer, "EXIT") == 0) {
        close(sock);
        exit(0);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        receive_data(sock, buffer);
        process_data(sock, buffer);
    }

    close(sock);
    return 0;
}