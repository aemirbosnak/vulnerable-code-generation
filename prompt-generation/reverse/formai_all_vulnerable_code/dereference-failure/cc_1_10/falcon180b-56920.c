//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];
    int min_port, max_port;

    // Validate IP address
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(ip_address, NULL, &hints, &result)!= 0) {
        printf("Invalid IP address: %s\n", ip_address);
        return 1;
    }

    // Parse port range
    sscanf(port_range, "%d-%d", &min_port, &max_port);
    if (min_port > max_port) {
        printf("Invalid port range: %s\n", port_range);
        return 1;
    }

    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Socket creation failed\n");
        return 1;
    }

    for (int port = min_port; port <= max_port; port++) {
        int status = connect(sock, result->ai_addr, result->ai_addrlen);
        if (status == -1) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Port %d is open\n", port);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
        }
    }

    return 0;
}