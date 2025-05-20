//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_range_min = atoi(argv[2]);
    int port_range_max = PORT_RANGE_MAX;

    if (port_range_min > port_range_max) {
        printf("Invalid port range.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_range_min);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    char buffer[1024];
    sprintf(buffer, "Scanning ports %d - %d on %s...\n", port_range_min, port_range_max, ip_address);
    printf("%s", buffer);

    for (int port = port_range_min; port <= port_range_max; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            close(sock);
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }

    close(sock);
    return 0;
}