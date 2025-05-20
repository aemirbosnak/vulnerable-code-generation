//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[100];
    char email[100];
} Contact;

typedef struct Node {
    Contact data;
    struct Node *next;
} Node;

Node *head = NULL;

void AddContact(char name[], char email[]) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    strcpy(newNode->data.email, email);
    newNode->next = head;
    head = newNode;
    printf("Contact added successfully! %s %s\n", name, email);
}

void DeleteContact(char name[]) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Contact deleted successfully! %s\n", name);
            break;
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found! %s\n", name);
    }
}

void DisplayContacts() {
    Node *current = head;

    printf("\n--- Mailing List ---\n");
    while (current != NULL) {
        printf("%s: %s\n", current->data.name, current->data.email);
        current = current->next;
    }
}

int main() {
    AddContact("Bob Marley", "bobmarley@mail.com");
    AddContact("Steve Jobs", "stevejobs@apple.com");
    AddContact("Elon Musk", "elonmusk@tesla.com");
    AddContact("Albert Einstein", "einstein@princeton.edu");

    DisplayContacts();

    DeleteContact("Steve Jobs");

    printf("\n--- After Deleting Steve Jobs ---\n");
    DisplayContacts();

    return 0;
}