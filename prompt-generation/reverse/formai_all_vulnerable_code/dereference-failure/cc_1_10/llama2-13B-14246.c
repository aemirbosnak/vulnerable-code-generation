//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 100

struct connection {
    int sock;
    struct sockaddr_in addr;
};

int main(int argc, char *argv[]) {
    int sock = 0;
    struct connection *connections = malloc(MAX_CONNECTIONS * sizeof(struct connection));

    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(80), // Replace with the port number you want to scan
        .sin_addr.s_addr = inet_addr(argv[1]), // Replace with the host IP address
    };

    // Scan the specified port range
    for (int i = 1; i <= PORT_RANGE; i++) {
        struct sockaddr_in client_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(i),
            .sin_addr = server_addr.sin_addr,
        };

        // Create a connection
        int conn = connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (conn < 0) {
            perror("connect failed");
            continue;
        }

        // Add the connection to the list
        connections[i - 1] = (struct connection) {
            .sock = conn,
            .addr = client_addr,
        };
    }

    // Iterate over the connections and print their IP addresses and ports
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].sock > 0) {
            printf("%d. %s:%d\n", i + 1, inet_ntoa(connections[i].addr.sin_addr), ntohs(connections[i].addr.sin_port));
        }
    }

    // Close the socket and free the connections list
    close(sock);
    free(connections);

    return 0;
}