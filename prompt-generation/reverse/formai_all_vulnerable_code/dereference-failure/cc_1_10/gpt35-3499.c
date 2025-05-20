//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    char* name;
    int age;
    struct Node* next;
};

void insertNode(struct Node** head, int id, char* name, int age) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->name = (char*)malloc(strlen(name) + 1);
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    while(head) {
        printf("ID: %d, Name: %s, Age: %d\n", head->id, head->name, head->age);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    insertNode(&head, 1, "John", 25);
    insertNode(&head, 2, "Alice", 30);
    insertNode(&head, 3, "Bob", 29);
    insertNode(&head, 4, "Kate", 22);

    printf("List of Names: \n");
    printList(head);

    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    printf("\nDeleting nodes with age less than 25... \n");

    while(current != NULL) {
        if(current->age < 25) {
            next = current->next;
            if(prev == NULL) {
                head = next;
            } else {
                prev->next = next;
            }
            free(current->name);
            free(current);
            current = next;
            continue;
        }
        prev = current;
        current = current->next;
    }

    printf("\nList of Names after deleting nodes with age less than 25: \n");
    printList(head);

    return 0;
}