//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

Node* Insert(Node* head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void PrintList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    char* name1 = "John Doe";
    Insert(head, name1);

    char* name2 = "Jane Doe";
    Insert(head, name2);

    char* name3 = "Bob Smith";
    Insert(head, name3);

    PrintList(head);

    return 0;
}