//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    char name[MAX];
    struct Node* next;
} Node;

struct Node* insert(struct Node* head, char* name) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insert(head, "John");
    insert(head, "Mary");
    insert(head, "Bob");

    printList(head);

    insert(head, "Alice");

    printList(head);

    return 0;
}