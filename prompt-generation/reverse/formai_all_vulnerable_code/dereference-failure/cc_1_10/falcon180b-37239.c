//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <IP address> <start port> <end port>\n", program_name);
}

int is_valid_port(int port) {
    if (port < 1 || port > 65535) {
        return 0;
    }
    return 1;
}

int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

int connect_to_host(char *ip, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address\n");
        return -1;
    }
    int sockfd = create_socket();
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        close(sockfd);
        return -1;
    }
    return sockfd;
}

void scan_ports(char *ip, int start_port, int end_port) {
    int sockfd;
    for (int port = start_port; port <= end_port; port++) {
        if (!is_valid_port(port)) {
            continue;
        }
        sockfd = connect_to_host(ip, port);
        if (sockfd == -1) {
            continue;
        }
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            close(sockfd);
            continue;
        }
        printf("%d - Open\n", port);
        close(sockfd);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    scan_ports(ip, start_port, end_port);
    return 0;
}