//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODE_SIZE 1024
#define LIST_SIZE 10

struct node {
    int data;
    struct node *next;
};

int main() {
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_NODE_SIZE];
    struct node *head, *tail, *new_node;

    // Create a listening socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    // Accept an incoming connection
    client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }

    printf("Connection accepted from %s\n", inet_ntoa(client_addr.sin_addr));

    // Create a linked list on the server side
    head = tail = NULL;
    for (int i = 0; i < LIST_SIZE; i++) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Send the linked list to the client
    send(client_sock, "Linked list: ", 13, 0);
    for (struct node *cur = head; cur != NULL; cur = cur->next) {
        send(client_sock, &cur->data, sizeof(int), 0);
    }

    // Receive the client's input and add it to the linked list
    while (1) {
        int input;
        recv(client_sock, &input, sizeof(int), 0);

        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = input;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        printf("Client input: %d\n", input);
    }

    // Close the socket
    close(client_sock);

    return 0;
}