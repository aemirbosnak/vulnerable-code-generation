//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[numContacts].name);

    printf("Enter contact phone: ");
    scanf("%s", contacts[numContacts].phone);

    printf("Enter contact email: ");
    scanf("%s", contacts[numContacts].email);

    numContacts++;
}

void printContacts() {
    for (int i = 0; i < numContacts; i++) {
        printf("%d. %s - %s - %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContact() {
    char name[50];

    printf("Enter contact name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found contact: %s - %s - %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }

    printf("Contact not found!\n");
}

void deleteContact() {
    int index;

    printf("Enter index of contact to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > numContacts) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < numContacts; i++) {
        contacts[i] = contacts[i + 1];
    }

    numContacts--;
}

void saveContacts() {
    FILE *fp = fopen("contacts.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        fprintf(fp, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(fp);
}

void loadContacts() {
    FILE *fp = fopen("contacts.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        char *email = strtok(NULL, "\n");

        strcpy(contacts[numContacts].name, name);
        strcpy(contacts[numContacts].phone, phone);
        strcpy(contacts[numContacts].email, email);

        numContacts++;
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Options:\n");
        printf("1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Save contacts\n");
        printf("6. Load contacts\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                printContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveContacts();
                break;
            case 6:
                loadContacts();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}