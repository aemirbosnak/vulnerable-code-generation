//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

void print_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char host[MAX_HOST_NAME] = {0};
    strncpy(host, argv[1], MAX_HOST_NAME - 1);

    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char data[MAX_DATA_SIZE] = {0};
    strncpy(data, "PING", MAX_DATA_SIZE - 1);

    if (send(sock, data, strlen(data), 0) == -1) {
        print_error("send");
    }

    char buffer[MAX_DATA_SIZE] = {0};
    int bytes_received = recv(sock, buffer, MAX_DATA_SIZE - 1, 0);
    if (bytes_received == -1) {
        print_error("recv");
    }

    buffer[bytes_received] = '\0';
    printf("Received: %s\n", buffer);

    close(sock);
    return 0;
}