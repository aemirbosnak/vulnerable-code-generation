//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_DATA_SIZE 1024


void print_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Number of Packets>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int num_packets = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        print_error("socket");
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &dest_addr.sin_addr);

    char data[MAX_DATA_SIZE];
    memset(data, 0, sizeof(data));

    int packet_size = strlen(data);

    for (int i = 0; i < num_packets; i++) {
        sendto(sock, data, packet_size, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        usleep(100000); // Sleep for 100ms between packets
    }

    close(sock);

    return 0;
}