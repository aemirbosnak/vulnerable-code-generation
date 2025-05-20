//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program) {
    fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", program);
    exit(1);
}

int is_port_open(int sockfd, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (result == 0) {
        close(sockfd);
        return 1;
    } else {
        close(sockfd);
        return 0;
    }
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    int sockfd;
    struct sockaddr_in server_addr;
    int port;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    for (port = start_port; port <= end_port; port++) {
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip_address);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        fprintf(stderr, "Start port cannot be greater than end port\n");
        exit(1);
    }

    scan_ports(ip_address, start_port, end_port);

    return 0;
}