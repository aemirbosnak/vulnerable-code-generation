//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_NODES 100
#define MAX_VALUE 1000000

struct node {
    int value;
    struct node *next;
};

struct message {
    int value;
    struct message *next;
};

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    struct node *head, *tail;
    struct message *message;

    // Initialize the search list
    head = tail = NULL;

    // Initialize the search value
    int value = 0;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_NODES) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        if ((client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read the search value from the client
        if (read(client_sock, &value, sizeof(value)) < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        // Add the search value to the search list
        tail = (struct node *)malloc(sizeof(struct node));
        tail->value = value;
        tail->next = NULL;

        if (head == NULL) {
            head = tail;
        } else {
            tail->next = head;
            head = tail;
        }

        // Send the search list to the client
        message = (struct message *)malloc(sizeof(struct message));
        message->value = value;
        message->next = NULL;

        send(client_sock, message, sizeof(struct message), 0);

        // Close the client socket
        close(client_sock);
    }

    return 0;
}