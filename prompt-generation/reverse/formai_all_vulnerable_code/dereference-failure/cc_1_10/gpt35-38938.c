//FormAI DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct Node {
    Contact c;
    struct Node* next;
} Node;

Node* head = NULL;

void add_contact() {
    Contact c;
    printf("Enter contact name: ");
    scanf("%s", c.name);
    printf("Enter contact email: ");
    scanf("%s", c.email);
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->c = c;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    printf("Contact added!\n");
}

void print_contacts() {
    if (head == NULL) {
        printf("No contacts.\n");
        return;
    }
    printf("Contacts:\n");
    Node* cur = head;
    while (cur != NULL) {
        printf("%s: %s\n", cur->c.name, cur->c.email);
        cur = cur->next;
    }
}

void delete_contact() {
    if (head == NULL) {
        printf("No contacts.\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to delete: ");
    scanf("%s", name);
    if (strcmp(head->c.name, name) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Contact deleted!\n");
        return;
    }
    Node* cur = head;
    while (cur->next != NULL && strcmp(cur->next->c.name, name) != 0) {
        cur = cur->next;
    }
    if (cur->next == NULL) {
        printf("Contact not found.\n");
        return;
    }
    Node* temp = cur->next;
    cur->next = temp->next;
    free(temp);
    printf("Contact deleted!\n");
}

int main() {
    int choice;
    do {
        printf("\nMailing List Manager:\n");
        printf("1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Delete contact\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                print_contacts();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}