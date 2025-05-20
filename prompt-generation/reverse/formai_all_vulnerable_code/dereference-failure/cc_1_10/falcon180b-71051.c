//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define PING_INTERVAL 1 // in seconds

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <number of pings>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int num_pings = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(7); // echo port

    char data[MAX_DATA_SIZE];
    int data_size = strlen(argv[0]) + 1; // include null terminator

    for (int i = 0; i < num_pings; i++) {
        sendto(sock, argv[0], data_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);

        struct timeval tv;
        tv.tv_sec = PING_INTERVAL;
        tv.tv_usec = 0;

        int ret = select(sock + 1, &read_fds, NULL, NULL, &tv);
        if (ret == -1) {
            printf("Error with select: %s\n", strerror(errno));
            break;
        } else if (ret == 0) {
            printf("Timeout\n");
        } else if (FD_ISSET(sock, &read_fds)) {
            int bytes_received = recvfrom(sock, data, MAX_DATA_SIZE, 0, NULL, NULL);
            if (bytes_received <= 0) {
                printf("Error receiving data: %s\n", strerror(errno));
                break;
            }

            data[bytes_received] = '\0'; // add null terminator
            printf("Received: %s\n", data);
        }
    }

    close(sock);
    return 0;
}