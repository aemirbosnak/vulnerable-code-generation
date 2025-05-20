//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

#define LIST_NAME_MAX_LEN 255

struct node {
    char name[LIST_NAME_MAX_LEN];
    struct node* next;
};

void add_node(struct node** head, char* name) {
    struct node* new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void print_list(struct node* head) {
    struct node* current = head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    int sockfd, newsockfd;
    struct node* head = NULL;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Listen for connections
    newsockfd = accept(sockfd, NULL, NULL);

    // Receive data
    char buffer[BUFFER_SIZE];
    recv(newsockfd, buffer, BUFFER_SIZE, 0);

    // Add the data to the list
    add_node(&head, buffer);

    // Print the list
    print_list(head);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}