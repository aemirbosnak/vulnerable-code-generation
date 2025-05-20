//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    char name[MAX];
    struct Node* next;
} Node;

Node* Insert(Node* head, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void PrintList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    Insert(head, "John Doe");
    Insert(head, "Jane Doe");
    Insert(head, "Bill Smith");
    Insert(head, "Mary Johnson");

    PrintList(head);

    return 0;
}