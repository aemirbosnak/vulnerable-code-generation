//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    char send_buffer[MAX_DATA_SIZE];
    memset(send_buffer, 'A', sizeof(send_buffer));

    int bytes_sent = send(socket_fd, send_buffer, sizeof(send_buffer), 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        exit(1);
    }

    char receive_buffer[MAX_DATA_SIZE];
    memset(receive_buffer, 0, sizeof(receive_buffer));

    int bytes_received = recv(socket_fd, receive_buffer, sizeof(receive_buffer), 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received data: %s\n", receive_buffer);

    close(socket_fd);

    return 0;
}