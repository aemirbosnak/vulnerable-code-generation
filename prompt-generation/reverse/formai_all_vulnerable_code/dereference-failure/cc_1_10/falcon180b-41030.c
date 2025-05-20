//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: future-proof
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
    printf("Usage: %s <IP Address> <Port Range>\n", program_name);
}

void scan_ports(char* ip_address, int start_port, int end_port) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (ret == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error: Failed to connect to port %d\n", port);
        }
    }

    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Error: Invalid port range\n");
        return 1;
    }

    scan_ports(ip_address, start_port, end_port);

    return 0;
}