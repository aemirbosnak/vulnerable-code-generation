//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 1024

struct connection {
    int sock;
    struct sockaddr_in address;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 1;
    }

    struct sockaddr_in target_address;
    target_address.sin_family = AF_INET;
    target_address.sin_port = htons(atoi(argv[1]));
    target_address.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&target_address, sizeof(target_address)) < 0) {
        perror("connection failed");
        close(sock);
        return 1;
    }

    // Create a list of connections
    struct connection *connections = calloc(MAX_CONNECTIONS, sizeof(struct connection));
    int i = 0;

    // Scan for open ports
    for (int port = 1; port <= PORT_RANGE; port++) {
        struct sockaddr_in local_address;
        local_address.sin_family = AF_INET;
        local_address.sin_port = htons(port);
        local_address.sin_addr.s_addr = INADDR_ANY;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket creation failed");
            continue;
        }

        if (bind(sock, (struct sockaddr *)&local_address, sizeof(local_address)) < 0) {
            perror("binding failed");
            close(sock);
            continue;
        }

        if (listen(sock, 1) < 0) {
            perror("listening failed");
            close(sock);
            continue;
        }

        // Accept a connection
        sock = accept(sock, NULL, NULL);
        if (sock < 0) {
            perror("accept failed");
            close(sock);
            continue;
        }

        // Add the connection to the list
        connections[i].sock = sock;
        connections[i].address = local_address;
        i++;

        // Close the connection
        close(sock);
    }

    // Print the list of connections
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        printf("%d: %s\n", connections[i].sock, inet_ntoa(connections[i].address.sin_addr));
    }

    // Free the list of connections
    free(connections);

    return 0;
}