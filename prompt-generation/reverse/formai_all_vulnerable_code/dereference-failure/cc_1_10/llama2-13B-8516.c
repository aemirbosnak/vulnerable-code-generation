//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock;
    struct sockaddr_in server, client;
    socklen_t clen = sizeof(client);
    int rv;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((rv = accept(sock, (struct sockaddr *)&client, &clen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read data from the client
        read(rv, &client, 1024);

        // Send a response back to the client
        send(rv, "Hello, client!", 13, 0);

        // Close the connection
        close(rv);
    }

    return 0;
}