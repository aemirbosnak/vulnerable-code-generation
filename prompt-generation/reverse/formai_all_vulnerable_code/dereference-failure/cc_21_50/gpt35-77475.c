//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char email[50];
    char phone_number[20];
} Contact;

int main() {
    Contact* contacts[50];
    int num_of_contacts = 0;
    char user_input[10];

    printf("Welcome to the Futuristic Phone Book!\n");

    while (1) {
        printf("\n");
        printf("Choose an option:\n");
        printf("1. Add contact\n");
        printf("2. View contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. Quit\n");

        fgets(user_input, 10, stdin);

        if (strcmp(user_input, "1\n") == 0) {
            char name[50];
            char email[50];
            char phone_number[20];

            printf("Enter name:\n");
            fgets(name, 50, stdin);

            printf("Enter email:\n");
            fgets(email, 50, stdin);

            printf("Enter phone number:\n");
            fgets(phone_number, 20, stdin);

            Contact* new_contact = (Contact*) malloc(sizeof(Contact));
            strcpy(new_contact->name, name);
            strcpy(new_contact->email, email);
            strcpy(new_contact->phone_number, phone_number);

            contacts[num_of_contacts] = new_contact;
            num_of_contacts++;
        }
        else if (strcmp(user_input, "2\n") == 0) {
            if (num_of_contacts == 0) {
                printf("No contacts to view.\n");
            }
            else {
                printf("Enter contact name:\n");
                char contact_name[50];
                fgets(contact_name, 50, stdin);

                int found_contact = 0;

                for (int i = 0; i < num_of_contacts; i++) {
                    if (strcmp(contact_name, contacts[i]->name) == 0) {
                        printf("Name: %sEmail: %sPhone number: %s", contacts[i]->name, contacts[i]->email, contacts[i]->phone_number);
                        found_contact = 1;
                        break;
                    }
                }

                if (!found_contact) {
                    printf("Contact not found.\n");
                }
            }
        }
        else if (strcmp(user_input, "3\n") == 0) {
            if (num_of_contacts == 0) {
                printf("No contacts to edit.\n");
            }
            else {
                printf("Enter contact name:\n");
                char contact_name[50];
                fgets(contact_name, 50, stdin);

                int found_contact = 0;

                for (int i = 0; i < num_of_contacts; i++) {
                    if (strcmp(contact_name, contacts[i]->name) == 0) {

                        printf("What would you like to edit?\n");
                        printf("1. Name\n");
                        printf("2. Email\n");
                        printf("3. Phone number\n");

                        fgets(user_input, 10, stdin);

                        if (strcmp(user_input, "1\n") == 0) {
                            printf("Enter new name:\n");
                            fgets(contacts[i]->name, 50, stdin);
                        }
                        else if (strcmp(user_input, "2\n") == 0) {
                            printf("Enter new email:\n");
                            fgets(contacts[i]->email, 50, stdin);
                        }
                        else if (strcmp(user_input, "3\n") == 0) {
                            printf("Enter new phone number:\n");
                            fgets(contacts[i]->phone_number, 20, stdin);
                        }
                        else {
                            printf("Invalid option.\n");
                        }

                        found_contact = 1;
                        break;
                    }
                }

                if (!found_contact) {
                    printf("Contact not found.\n");
                }
            }
        }
        else if (strcmp(user_input, "4\n") == 0) {
            if (num_of_contacts == 0) {
                printf("No contacts to delete.\n");
            }
            else {
                printf("Enter contact name:\n");
                char contact_name[50];
                fgets(contact_name, 50, stdin);

                int found_contact = 0;

                for (int i = 0; i < num_of_contacts; i++) {
                    if (strcmp(contact_name, contacts[i]->name) == 0) {
                        free(contacts[i]);
                        num_of_contacts--;
                        found_contact = 1;
                        break;
                    }
                }

                if (!found_contact) {
                    printf("Contact not found.\n");
                }
            }
        }
        else if (strcmp(user_input, "5\n") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}