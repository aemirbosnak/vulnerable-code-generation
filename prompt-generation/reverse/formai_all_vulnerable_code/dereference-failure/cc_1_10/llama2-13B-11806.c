//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10

struct client {
    int sock;
    char buffer[BUFFER_SIZE];
    size_t len;
};

void *dist_word_count(void *arg) {
    struct client *client = arg;
    char *buffer = client->buffer;
    size_t len = client->len;

    // Word count for this client
    size_t word_count = 0;

    // Loop through the buffer and count words
    for (size_t i = 0; i < len; i++) {
        if (isalpha(buffer[i])) {
            word_count++;
        }
    }

    // Send the word count back to the main program
    send(client->sock, &word_count, sizeof(size_t), 0);

    return NULL;
}

int main(int argc, char *argv[]) {
    // Create a socket for listening
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set up the listen address
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the listen address
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    // Create a new client socket for each incoming connection
    while (1) {
        // Accept an incoming connection
        int client_sock = accept(listen_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept failed");
            exit(1);
        }

        // Create a new client structure
        struct client *client = malloc(sizeof(struct client));
        client->sock = client_sock;

        // Read the entire buffer from the client
        char buffer[BUFFER_SIZE];
        ssize_t len = read(client->sock, buffer, BUFFER_SIZE);
        if (len < 0) {
            perror("read failed");
            exit(1);
        }

        // Send the buffer to the word count thread
        pid_t pid = fork();
        if (pid == 0) {
            // Word count thread
            dist_word_count(client);
        } else {
            // Wait for the word count thread to finish
            wait(NULL);
        }

        // Close the client socket
        close(client->sock);

        // Free the client structure
        free(client);
    }

    return 0;
}