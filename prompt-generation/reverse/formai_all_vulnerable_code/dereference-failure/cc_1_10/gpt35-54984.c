//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_CONTACTS 100

struct contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

typedef struct contact Contact;

Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

void add_contact();
void remove_contact();
void search_contact();
void print_all_contacts();
void save_phone_book();
void load_phone_book();

int main() {
    int choice;

    // load previously saved phone book from file
    load_phone_book();

    do {
        printf("\n---------- Phone Book ----------\n\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Search contact\n");
        printf("4. Print all contacts\n");
        printf("5. Save phone book\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                print_all_contacts();
                break;
            case 5:
                save_phone_book();
                break;
            case 6:
                printf("\nExiting phone book...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("\nPhone book is full. Cannot add more contacts.\n");
        return;
    }

    printf("\nAdding new contact...\n");

    Contact new_contact;
    printf("Enter name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", new_contact.name);
    printf("Enter phone (max %d characters): ", MAX_PHONE_LENGTH);
    scanf("%s", new_contact.phone);
    printf("Enter email (max %d characters): ", MAX_EMAIL_LENGTH);
    scanf("%s", new_contact.email);

    phone_book[num_contacts++] = new_contact;

    printf("\nContact added successfully.\n");
}

void remove_contact() {
    if (num_contacts == 0) {
        printf("\nPhone book is empty. Nothing to remove.\n");
        return;
    }

    printf("\nRemoving a contact...\n");

    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to remove: ");
    scanf("%s", name);

    int removed = 0; // flag to indicate if any contact was removed
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) { // name match found
            removed = 1;
            for (int j = i; j < num_contacts - 1; j++) {
                phone_book[j] = phone_book[j+1];
            }
            num_contacts--;
            printf("\nContact removed successfully.\n");
            break; // exit loop after first match is found
        }
    }

    if (!removed) {
        printf("\nNo contact found with name '%s'. Nothing to remove.\n", name);
    }
}

void search_contact() {
    if (num_contacts == 0) {
        printf("\nPhone book is empty. Nothing to search for.\n");
        return;
    }

    printf("\nSearching for a contact...\n");

    char name[MAX_NAME_LENGTH];
    printf("Enter name of contact to search for: ");
    scanf("%s", name);

    int found = 0; // flag to indicate if any contact was found
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) { // name match found
            found = 1;
            printf("\nContact found:\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone: %s\n", phone_book[i].phone);
            printf("Email: %s\n", phone_book[i].email);
            break; // exit loop after first match is found
        }
    }

    if (!found) {
        printf("\nNo contact found with name '%s'.\n", name);
    }
}

void print_all_contacts() {
    if (num_contacts == 0) {
        printf("\nPhone book is empty. Nothing to print.\n");
        return;
    }

    printf("\nPrinting all contacts...\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Contact %d:\n", i+1);
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone: %s\n", phone_book[i].phone);
        printf("Email: %s\n", phone_book[i].email);
        printf("\n");
    }
}

void save_phone_book() {
    if (num_contacts == 0) {
        printf("\nPhone book is empty. Nothing to save.\n");
        return;
    }

    FILE *file = fopen("phone_book.txt", "w");
    if (!file) {
        printf("\nError opening file for writing.\n");
        return;
    }

    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "%s;%s;%s\n", phone_book[i].name, phone_book[i].phone, phone_book[i].email);
    }

    fclose(file);
    printf("\nPhone book saved to file.\n");
}

void load_phone_book() {
    FILE *file = fopen("phone_book.txt", "r");
    if (!file) {
        // no saved phone book file found
        return;
    }

    char line[MAX_NAME_LENGTH + MAX_PHONE_LENGTH + MAX_EMAIL_LENGTH + 3]; // +3 for delimiters (;)
    char *name;
    char *phone;
    char *email;

    while (fgets(line, sizeof(line), file)) {
        // tokenize line using delimiter ';'
        name = strtok(line, ";");
        phone = strtok(NULL, ";");
        email = strtok(NULL, ";");

        // remove newline character from email field
        email[strlen(email)-1] = '\0';

        // create new contact and add to phone book
        Contact new_contact;
        strcpy(new_contact.name, name);
        strcpy(new_contact.phone, phone);
        strcpy(new_contact.email, email);
        phone_book[num_contacts++] = new_contact;
    }

    fclose(file);
}