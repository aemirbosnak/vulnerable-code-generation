//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
struct Node {
    char name[100];
    struct Node* next;
};

// Structure to represent the mailing list
struct List {
    struct Node* head;
};

// Function to add a new member to the mailing list
void addMember(struct List* list, char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to remove a member from the mailing list
void removeMember(struct List* list, char* name) {
    struct Node* current = list->head;
    struct Node* prev = NULL;
    
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to list all members of the mailing list
void listMembers(struct List* list) {
    struct Node* current = list->head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    struct List list;
    list.head = NULL;
    
    addMember(&list, "Alice");
    addMember(&list, "Bob");
    addMember(&list, "Charlie");
    
    listMembers(&list); // Output: Alice, Bob, Charlie
    
    removeMember(&list, "Charlie");
    
    listMembers(&list); // Output: Alice, Bob
    
    return 0;
}