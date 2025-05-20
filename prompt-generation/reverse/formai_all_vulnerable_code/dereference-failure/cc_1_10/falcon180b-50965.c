//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME_SIZE 256
#define MAX_DATA_SIZE 64
#define NUM_PINGS 10
#define PING_INTERVAL_MS 1000

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_SIZE];
    strncpy(hostname, argv[1], MAX_HOSTNAME_SIZE);

    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sock == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    char data[MAX_DATA_SIZE];
    for (int i = 0; i < NUM_PINGS; i++) {
        snprintf(data, MAX_DATA_SIZE, "Ping %d", i + 1);
        sendto(sock, data, strlen(data), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        usleep(PING_INTERVAL_MS * 1000);
    }

    close(sock);

    return 0;
}