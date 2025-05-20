//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Defines the maximum number of contacts in the mailing list
#define MAX_CONTACTS 100

// Defines the maximum length of a contact's name and email address
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Defines the structure of a contact in the mailing list
typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

// Defines the structure of the mailing list
typedef struct mailing_list {
    contact contacts[MAX_CONTACTS];
    int num_contacts;
} mailing_list;

// Function to create a new mailing list
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->num_contacts = 0;
    return list;
}

// Function to add a new contact to the mailing list
void add_contact(mailing_list* list, char* name, char* email) {
    if (list->num_contacts < MAX_CONTACTS) {
        strcpy(list->contacts[list->num_contacts].name, name);
        strcpy(list->contacts[list->num_contacts].email, email);
        list->num_contacts++;
    } else {
        printf("Error: Mailing list is full\n");
    }
}

// Function to remove a contact from the mailing list
void remove_contact(mailing_list* list, char* name) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            // Shift the contacts after the one being removed to the left
            for (int j = i; j < list->num_contacts - 1; j++) {
                list->contacts[j] = list->contacts[j + 1];
            }
            list->num_contacts--;
            break;
        }
    }
}

// Function to send an email to all contacts in the mailing list
void send_email(mailing_list* list, char* subject, char* message) {
    for (int i = 0; i < list->num_contacts; i++) {
        // Simulate sending an email using printf
        printf("To: %s <%s>\n", list->contacts[i].name, list->contacts[i].email);
        printf("Subject: %s\n", subject);
        printf("Message: %s\n\n", message);
    }
}

// Function to print the contacts in the mailing list
void print_contacts(mailing_list* list) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("%s <%s>\n", list->contacts[i].name, list->contacts[i].email);
    }
}

// Function to generate a random name
char* generate_random_name() {
    // Define an array of possible characters for the name
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* name = malloc(MAX_NAME_LENGTH);

    // Generate a random length for the name
    int name_length = rand() % MAX_NAME_LENGTH + 1;

    // Generate the name
    for (int i = 0; i < name_length; i++) {
        name[i] = characters[rand() % (sizeof(characters) - 1)];
    }

    // Terminate the name with a null character
    name[name_length] = '\0';

    return name;
}

// Function to generate a random email address
char* generate_random_email_address() {
    // Define an array of possible characters for the email address
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char* email = malloc(MAX_EMAIL_LENGTH);

    // Generate a random length for the email address
    int email_length = rand() % MAX_EMAIL_LENGTH + 1;

    // Generate the email address
    for (int i = 0; i < email_length; i++) {
        email[i] = characters[rand() % (sizeof(characters) - 1)];
    }

    // Terminate the email address with a null character
    email[email_length] = '\0';

    // Add the "@" symbol to the email address
    strcat(email, "@example.com");

    return email;
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Create a new mailing list
    mailing_list* list = create_mailing_list();

    // Add 10 random contacts to the mailing list
    for (int i = 0; i < 10; i++) {
        char* name = generate_random_name();
        char* email = generate_random_email_address();
        add_contact(list, name, email);
    }

    // Print the contacts in the mailing list
    printf("Contacts:\n");
    print_contacts(list);

    // Send an email to all contacts in the mailing list
    send_email(list, "Test Subject", "Test Message");

    // Remove a contact from the mailing list
    remove_contact(list, "John Doe");

    // Print the contacts in the mailing list
    printf("\nContacts:\n");
    print_contacts(list);

    // Free the memory allocated for the mailing list
    free(list);

    return 0;
}