//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name[20];
    int number;
    struct Node* next;
};

struct Node* insert(struct Node* head, char* name, int number) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->number = number;
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

void search(struct Node* head, char* name) {
    struct Node* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s, Number: %d\n", temp->name, temp->number);
            return;
        }
        temp = temp->next;
    }

    printf("Name not found.\n");
}

int main() {
    struct Node* head = NULL;

    insert(head, "John Doe", 123);
    insert(head, "Jane Doe", 456);
    insert(head, "Peter Pan", 984);

    search(head, "Jane Doe");

    return 0;
}