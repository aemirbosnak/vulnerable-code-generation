//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

void insertAtTail(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

    char name[50];

    printf("Enter a name: ");
    scanf("%s", name);
    insertAtTail(&head, name);

    printf("Enter another name: ");
    scanf("%s", name);
    insertAtTail(&head, name);

    printf("Enter a third name: ");
    scanf("%s", name);
    insertAtTail(&head, name);

    printList(head);

    return 0;
}