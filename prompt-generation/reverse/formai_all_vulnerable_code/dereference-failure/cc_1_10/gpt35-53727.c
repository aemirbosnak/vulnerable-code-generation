//FormAI DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int is_port_open(char *ip_address, int port_number) {
    struct sockaddr_in target_address;

    target_address.sin_family = AF_INET;
    target_address.sin_port = htons(port_number);
    target_address.sin_addr.s_addr = inet_addr(ip_address);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *)&target_address, sizeof(target_address)) == 0) {
        close(sockfd);
        return 1;
    } else {
        close(sockfd);
        return 0;
    }
}

void scan_ports(char *ip_address, int start_port, int end_port, int *open_ports) {
    int port_number;

    for (port_number = start_port; port_number <= end_port; port_number++) {
        if (is_port_open(ip_address, port_number)) {
            printf("%d\n", port_number);
            *open_ports += 1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(0);
    }
    
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    int open_ports = 0;
  
    scan_ports(ip_address, start_port, end_port, &open_ports);

    if (open_ports == 0) {
        printf("No open ports found.\n");
    } else {
        printf("%d open ports found.\n", open_ports);
    }

    return 0;
}