//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

struct node {
    int socket;
    char name[50];
    char message[100];
    struct node *next;
};

void create_node(struct node **head_ptr, int socket, char *name, char *message) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->socket = socket;
    strcpy(new_node->name, name);
    strcpy(new_node->message, message);
    new_node->next = *head_ptr;
    *head_ptr = new_node;
}

void print_nodes(struct node *head) {
    while (head != NULL) {
        printf("%d: %s says: %s\n", head->socket, head->name, head->message);
        head = head->next;
    }
}

void chat_server(int socket) {
    struct node *head = NULL;

    while (1) {
        char name[50];
        char message[100];

        printf("Client: Please enter your name and message: ");
        fgets(name, 50, stdin);
        fgets(message, 100, stdin);

        create_node(&head, socket, name, message);

        printf("Server: Hello %s!", name);
        print_nodes(head);

        if (strcmp(name, "Admin") == 0) {
            printf("Server: I am not able to chat with you. Please leave the chat room.\n");
            break;
        }

        printf("Server: Please enter another message: ");
        fgets(message, 100, stdin);

        create_node(&head, socket, name, message);
    }

    printf("Server: Goodbye! Chat room is now closed.\n");
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, 3);

    printf("Server listening on port %d...\n", ntohs(server_addr.sin_port));

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        chat_server(client_sock);
        close(client_sock);
    }

    return 0;
}