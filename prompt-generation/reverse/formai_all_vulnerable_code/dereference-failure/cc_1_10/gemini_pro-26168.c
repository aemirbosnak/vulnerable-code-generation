//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Data structure to store a contact
typedef struct Contact {
    char name[50];
    char email[50];
} Contact;

// Data structure to store a mailing list
typedef struct MailingList {
    Contact *contacts;
    int num_contacts;
    int capacity;
} MailingList;

// Function to create a new mailing list
MailingList *create_mailing_list() {
    MailingList *list = malloc(sizeof(MailingList));
    list->contacts = malloc(10 * sizeof(Contact));
    list->num_contacts = 0;
    list->capacity = 10;
    return list;
}

// Function to add a contact to a mailing list
void add_contact(MailingList *list, Contact *contact) {
    if (list->num_contacts == list->capacity) {
        // Reallocate the array of contacts to double the capacity
        list->contacts = realloc(list->contacts, 2 * list->capacity * sizeof(Contact));
        list->capacity *= 2;
    }

    // Add the contact to the array
    list->contacts[list->num_contacts] = *contact;
    list->num_contacts++;
}

// Function to remove a contact from a mailing list
void remove_contact(MailingList *list, char *name) {
    // Find the index of the contact to remove
    int index = -1;
    for (int i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the contact was not found, return
    if (index == -1) {
        return;
    }

    // Shift the contacts after the one to remove to the left
    for (int i = index; i < list->num_contacts - 1; i++) {
        list->contacts[i] = list->contacts[i + 1];
    }

    // Decrement the number of contacts
    list->num_contacts--;
}

// Function to print a mailing list
void print_mailing_list(MailingList *list) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("%s <%s>\n", list->contacts[i].name, list->contacts[i].email);
    }
}

// Function to send an email to all contacts on a mailing list
void send_email(MailingList *list, char *subject, char *body) {
    // Iterate over the contacts and send an email to each one
    for (int i = 0; i < list->num_contacts; i++) {
        // Send the email using your preferred email sending library
    }
}

// Function to get a valid email address from the user
char *get_email_address() {
    char *email = malloc(50 * sizeof(char));
    while (1) {
        printf("Enter an email address: ");
        scanf("%s", email);

        // Check if the email address is valid
        int valid = 1;
        for (int i = 0; i < strlen(email); i++) {
            if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.' && email[i] != '_') {
                valid = 0;
                break;
            }
        }

        if (valid) {
            break;
        } else {
            printf("Invalid email address. Please try again.\n");
        }
    }

    return email;
}

// Function to get a valid name from the user
char *get_name() {
    char *name = malloc(50 * sizeof(char));
    while (1) {
        printf("Enter a name: ");
        scanf("%s", name);

        // Check if the name is valid
        int valid = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i]) && name[i] != ' ') {
                valid = 0;
                break;
            }
        }

        if (valid) {
            break;
        } else {
            printf("Invalid name. Please try again.\n");
        }
    }

    return name;
}

int main() {
    // Create a new mailing list
    MailingList *list = create_mailing_list();

    // Get the user's choice
    int choice = 0;
    while (choice != 4) {
        printf("\n1. Add a contact\n2. Remove a contact\n3. Print the mailing list\n4. Send an email\n5. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform the user's choice
        switch (choice) {
            case 1:
                {
                    // Get the contact's name and email address
                    Contact contact;
                    strcpy(contact.name, get_name());
                    strcpy(contact.email, get_email_address());

                    // Add the contact to the mailing list
                    add_contact(list, &contact);

                    printf("Contact added successfully.\n");
                }
                break;
            case 2:
                {
                    // Get the contact's name
                    char name[50];
                    printf("Enter the name of the contact to remove: ");
                    scanf("%s", name);

                    // Remove the contact from the mailing list
                    remove_contact(list, name);

                    printf("Contact removed successfully.\n");
                }
                break;
            case 3:
                // Print the mailing list
                print_mailing_list(list);
                break;
            case 4:
                {
                    // Get the email subject and body
                    char subject[50];
                    char body[255];
                    printf("Enter the subject of the email: ");
                    scanf("%s", subject);
                    printf("Enter the body of the email: ");
                    scanf(" %[^\n]%*c", body);

                    // Send the email to all contacts on the mailing list
                    send_email(list, subject, body);

                    printf("Email sent successfully.\n");
                }
                break;
            case 5:
                // Quit the program
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    // Free the memory allocated for the mailing list
    free(list->contacts);
    free(list);

    return 0;
}