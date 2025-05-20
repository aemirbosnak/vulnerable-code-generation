//FormAI DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char *name;
    char *phone_number;
};

int menu();
void add_contact(struct contact *book, int *size);
void search_contact(struct contact *book, int size);
void delete_contact(struct contact *book, int *size);

int main() {
    struct contact phone_book[MAX_CONTACTS];
    int size = 0;
    int choice;

    while ((choice = menu()) != 4) {
        switch(choice) {
            case 1:
                add_contact(phone_book, &size);
                break;
            case 2:
                search_contact(phone_book, size);
                break;
            case 3:
                delete_contact(phone_book, &size);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    printf("Closing phone book.\n");

    return 0;
}

int menu() {
    int choice;

    printf("------ C Phone Book ------\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Quit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    return choice;
}

void add_contact(struct contact *book, int *size) {
    char buffer[256];
    book[*size].name = malloc(sizeof(char));
    book[*size].phone_number = malloc(sizeof(char));

    printf("Enter name: ");
    scanf("%s", buffer);
    book[*size].name = realloc(book[*size].name, strlen(buffer)*sizeof(char));
    strcpy(book[*size].name, buffer);

    printf("Enter phone number: ");
    scanf("%s", buffer);
    book[*size].phone_number = realloc(book[*size].phone_number, strlen(buffer)*sizeof(char));
    strcpy(book[*size].phone_number, buffer);

    printf("Contact added successfully.\n");

    (*size)++;
}

void search_contact(struct contact *book, int size) {
    char buffer[256];
    printf("Enter name: ");
    scanf("%s", buffer);

    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].name, buffer) == 0) {
            printf("Name: %s\n", book[i].name);
            printf("Phone number: %s\n", book[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(struct contact *book, int *size) {
    char buffer[256];
    printf("Enter name: ");
    scanf("%s", buffer);

    for (int i = 0; i < *size; i++) {
        if (strcmp(book[i].name, buffer) == 0) {
            free(book[i].name);
            free(book[i].phone_number);
            for (int j = i+1; j < *size; j++) {
                book[j-1] = book[j];
            }
            (*size)--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}