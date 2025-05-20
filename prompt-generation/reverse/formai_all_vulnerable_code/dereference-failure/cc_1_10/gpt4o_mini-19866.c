//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(char* value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory!\n");
        exit(1);
    }
    strcpy(newNode->data, value);
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the linked list
struct LinkedList* initList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        fprintf(stderr, "Error allocating memory!\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

// Function to insert a node at the end of the list
void insertEnd(struct LinkedList* list, char* value) {
    struct Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the contents of the list
void displayList(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = list->head;
    printf("Contents of the linked list:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the first node from the list
void deleteFirst(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    printf("First node deleted.\n");
}

// Function to free the entire list
void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Main program
int main() {
    struct LinkedList* myList = initList();
    char command[100];
    char value[100];

    printf("Welcome to the Retro Linked List Program!\n");
    printf("Available commands: INSERT, DELETE, DISPLAY, EXIT\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcasecmp(command, "INSERT") == 0) {
            printf("Enter value to insert: ");
            fgets(value, sizeof(value), stdin);
            value[strcspn(value, "\n")] = 0; // Remove newline character
            insertEnd(myList, value);
            printf("Inserted '%s' into the list.\n", value);
        } else if (strcasecmp(command, "DELETE") == 0) {
            deleteFirst(myList);
        } else if (strcasecmp(command, "DISPLAY") == 0) {
            displayList(myList);
        } else if (strcasecmp(command, "EXIT") == 0) {
            freeList(myList);
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}