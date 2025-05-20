//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_ Mailing_LIST_SIZE 100

typedef struct Mailing_List_Node {
    char name[MAX_NAME_LENGTH];
    struct Mailing_List_Node* next;
} Mailing_List_Node;

Mailing_List_Node* Insert_Node(Mailing_List_Node* head, char* name) {
    Mailing_List_Node* newNode = (Mailing_List_Node*)malloc(sizeof(Mailing_List_Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int Search_Node(Mailing_List_Node* head, char* name) {
    Mailing_List_Node* current = head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    Mailing_List_Node* head = NULL;

    Insert_Node(head, "John Doe");
    Insert_Node(head, "Jane Doe");
    Insert_Node(head, "Peter Pan");

    if (Search_Node(head, "John Doe") == 1) {
        printf("John Doe is in the list.\n");
    }

    if (Search_Node(head, "Bob Smith") == 0) {
        printf("Bob Smith is not in the list.\n");
    }

    return 0;
}