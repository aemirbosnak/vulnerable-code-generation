//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
struct Node* insert_node(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    return *head;
}

// Function to delete a node from the list
struct Node* delete_node(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (*head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return NULL;
    }

    if (prev == NULL) {
        *head = temp->next;
        free(temp);
        return *head;
    }

    prev->next = temp->next;
    free(temp);
    return *head;
}

// Function to print the list
void print_list(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    for (int i = 1; i <= 10; i++) {
        insert_node(&head, i);
    }
    print_list(head);
    insert_node(&head, 11);
    print_list(head);
    delete_node(&head, 5);
    print_list(head);
    return 0;
}