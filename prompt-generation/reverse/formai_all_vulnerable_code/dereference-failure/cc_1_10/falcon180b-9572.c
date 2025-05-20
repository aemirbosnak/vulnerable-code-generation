//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server_addr;
    char *ip_address = "127.0.0.1";
    int port_range[2] = {1, MAX_PORTS};
    int num_ports = 0;

    if (argc == 3) {
        ip_address = argv[1];
        port_range[0] = atoi(argv[2]);
        port_range[1] = atoi(argv[2]);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    for (int i = port_range[0]; i <= port_range[1]; i++) {
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", i);
            num_ports++;
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", i);
        } else {
            printf("Error connecting to port %d: %s\n", i, strerror(errno));
        }
    }

    close(sock);

    if (num_ports == 0) {
        printf("No open ports found.\n");
    }

    return 0;
}