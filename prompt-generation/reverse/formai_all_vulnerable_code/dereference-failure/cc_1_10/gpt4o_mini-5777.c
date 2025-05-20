//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"
#define NAME_SIZE 50
#define PHONE_SIZE 20
#define BUFFER_SIZE 100

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

void add_contact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("Enter Name: ");
    fgets(contact.name, NAME_SIZE, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline
    printf("Enter Phone: ");
    fgets(contact.phone, PHONE_SIZE, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline

    fprintf(file, "%s,%s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void view_contacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\nContacts:\n");
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char *name = strtok(buffer, ",");
        char *phone = strtok(NULL, ",");
        if (phone != NULL) {
            phone[strcspn(phone, "\n")] = 0; // Remove newline
            printf("Name: %s, Phone: %s\n", name, phone);
        }
    }
    fclose(file);
}

void delete_contact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("Enter the name of the contact to delete: ");
    char name_to_delete[NAME_SIZE];
    fgets(name_to_delete, NAME_SIZE, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0; // Remove newline

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    int found = 0;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char *name = strtok(buffer, ",");
        if (strcmp(name, name_to_delete) != 0) {
            fprintf(temp_file, "%s", buffer);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    
    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nContact Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer after scanf

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}