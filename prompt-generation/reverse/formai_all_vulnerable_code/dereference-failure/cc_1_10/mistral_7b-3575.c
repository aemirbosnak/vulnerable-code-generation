//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Contact {
    char name[50];
    char phone[20];
    struct Contact *next;
} Contact;

Contact *head = NULL;
Contact *current = NULL;

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n");
}

void addContact() {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    printf("Enter Name: ");
    scanf("%s", newContact->name);
    fflush(stdin);
    printf("Enter Phone Number: ");
    fgets(newContact->phone, sizeof(newContact->phone), stdin);
    newContact->next = head;
    head = newContact;
}

void deleteContact() {
    char name[50];
    printf("Enter Name to Delete: ");
    scanf("%s", name);
    if (head == NULL) {
        printf("Phone Book is Empty!\n");
        return;
    }
    if (strcmp(head->name, name) == 0) {
        Contact *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Contact Not Found!\n");
        return;
    }
    Contact *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void searchContact() {
    char name[50];
    printf("Enter Name to Search: ");
    scanf("%s", name);
    if (head == NULL) {
        printf("Phone Book is Empty!\n");
        return;
    }
    current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\n", current->name);
            printf("Phone: %s\n", current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact Not Found!\n");
}

void displayAllContacts() {
    if (head == NULL) {
        printf("Phone Book is Empty!\n");
        return;
    }
    current = head;
    printf("\nPhone Book:\n");
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone: %s\n", current->phone);
        current = current->next;
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                displayAllContacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}