//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIST_SIZE 100

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

void addToList(Node** head, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    char* name;

    // Add some test names to the list
    addToList(&head, "John Doe");
    addToList(&head, "Jane Doe");
    addToList(&head, "Bill Smith");

    // Print the list
    printList(head);

    // Get the name of the user
    printf("Enter a name: ");
    scanf("%s", name);

    // Add the user's name to the list
    addToList(&head, name);

    // Print the updated list
    printList(head);

    return 0;
}