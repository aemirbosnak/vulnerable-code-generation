//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define NUM_PINGS 10

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./ping <IP Address> <Port Number>\n");
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char send_data[MAX_DATA_SIZE];
    memset(send_data, 'A', MAX_DATA_SIZE);

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    for (int i = 0; i < NUM_PINGS; i++) {
        send(sockfd, send_data, MAX_DATA_SIZE, 0);
        gettimeofday(&end_time, NULL);

        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
        printf("Ping %d: Elapsed time: %.2f ms\n", i + 1, elapsed_time);
    }

    close(sockfd);

    return 0;
}