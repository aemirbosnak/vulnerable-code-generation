//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: invasive
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char number[20];
};

struct Node {
    struct Contact contact;
    struct Node *next;
};

void invasivePrint(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->contact.name);
        printf("Number: %s\n", current->contact.number);
        current = current->next;
    }
}

int main() {
    struct Node *head = NULL;
    while (1) {
        int choice;
        printf("\n1. Add a contact\n2. Print all contacts\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct Node *newContact = malloc(sizeof(struct Node));
                printf("Enter name: ");
                scanf("%s", newContact->contact.name);
                printf("Enter number: ");
                scanf("%s", newContact->contact.number);
                newContact->next = head;
                head = newContact;
                break;
            }
            case 2: {
                invasivePrint(head);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}