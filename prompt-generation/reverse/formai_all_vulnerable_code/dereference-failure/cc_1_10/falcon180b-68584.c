//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <ip_address> <port_range>\n", program_name);
    exit(1);
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(start_port);

    for (int i = start_port; i <= end_port; i++) {
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            char buffer[BUFFER_SIZE];
            snprintf(buffer, BUFFER_SIZE, "Port %d is open\n", i);
            write(sock, buffer, strlen(buffer));
            close(sock);
        } else {
            continue;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    scan_ports(ip_address, start_port, end_port);

    return 0;
}