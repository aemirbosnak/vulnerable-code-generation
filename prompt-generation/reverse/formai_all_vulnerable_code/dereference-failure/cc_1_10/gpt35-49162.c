//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define MAX_NAME_LEN and MAX_PHONE_NUM_LEN
#define MAX_NAME_LEN 20
#define MAX_PHONE_NUM_LEN 10

// Define a struct to hold contact information
typedef struct {
    char name[MAX_NAME_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
} Contact;

// Define a function to print all contacts in the "database"
void print_contacts(Contact *contacts, int num_contacts) {
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].phone_num);
    }
    printf("\n");
}

int main() {
    int num_contacts = 0;
    Contact *contacts = malloc(sizeof(Contact));

    // Prompt the user to enter a command
    char command;
    printf("Enter 'a' to add a contact or 'p' to print contacts: ");
    scanf(" %c", &command);

    while (command != 'q') {
        if (command == 'a') {
            // Prompt the user to enter a name and phone number
            char name[MAX_NAME_LEN];
            char phone_num[MAX_PHONE_NUM_LEN];
            printf("Enter a name (up to %d characters): ", MAX_NAME_LEN - 1);
            scanf("%s", name);
            printf("Enter a phone number (up to %d digits): ", MAX_PHONE_NUM_LEN - 1);
            scanf("%s", phone_num);

            // Create a new contact and add it to the "database"
            contacts[num_contacts].name[MAX_NAME_LEN - 1] = '\0';
            strncpy(contacts[num_contacts].name, name, MAX_NAME_LEN - 1);
            contacts[num_contacts].phone_num[MAX_PHONE_NUM_LEN - 1] = '\0';
            strncpy(contacts[num_contacts].phone_num, phone_num, MAX_PHONE_NUM_LEN - 1);
            num_contacts++;
            contacts = realloc(contacts, (num_contacts + 1) * sizeof(Contact));
        } else if (command == 'p') {
            // Print all contacts in the "database"
            print_contacts(contacts, num_contacts);
        }

        // Prompt the user to enter another command
        printf("Enter 'a' to add a contact or 'p' to print contacts: ");
        scanf(" %c", &command);
    }

    free(contacts);
    return 0;
}