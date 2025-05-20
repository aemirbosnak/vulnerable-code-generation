//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char name[MAX_SIZE];
    struct node* next;
};

typedef struct node Node;

Node* create_node(char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node** head, char* name) {
    Node* new_node = create_node(name);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        Node* current = head;
        while (current!= NULL) {
            printf("%s\n", current->name);
            current = current->next;
        }
    }
}

int main() {
    Node* head = NULL;

    insert_node(&head, "Alice");
    insert_node(&head, "Bob");
    insert_node(&head, "Charlie");
    insert_node(&head, "David");

    print_list(head);

    return 0;
}