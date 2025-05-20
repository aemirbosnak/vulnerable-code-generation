//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char* program_name) {
    printf("Usage: %s [host] [port_range]\n", program_name);
    printf("host: The host to scan\n");
    printf("port_range: The range of ports to scan (e.g. 1-1024)\n");
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char* host = argv[1];
    char* port_range = argv[2];
    int start_port = atoi(port_range);
    int end_port = start_port;

    if (port_range[strlen(port_range) - 1] == '-') {
        end_port = atoi(port_range + strlen(port_range) - 1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        printf("Invalid host\n");
        close(sock);
        return 1;
    }

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error: %s\n", strerror(errno));
        }
    }

    close(sock);
    return 0;
}