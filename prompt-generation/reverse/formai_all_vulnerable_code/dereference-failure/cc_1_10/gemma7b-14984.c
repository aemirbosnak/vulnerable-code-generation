//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// Define a structure to represent a node in a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a function to insert a node into a linked list
void insertNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Define a function to traverse a linked list
void traverseList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    Node* head = NULL;

    // Insert some nodes into the linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    // Traverse the linked list
    traverseList(head);

    // Send the linked list to a remote server
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    connect(sockfd, "localhost", htons(SERVER_PORT));

    char buffer[BUFFER_SIZE];
    traverseList(head);
    sprintf(buffer, "%s", head->data);
    send(sockfd, buffer, BUFFER_SIZE, 0);

    // Receive the linked list from the remote server
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Print the received linked list
    printf("%s", buffer);

    close(sockfd);

    return 0;
}