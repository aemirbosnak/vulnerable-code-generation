//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char number[20];
    struct node *next;
};

struct node *head = NULL;

void addContact(char *name, char *number) {
    struct node *newContact = (struct node *)malloc(sizeof(struct node));
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->next = NULL;
    if (head == NULL) {
        head = newContact;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newContact;
    }
}

void deleteContact(char *name) {
    struct node *ptr = head;
    struct node *prev = NULL;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr == head) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            break;
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
}

void searchContact(char *name) {
    struct node *ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            printf("Name: %s\n", ptr->name);
            printf("Number: %s\n", ptr->number);
            break;
        } else {
            ptr = ptr->next;
        }
    }
    if (ptr == NULL) {
        printf("Contact not found.\n");
    }
}

void printAllContacts() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("Name: %s\n", ptr->name);
        printf("Number: %s\n", ptr->number);
        ptr = ptr->next;
    }
}

int main() {
    addContact("John Doe", "123-456-7890");
    addContact("Jane Doe", "098-765-4321");
    addContact("James Smith", "111-222-3333");
    addContact("Mary Johnson", "444-555-6666");
    addContact("Robert Jones", "777-888-9999");
    printAllContacts();
    printf("Deleting James Smith\n");
    deleteContact("James Smith");
    printf("Searching for Mary Johnson\n");
    searchContact("Mary Johnson");
    return 0;
}