//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 10
#define PORT_RANGE 1024

struct connection {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];
};

void scan_ports(int start, int end) {
    int i, j;
    struct connection connections[MAX_CONNECTIONS];

    for (i = start; i <= end; i++) {
        // Create a new connection
        connections[j].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (connections[j].sock < 0) {
            perror("socket creation failed");
            exit(1);
        }

        // Set the server address
        connections[j].server_addr.sin_family = AF_INET;
        connections[j].server_addr.sin_port = htons(i);
        inet_pton(AF_INET, "127.0.0.1", &connections[j].server_addr.sin_addr);

        // Connect to the server
        if (connect(connections[j].sock, (struct sockaddr *)&connections[j].server_addr, sizeof(struct sockaddr_in)) < 0) {
            perror("connection failed");
            close(connections[j].sock);
            continue;
        }

        // Read data from the server
        read(connections[j].sock, connections[j].buffer, 1024);

        // Print the server's response
        printf("Server responded with: %s\n", connections[j].buffer);

        // Close the connection
        close(connections[j].sock);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    scan_ports(start_port, end_port);

    return 0;
}