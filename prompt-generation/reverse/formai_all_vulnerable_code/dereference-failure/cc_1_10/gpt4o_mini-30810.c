//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define FILENAME "contacts.txt"

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function prototypes
void addContact();
void viewContacts();
void deleteContact();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline character from input buffer

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline

    printf("Enter email: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // Remove newline

    printf("Enter phone: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline

    fprintf(file, "%s,%s,%s\n", newContact.name, newContact.email, newContact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        char *phone = strtok(NULL, ",");
        if (name && email && phone) {
            printf("Name: %s, Email: %s, Phone: %s", name, email, phone);
        }
    }
    fclose(file);
}

void deleteContact() {
    char nameToDelete[MAX_NAME_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, MAX_NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0; // Remove newline

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char line[1024];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        if (strcmp(name, nameToDelete) != 0) {
            fprintf(tempFile, "%s", line);
        } else {
            found = 1;
        }
    }

    if (found) {
        printf("Contact '%s' deleted successfully!\n", nameToDelete);
    } else {
        printf("Contact '%s' not found!\n", nameToDelete);
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);
}

void clearBuffer() {
    while (getchar() != '\n');
}