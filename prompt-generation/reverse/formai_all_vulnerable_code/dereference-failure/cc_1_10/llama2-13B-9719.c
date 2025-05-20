//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

typedef struct {
    int sock;
    char *host;
    int port;
} config_t;

int main(int argc, char *argv[]) {
    config_t c;

    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    c.host = argv[1];
    c.port = atoi(argv[2]);

    if (c.port <= 0 || c.port > 65535) {
        printf("Invalid port number: %d\n", c.port);
        return 2;
    }

    if (socket(AF_INET, SOCK_STREAM, 0) < 0) {
        perror("Socket creation failed");
        return 3;
    }

    c.sock = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(c.sock, (struct sockaddr *)&c.host, sizeof(c.host)) < 0) {
        perror("Connection failed");
        close(c.sock);
        return 4;
    }

    printf("Connected to %s on port %d\n", c.host, c.port);

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_read = recv(c.sock, buffer, BUFFER_SIZE, 0);
        if (bytes_read < 0) {
            perror("Recv failed");
            break;
        }

        printf("Received message: %s\n", buffer);

        char *message = "Hello, server!";
        send(c.sock, message, strlen(message), 0);

        printf("Sent message: %s\n", message);
    }

    close(c.sock);

    return 0;
}