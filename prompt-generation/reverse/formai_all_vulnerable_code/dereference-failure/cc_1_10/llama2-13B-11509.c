//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_WORD_LENGTH 100

struct client_info {
    int sock;
    char client_ip[INET_ADDRSTRLEN];
    char word[MAX_WORD_LENGTH];
};

int main(void) {
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[256];
    int count = 0;
    struct client_info clients[MAX_CLIENT_CONNECTIONS];

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind the server socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENT_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", server.sin_port);

    while (1) {
        // Accept an incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Print the client address and word
        printf("Client connected from IP address %s, word: %s\n",
               inet_ntoa(client.sin_addr), clients[count].word);

        // Receive the word from the client
        recv(client_fd, buffer, 256, 0);
        clients[count].word[0] = buffer[0];
        clients[count].word[1] = buffer[1];
        clients[count].word[2] = buffer[2];
        clients[count].word[3] = buffer[3];

        // Increment the word count
        count++;

        // Send the word back to the client
        send(client_fd, clients[count - 1].word, strlen(clients[count - 1].word), 0);

        // Close the client connection
        close(client_fd);
    }

    return 0;
}