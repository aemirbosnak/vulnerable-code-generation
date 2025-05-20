//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[256];
    char *word;

    // Create the server socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_sock = accept(sock, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a word to be used in the memory game
        word = malloc(256);
        sprintf(word, "%s", "Memory game word");

        // Send the word to the client
        send(client_sock, word, strlen(word), 0);

        // Receive the client's response
        recv(client_sock, buffer, 256, 0);

        // Print the client's response
        printf("Client: %s\n", buffer);

        // Free the word and close the client socket
        free(word);
        close(client_sock);
    }

    return 0;
}