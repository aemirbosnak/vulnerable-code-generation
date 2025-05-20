//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;

    time(&start_time);
    send(sock, "GET /speed_test HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", strlen("GET /speed_test HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"), 0);

    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    buffer[bytes_received] = '\0';
    printf("Received %d bytes:\n%s", bytes_received, buffer);

    time(&end_time);
    double elapsed_time = difftime(end_time, start_time);
    double speed = bytes_received / elapsed_time;

    printf("Speed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}