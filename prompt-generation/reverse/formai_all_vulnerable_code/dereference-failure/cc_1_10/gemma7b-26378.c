//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_LIST_SIZE 10

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

void insert(Node** head, char* name) {
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
        printf("%s\n", head->name);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    char name[MAX_NAME_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    insert(&head, name);

    printf("Enter name: ");
    scanf("%s", name);
    insert(&head, name);

    printf("Enter name: ");
    scanf("%s", name);
    insert(&head, name);

    printList(head);

    return 0;
}