//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    long int start_time, end_time;
    double elapsed_time;

    if (argc!= 2) {
        printf("Usage:./speedtest <file_size_in_bytes>\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(send_buffer, "GET /download?size=%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1], SERVER_IP);

    send(sock, send_buffer, strlen(send_buffer), 0);

    start_time = time(NULL);

    while (1) {
        memset(recv_buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, recv_buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        fwrite(recv_buffer, 1, bytes_received, stdout);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("\n");
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Download speed: %.2f bytes/second\n", (double)atoi(argv[1]) / elapsed_time);

    close(sock);

    return 0;
}