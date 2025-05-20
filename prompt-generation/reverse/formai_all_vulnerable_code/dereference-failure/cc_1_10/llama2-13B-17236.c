//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_HOST_LEN 100

void scan_ports(int sockfd, char *host, int port_range) {
    struct sockaddr_in server_addr;
    socklen_t client_len = sizeof(server_addr);
    int client_fd, port;
    char buffer[256];

    // Initialize the server address with the host and port range
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_range);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    client_fd = connect(sockfd, (struct sockaddr *)&server_addr, client_len);
    if (client_fd < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send a SYN packet to the server to initiate the connection
    send(sockfd, "SYN", 3, 0);

    // Receive the SYN-ACK packet from the server
    recv(sockfd, buffer, 256, 0);

    // Extract the port number from the SYN-ACK packet
    port = ntohs(inet_pton(AF_INET, buffer, &server_addr.sin_port));

    // Print the open ports on the server
    printf("Ports open on %s: ", host);
    for (int i = 0; i < PORT_RANGE; i++) {
        if (port == 0) {
            break;
        }
        printf("%d ", port);
        port = ntohs(inet_pton(AF_INET, buffer, &server_addr.sin_port));
    }
    printf("\n");

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <port_range>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int port_range = atoi(argv[2]);

    // Scan the ports on the specified host
    scan_ports(0, host, port_range);

    return 0;
}