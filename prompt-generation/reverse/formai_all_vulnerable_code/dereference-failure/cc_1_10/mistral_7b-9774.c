//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;

bool is_empty() {
    return head == NULL;
}

Node* create_node(int data, const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(int data, const char* name) {
    Node* new_node = create_node(data, name);
    new_node->next = head;
    head = new_node;
}

void display_list() {
    printf("\n***** Cheerful Linked List *****\n");
    if (is_empty()) {
        printf("List is empty.\n");
        return;
    }
    current = head;
    printf("Position | Data | Name\n");
    printf("------------------------------------------\n");
    int pos = 0;
    while (current != NULL) {
        printf("%d | %d | %s\n", ++pos, current->data, current->name);
        current = current->next;
    }
}

int main() {
    int choice, data;
    char name[20];
    while (true) {
        printf("\n***** Cheerful Linked List Menu *****\n");
        printf("1. Insert at Beginning\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data and name: ");
                scanf("%d %s", &data, name);
                insert_at_beginning(data, name);
                break;
            case 2:
                display_list();
                break;
            case 3:
                printf("Goodbye and have a cheerful day!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}