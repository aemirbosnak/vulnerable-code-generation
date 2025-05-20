//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_SIZE 1024

void process_packet(char *packet, int size) {
    printf("Packet received: %s\n", packet);
}

void handle_error(char *error_message) {
    perror(error_message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port_number>\n", argv[0]);
        return 1;
    }

    char ip_address[16] = {0};
    strncpy(ip_address, argv[1], sizeof(ip_address));

    int port_number = atoi(argv[2]);

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        handle_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        handle_error("connect");
    }

    char buffer[MAX_SIZE];
    while (1) {
        int bytes_received = recv(socket_fd, buffer, MAX_SIZE, 0);
        if (bytes_received <= 0) {
            handle_error("recv");
        }

        process_packet(buffer, bytes_received);
    }

    close(socket_fd);
    return 0;
}