//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_NAME_LEN];
} Contact;

void prompt_for_contact(Contact *contact) {
    printf("Enter Name: ");
    fgets(contact->name, MAX_NAME_LEN, stdin);
    contact->name[strcspn(contact->name, "\n")] = 0; // Remove trailing newline
    
    printf("Enter Phone: ");
    fgets(contact->phone, MAX_NAME_LEN, stdin);
    contact->phone[strcspn(contact->phone, "\n")] = 0; // Remove trailing newline
}

void add_contact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    prompt_for_contact(&contact);
    fprintf(file, "%s,%s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void display_contacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\n--- Contact List ---\n");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        printf("Name: %s, Phone: %s", name, phone);
    }
    fclose(file);
}

void delete_contact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        fclose(file);
        perror("Unable to create temp file");
        return;
    }

    char line[100];
    char name_to_delete[MAX_NAME_LEN];
    printf("Enter the name of the contact to delete: ");
    fgets(name_to_delete, MAX_NAME_LEN, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0; // Remove trailing newline

    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        if (strcmp(name, name_to_delete) != 0) {
            fputs(line, temp_file);  // Write to temp file if not deleting
        } else {
            found = 1;  // Contact found
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(FILE_NAME);  // Delete original file
        rename("temp.txt", FILE_NAME);  // Rename temp to original
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.txt");  // Clean up temp file
        printf("Contact not found.\n");
    }
}

void search_contact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    char name_to_search[MAX_NAME_LEN];
    printf("Enter the name of the contact to search: ");
    fgets(name_to_search, MAX_NAME_LEN, stdin);
    name_to_search[strcspn(name_to_search, "\n")] = 0; // Remove trailing newline

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        if (strcmp(name, name_to_search) == 0) {
            char *phone = strtok(NULL, ",");
            printf("Name: %s, Phone: %s\n", name, phone);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("Contact not found.\n");
    }
}

void display_menu() {
    printf("\n--- Welcome to the Contact Manager ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
    printf("Please choose an option (1-5): ");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Clear newline character left by scanf

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                search_contact();
                break;
            case 5:
                printf("Exiting the Contact Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}