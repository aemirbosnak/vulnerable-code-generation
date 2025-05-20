//FormAI DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_CONTACTS 100

// Define the Contact structure
struct Contact {
    char name[50];
    char phone[15];
};

// Function to trim leading and trailing whitespace from a string
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading whitespace
    while(*str == ' ') {
        str++;
    }

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while(end > str && *end == ' ') {
        end--;
    }
    *(end+1) = '\0';

    return str;
}

// Function to add a new contact to the phone book
void add_contact(struct Contact *phone_book, int *num_contacts) {
    char name[50], phone[15];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    if (strlen(name) > 0 && name[strlen(name)-1] == '\n') {
        name[strlen(name)-1] = '\0';
    }
    printf("Enter phone number: ");
    fgets(phone, sizeof(phone), stdin);
    if (strlen(phone) > 0 && phone[strlen(phone)-1] == '\n') {
        phone[strlen(phone)-1] = '\0';
    }

    if (*num_contacts >= MAX_NUM_CONTACTS) {
        printf("Phone book is full!\n");
    } else {
        struct Contact new_contact;
        strcpy(new_contact.name, trim_whitespace(name));
        strcpy(new_contact.phone, trim_whitespace(phone));
        phone_book[*num_contacts] = new_contact;
        (*num_contacts)++;
        printf("Contact added!\n");
    }
}

// Function to print all contacts in the phone book
void print_contacts(struct Contact *phone_book, int num_contacts) {
    if (num_contacts == 0) {
        printf("Phone book is empty!\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < num_contacts; i++) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
        }
    }
}

int main() {
    struct Contact phone_book[MAX_NUM_CONTACTS];
    int num_contacts = 0;
    char input[10];

    printf("Welcome to the Artistic Phone Book!\n");

    while (1) {
        printf("Enter 'a' to add a contact, 'p' to print all contacts, or 'q' to quit: ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "a\n") == 0) {
            add_contact(phone_book, &num_contacts);
        } else if (strcmp(input, "p\n") == 0) {
            print_contacts(phone_book, num_contacts);
        } else if (strcmp(input, "q\n") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid input, please try again.\n");
        }
    }

    return 0;
}