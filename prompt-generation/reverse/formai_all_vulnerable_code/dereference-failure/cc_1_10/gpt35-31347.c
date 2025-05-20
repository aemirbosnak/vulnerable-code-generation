//FormAI DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// function to check if the port is open or closed
bool is_port_open(char *ip_address, int port) {
    struct sockaddr_in target;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    memset(&target, 0, sizeof(target));
    target.sin_port = htons(port);
    target.sin_family = AF_INET;

    // convert the IP address from text to binary form
    if (inet_pton(AF_INET, ip_address, &target.sin_addr) <= 0) {
        perror("inet_pton");
        close(sock);
        return false;
    }

    // try connecting to the target address and port
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        close(sock);
        return true;
    }

    close(sock);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip_address> [starting_port] [ending_port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int start_port = 1;
    int end_port = 65535;

    if (argc == 3) {
        start_port = atoi(argv[2]);
        end_port = start_port;
    } else if (argc == 4) {
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
    }

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip_address);

    // scan all ports in the range
    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(ip_address, port)) {
            printf("Port %d is open\n", port);
        }
    }

    printf("Scan complete\n");
    return 0;
}