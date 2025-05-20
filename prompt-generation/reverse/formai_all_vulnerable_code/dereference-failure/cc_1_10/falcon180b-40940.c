//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <IP address> <start port> <end port>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range.\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address: %s\n", ip_address);
        exit(1);
    }

    int result;
    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);
        result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (result == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed.\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("Connection timed out on port %d.\n", port);
            } else {
                printf("Error connecting to port %d: %s\n", port, strerror(errno));
            }
        } else {
            printf("Port %d is open.\n", port);
            close(sockfd);
            exit(0);
        }
    }

    printf("All ports are closed.\n");
    close(sockfd);
    exit(0);
}