//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

struct port_info {
    int port;
    char *host;
};

void init_ports(struct port_info *ports, int count) {
    int i;
    for (i = 0; i < count; i++) {
        ports[i].port = i + 1;
        ports[i].host = malloc(256);
        if (ports[i].host == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        snprintf(ports[i].host, 256, "%d.%d.%d.%d",
                 (i / 256) % 256, (i / 64) % 256, (i / 8) % 256, i % 8);
    }
}

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[4096];
    int bytes_read;
    struct port_info ports[PORT_RANGE];
    int port_count = PORT_RANGE;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    init_ports(ports, port_count);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(8080);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Read data from the client
        bytes_read = read(client_sock, buffer, 4096);
        if (bytes_read < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Check if the client sent a valid port number
        if (sscanf(buffer, "%d", &port_count) != 1) {
            fprintf(stderr, "Invalid port number received from client\n");
            exit(EXIT_FAILURE);
        }

        // Check if the port is in the range
        if (port_count < 1 || port_count > PORT_RANGE) {
            fprintf(stderr, "Port number out of range\n");
            exit(EXIT_FAILURE);
        }

        // Connect to the client on the specified port
        if (connect(client_sock, (struct sockaddr *)&ports[port_count - 1], sizeof(ports[port_count - 1])) < 0) {
            perror("connect");
            exit(EXIT_FAILURE);
        }

        // Send a response back to the client
        send(client_sock, "Hello, client!", 13, 0);

        // Close the connection
        close(client_sock);
    }

    return 0;
}