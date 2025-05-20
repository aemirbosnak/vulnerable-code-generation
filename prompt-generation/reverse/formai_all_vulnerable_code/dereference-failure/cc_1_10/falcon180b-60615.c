//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 1024

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port Range> <Verbosity>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port_range_min = atoi(argv[2]);
    int port_range_max = atoi(argv[2]);
    int verbosity = atoi(argv[3]);

    if (port_range_min > port_range_max) {
        printf("Invalid port range\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_range_min);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    char buffer[BUFFER_SIZE];
    while (port_range_min <= port_range_max) {
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            if (verbosity > 0) {
                printf("Port %d is open\n", port_range_min);
            }
        } else {
            if (verbosity > 0) {
                printf("Port %d is closed\n", port_range_min);
            }
        }
        port_range_min++;
    }

    close(sock);
    return 0;
}