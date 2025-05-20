//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_NODES 100
#define MAX_DATA 1024

struct node {
    int data;
    struct node *next;
};

int main() {
    int sock, conn_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_DATA];
    struct node *head, *tail, *current;

    // Create a server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        if ((conn_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new node for the client
        head = (struct node *)malloc(sizeof(struct node));
        head->data = 0;
        head->next = NULL;

        // Add the new node to the tail of the list
        tail->next = head;
        tail = head;

        // Read data from the client
        read(conn_sock, buffer, MAX_DATA);
        int data = atoi(buffer);

        // Add the data to the linked list
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (struct node *)malloc(sizeof(struct node));
        current->next->data = data;
        current->next->next = NULL;

        // Send the updated list to the client
        send(conn_sock, "Updated list: ", 13, 0);

        // Close the connection
        close(conn_sock);
    }

    return 0;
}