//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CONNECTIONS 10
#define MAX_PACKET_SIZE 1024

struct connection {
    int sock;
    char ip[16];
    char port[6];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, MAX_CONNECTIONS);

    while (1) {
        struct connection *conn = malloc(sizeof(struct connection));
        conn->sock = accept(sock, NULL, NULL);
        if (conn->sock < 0) {
            perror("accept failed");
            free(conn);
            continue;
        }

        // Read IP and port from client
        read(conn->sock, (void *)&conn->ip, 16);
        read(conn->sock, (void *)&conn->port, 6);

        // Check if IP and port are valid
        if (strcmp(conn->ip, "127.0.0.1") != 0 || atoi(conn->port) != 1234) {
            close(conn->sock);
            free(conn);
            continue;
        }

        // Allow connection
        printf("Connection allowed from %s:%d\n", conn->ip, conn->port);

        // Do something with the connection...
        char buffer[MAX_PACKET_SIZE];
        read(conn->sock, buffer, MAX_PACKET_SIZE);
        printf("Received packet: %s\n", buffer);

        // Send response
        char *response = "Hello, client!";
        send(conn->sock, response, strlen(response), 0);

        // Close connection
        close(conn->sock);
        free(conn);
    }

    return 0;
}