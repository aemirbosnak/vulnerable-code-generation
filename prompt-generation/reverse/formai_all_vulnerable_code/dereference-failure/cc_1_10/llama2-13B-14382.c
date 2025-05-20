//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 50

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
        return 2;
    }

    struct sockaddr_in target_address;
    target_address.sin_family = AF_INET;
    target_address.sin_port = htons(atoi(argv[1]));
    target_address.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Scanning port %d on %s...\n", target_address.sin_port, argv[1]);

    struct connection connections[MAX_CONNECTIONS];
    int connection_count = 0;

    for (int i = 0; i < PORT_RANGE; i++) {
        socklen_t address_len = sizeof(target_address);
        getsockname(sock, (struct sockaddr *)&target_address, &address_len);

        if (connect(sock, (struct sockaddr *)&target_address, sizeof(target_address)) == 0) {
            printf("Connected to %s on port %d\n", argv[1], target_address.sin_port);

            struct connection *new_connection = calloc(1, sizeof(struct connection));
            new_connection->sock = sock;
            new_connection->address = target_address;

            // Add the connection to the array
            connections[connection_count] = *new_connection;
            connection_count++;

            if (connection_count >= MAX_CONNECTIONS) {
                break;
            }
        }
    }

    for (int i = 0; i < connection_count; i++) {
        printf("Connection %d: %s on port %d\n", i, connections[i].address.sin_addr.s_addr, connections[i].address.sin_port);
    }

    close(sock);

    return 0;
}