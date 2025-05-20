//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CLIENT_LENGTH 1024

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[2048];
    int port, found = 0;

    if (argc < 2) {
        printf("Usage: %s <port_range>\n", argv[0]);
        return 0;
    }

    port = atoi(argv[1]);
    if (port < 1 || port > 65535) {
        printf("Invalid port range\n");
        return 0;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 0;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        close(sock);
        return 0;
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        close(sock);
        return 0;
    }

    printf("Listening on port %d...\n", port);

    while (1) {
        client_len = sizeof(client);
        client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Read data from client
        read(client_sock, buffer, 2048);
        printf("Client message: %s\n", buffer);

        // Send response to client
        char *message = "Hello, client!";
        send(client_sock, message, strlen(message), 0);

        // Close connection
        close(client_sock);
        found++;
    }

    return 0;
}