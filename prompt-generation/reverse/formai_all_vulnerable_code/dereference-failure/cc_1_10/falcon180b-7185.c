//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>

// Define the structure of a node
typedef struct {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to search for a node
Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                Node* result = search(head, data);
                if (result!= NULL) {
                    printf("Node found with data %d\n", result->data);
                } else {
                    printf("Node not found\n");
                }
                break;
            case 3:
                printf("List:\n");
                print_list(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}