//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct message {
    char *data;
    int length;
};

int main() {
    int sock, cli;
    struct message message;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Bind the socket to a specific address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        cli = accept(sock, NULL, NULL);
        if (cli < 0) {
            perror("accept failed");
            exit(1);
        }

        // Receive a message from the client
        message.data = malloc(1024);
        message.length = recv(cli, message.data, 1024, 0);
        if (message.length < 0) {
            perror("receive failed");
            exit(1);
        }

        // Print the received message
        printf("Received message: %s\n", message.data);

        // Send a response message back to the client
        char *response = "Hello, client!";
        send(cli, response, strlen(response), 0);

        // Free the memory allocated for the message
        free(message.data);

        // Close the client socket
        close(cli);
    }

    return 0;
}