//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <test_duration_in_seconds>\n", argv[0]);
        return 1;
    }

    int test_duration = atoi(argv[1]);
    if (test_duration <= 0) {
        printf("Invalid test duration.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        close(sock);
        return 1;
    }

    char request[50];
    sprintf(request, "GET /speed_test?duration=%d HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", test_duration, SERVER_IP);

    send(sock, request, strlen(request), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Error receiving data from server.\n");
        close(sock);
        return 1;
    }

    double speed = (double)bytes_received / test_duration;
    printf("Internet speed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}