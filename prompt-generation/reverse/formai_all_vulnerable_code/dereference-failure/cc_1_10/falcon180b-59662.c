//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTS 100
#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    int *ports = malloc(MAX_PORTS * sizeof(int));
    if (ports == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }

    for (int i = 0; i < MAX_PORTS; i++) {
        ports[i] = start_port + i;
    }

    int num_open_ports = 0;

    for (int i = 0; i < MAX_HOSTS; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: Could not create socket.\n");
            free(ports);
            return 1;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(ports[i]);
        inet_pton(AF_INET, ip_address, &addr.sin_addr);

        int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (result == 0) {
            printf("Port %d is open.\n", ports[i]);
            num_open_ports++;
        } else if (errno == ECONNREFUSED) {
            // Do nothing, port is closed
        } else {
            printf("Error: Could not connect to port %d.\n", ports[i]);
        }

        close(sock);
    }

    free(ports);

    if (num_open_ports == 0) {
        printf("No open ports found.\n");
    }

    return 0;
}