//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to traverse the list and print the data
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create a list of nodes on different machines
    int machine_1_data = 1;
    struct Node* machine_1_node = newNode(machine_1_data);
    insertAtBeginning(&head, machine_1_data);

    int machine_2_data = 2;
    struct Node* machine_2_node = newNode(machine_2_data);
    insertAtEnd(&head, machine_2_data);

    int machine_3_data = 3;
    struct Node* machine_3_node = newNode(machine_3_data);
    insertAtBeginning(&head, machine_3_data);

    // Connect to the machines and insert nodes into the list
    int sock_fd[3];
    struct sockaddr_in server_addr[3];
    sock_fd[0] = socket(AF_INET, SOCK_STREAM, 0);
    server_addr[0].sin_family = AF_INET;
    server_addr[0].sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr[0].sin_addr);
    connect(sock_fd[0], (struct sockaddr*)server_addr, sizeof(server_addr[0]));
    send(sock_fd[0], &machine_1_data, sizeof(int), 0);

    sock_fd[1] = socket(AF_INET, SOCK_STREAM, 0);
    server_addr[1].sin_family = AF_INET;
    server_addr[1].sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.2", &server_addr[1].sin_addr);
    connect(sock_fd[1], (struct sockaddr*)server_addr, sizeof(server_addr[1]));
    send(sock_fd[1], &machine_2_data, sizeof(int), 0);

    sock_fd[2] = socket(AF_INET, SOCK_STREAM, 0);
    server_addr[2].sin_family = AF_INET;
    server_addr[2].sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.3", &server_addr[2].sin_addr);
    connect(sock_fd[2], (struct sockaddr*)server_addr, sizeof(server_addr[2]));
    send(sock_fd[2], &machine_3_data, sizeof(int), 0);

    // Print the list of nodes
    printList(head);

    return 0;
}