//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 80
#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *data = malloc(BUFFER_SIZE);
    char *response = malloc(BUFFER_SIZE);
    int data_len = 0;
    int response_len = 0;
    double total_time = 0;
    double avg_speed = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    for (int i = 0; i < NUM_REQUESTS; i++) {
        data_len = sprintf(data, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER);
        send(sock, data, data_len, 0);

        memset(response, 0, BUFFER_SIZE);
        response_len = recv(sock, response, BUFFER_SIZE, 0);

        if (response_len <= 0) {
            printf("Error receiving response\n");
            exit(1);
        }

        double start_time = clock();
        while (response[response_len - 1]!= '\n') {
            response_len -= 2;
        }
        double end_time = clock();

        total_time += end_time - start_time;
    }

    avg_speed = (double)NUM_REQUESTS * BUFFER_SIZE / total_time;
    printf("Average speed: %.2f kB/s\n", avg_speed);

    close(sock);
    free(data);
    free(response);
    return 0;
}