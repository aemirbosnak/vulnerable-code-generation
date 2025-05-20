//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 10

struct connection {
    int sock;
    struct sockaddr_in server_addr;
    char *host;
    int port;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host_ip>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 2;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // default port 80
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct connection *connections = malloc(MAX_CONNECTIONS * sizeof(struct connection));

    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        connections[i].sock = -1;
        connections[i].server_addr = server_addr;
        connections[i].host = host;
        connections[i].port = port;
    }

    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connect(sock, (struct sockaddr *)&connections[i].server_addr, sizeof(struct sockaddr_in)) < 0) {
            perror("connect() failed");
            continue;
        }

        printf("Connected to %s on port %d\n", connections[i].host, connections[i].port);

        // send some data
        char data[] = "Hello, world!";
        send(sock, data, strlen(data), 0);

        // receive some data
        char buffer[1024];
        recv(sock, buffer, 1024, 0);

        printf("Received: %s\n", buffer);

        // close the connection
        close(sock);
    }

    free(connections);
    return 0;
}