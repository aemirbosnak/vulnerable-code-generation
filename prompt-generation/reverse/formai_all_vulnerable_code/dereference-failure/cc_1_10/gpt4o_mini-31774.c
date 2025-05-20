//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[256];
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* create_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

Node* create_node(const char* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->data, data, 256);
    new_node->next = NULL;
    return new_node;
}

void add_node(LinkedList* list, const char* data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display_list(LinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List:\n");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void delete_node(LinkedList* list, const char* data) {
    if (list->head == NULL) return;

    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->data, data) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return; // Data not found
    
    if (previous == NULL) { // The node to be deleted is the head
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void free_list(LinkedList* list) {
    Node* current = list->head;
    Node* next_node;
    
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    
    free(list);
}

void clear_list(LinkedList* list) {
    free_list(list);
    list = create_list();
}

int main() {
    LinkedList* my_list = create_list();
    char choice[10];
    char data[256];

    while (1) {
        printf("\nChoose an operation (add, display, delete, clear, exit): ");
        scanf("%s", choice);

        if (strcmp(choice, "add") == 0) {
            printf("Enter data to add: ");
            scanf(" %[^\n]", data);
            add_node(my_list, data);
        } else if (strcmp(choice, "display") == 0) {
            display_list(my_list);
        } else if (strcmp(choice, "delete") == 0) {
            printf("Enter data to delete: ");
            scanf(" %[^\n]", data);
            delete_node(my_list, data);
        } else if (strcmp(choice, "clear") == 0) {
            clear_list(my_list);
            printf("List cleared.\n");
        } else if (strcmp(choice, "exit") == 0) {
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    free_list(my_list);
    return 0;
}