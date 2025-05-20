//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 20

// Define a struct to hold mailing list data
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} MailingList;

// Define a struct to hold the mailing list and its length
typedef struct {
    MailingList *list;
    int length;
} MailingListManager;

// Function to read input from user
char *readInput(char *prompt) {
    char *input = malloc(100 * sizeof(char));
    printf("%s", prompt);
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    return input;
}

// Function to add a new contact to the mailing list
void addContact(MailingListManager *manager) {
    // Allocate memory for new contact
    manager->list = realloc(manager->list, (manager->length + 1) * sizeof(MailingList));
    MailingList *newContact = &(manager->list[manager->length]);

    // Read input from user
    strcpy(newContact->name, readInput("Enter the name: "));
    strcpy(newContact->email, readInput("Enter the email address: "));
    strcpy(newContact->phone, readInput("Enter the phone number: "));

    // Increment length of mailing list
    manager->length++;
    printf("Contact added successfully!\n");
}

// Function to display all contacts in the mailing list
void displayContacts(MailingListManager manager) {
    printf("Mailing list has %d contacts:\n", manager.length);
    for (int i = 0; i < manager.length; i++) {
        printf("%d. Name: %s\n   Email: %s\n   Phone: %s\n", i+1, manager.list[i].name, manager.list[i].email, manager.list[i].phone);
    }
}

// Main function to run the program
int main() {
    MailingListManager manager = {.list = NULL, .length = 0};
    int option;

    while (1) {
        printf("\nMenu:\n"
               "1. Add new contact\n"
               "2. Display all contacts\n"
               "3. Exit\n");
        option = atoi(readInput("Enter your choice: "));

        switch(option) {
            case 1: addContact(&manager); break;
            case 2: displayContacts(manager); break;
            case 3: return 0;
            default: printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}