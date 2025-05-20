//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define MAX_HOSTS 100
#define MAX_DATA_POINTS 100

int main(int argc, char **argv) {

    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char buffer[BUFFER_SIZE];
    int bytes_received;
    int total_bytes_received = 0;
    struct timeval start_time, end_time;
    int num_data_points = 0;

    gettimeofday(&start_time, NULL);

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        total_bytes_received += bytes_received;

        if (++num_data_points == MAX_DATA_POINTS) {
            break;
        }
    }

    gettimeofday(&end_time, NULL);

    double elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    double throughput_bps = (double)total_bytes_received / elapsed_time_ms;

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Elapsed time (ms): %f\n", elapsed_time_ms);
    printf("Throughput (bps): %f\n", throughput_bps);

    close(sock);
    return 0;
}