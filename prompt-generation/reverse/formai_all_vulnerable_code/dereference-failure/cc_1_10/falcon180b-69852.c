//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *message = "GET / HTTP/1.1\r\nHost: \r\nConnection: close\r\n\r\n";
    char *buffer = malloc(BUFFER_SIZE);
    int bytes_received = 0;
    int total_bytes_received = 0;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    start_time = time(NULL);
    send(sock, message, strlen(message), 0);

    while ((bytes_received = recv(sock, buffer + total_bytes_received, BUFFER_SIZE - total_bytes_received, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    end_time = time(NULL);
    elapsed_time = end_time - start_time;
    speed = (double)total_bytes_received / elapsed_time;

    printf("Transfer rate: %.2f bytes/second\n", speed);

    close(sock);
    free(buffer);
    return 0;
}