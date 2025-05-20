//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Node structure
struct node {
    int id;
    char* ip;
    int port;
    char* name;
    int is_up;
    struct node* next;
};

// Create a new node
struct node* node_create(char* ip, int port) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->id = 0;
    new_node->ip = ip;
    new_node->port = port;
    new_node->name = "Node";
    new_node->is_up = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void node_insert(struct node** head, struct node* node) {
    node->next = *head;
    *head = node;
}

// Remove a node from the linked list
void node_remove(struct node** head, struct node* node) {
    struct node* temp = *head;
    while (temp->next!= node) {
        temp = temp->next;
    }
    temp->next = node->next;
    free(node);
}

// Print a node
void node_print(struct node* node) {
    printf("Node ID: %d\n", node->id);
    printf("IP Address: %s\n", node->ip);
    printf("Port: %d\n", node->port);
    printf("Name: %s\n", node->name);
    printf("Is Up: %s\n", node->is_up? "Yes" : "No");
}

// Delete a node from the linked list
void node_delete(struct node** head, struct node* node) {
    struct node* temp = *head;
    while (temp->next!= node) {
        temp = temp->next;
    }
    temp->next = node->next;
    free(node);
}

int main() {
    char* ip = "192.168.0.1";
    int port = 8080;
    struct node* head = NULL;
    struct node* node = NULL;

    for (int i = 1; i <= 5; i++) {
        node = node_create(ip, port);
        node->id = i;
        node_insert(&head, node);
        printf("Added Node %d\n", i);
    }

    for (struct node* p = head; p!= NULL; p = p->next) {
        node_print(p);
    }

    node_remove(&head, node);
    node_print(head);

    node_delete(&head, head);
    printf("All nodes deleted\n");

    return 0;
}