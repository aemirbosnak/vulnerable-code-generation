//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <IP Address> <Port Number>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char message[BUFFER_SIZE] = "PING";

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address\n");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    send(socket_fd, message, strlen(message), 0);
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        fprintf(stderr, "Error receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(socket_fd);
    return 0;
}