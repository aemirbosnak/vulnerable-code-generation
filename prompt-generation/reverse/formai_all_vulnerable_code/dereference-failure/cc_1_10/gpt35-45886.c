//FormAI DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50

// Define a struct for each email record
typedef struct EmailRecord {
    char email[MAX_EMAIL_LENGTH];
    struct EmailRecord* next; // next pointer for linked list
} EmailRecord;

// Function to add an email address to the linked list
void addEmail(EmailRecord** headRef, char* email) {
    // Allocate memory for new email record
    EmailRecord* newEmail = (EmailRecord*) malloc(sizeof(EmailRecord));
    // Copy email address into new record
    strcpy(newEmail->email, email);
    // Set the next pointer to NULL since this is a new record
    newEmail->next = NULL;

    // If the list is currently empty, set the head to the new record
    if (*headRef == NULL) {
        *headRef = newEmail;
    } else {
        // Otherwise, traverse the list to find the last record
        EmailRecord* lastEmail = *headRef;
        while (lastEmail->next != NULL) {
            lastEmail = lastEmail->next;
        }
        // Set the next pointer of the last record to the new record
        lastEmail->next = newEmail;
    }
}

// Function to delete an email address from the linked list
void deleteEmail(EmailRecord** headRef, char* email) {
    // Traverse the list to find the email record to delete
    EmailRecord* prevEmail = NULL;
    EmailRecord* currEmail = *headRef;
    while (currEmail != NULL) {
        if (strcmp(currEmail->email, email) == 0) {
            // Found email to delete, update prevEmail->next and free memory
            if (prevEmail == NULL) {
                // Deleting first record, update headRef
                *headRef = currEmail->next;
            } else {
                // Deleting record in middle or end of list
                prevEmail->next = currEmail->next;
            }
            free(currEmail);
            return; // exit function once delete is complete
        } else {
            // Haven't found email yet, keep searching
            prevEmail = currEmail;
            currEmail = currEmail->next;
        }
    }
    // If we get here, email was not found in the list
    printf("%s not found in list\n", email);
}

// Function to print all email addresses in the linked list
void printEmails(EmailRecord* head) {
    printf("List of Email Addresses:\n");
    while (head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}

// Function to read email addresses from a file and add to linked list
void readEmailsFromFile(char* filename, EmailRecord** headRef) {
    // Open file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    // Read email addresses from file and add to linked list
    char buffer[MAX_EMAIL_LENGTH];
    while (fgets(buffer, MAX_EMAIL_LENGTH, file)) {
        // Remove trailing newline character if present
        buffer[strcspn(buffer, "\n")] = 0;
        addEmail(headRef, buffer);
    }

    // Close file
    fclose(file);
}

// Function to write email addresses from linked list to a file
void writeEmailsToFile(char* filename, EmailRecord* head) {
    // Open file for writing
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    // Write email addresses from linked list to file
    while (head != NULL) {
        fprintf(file, "%s\n", head->email);
        head = head->next;
    }

    // Close file
    fclose(file);
}

int main() {
    // Initialize head of linked list to NULL
    EmailRecord* head = NULL;

    // Read initial email addresses from file
    readEmailsFromFile("emails.txt", &head);

    // Loop to manage user input until they choose to quit
    char input[MAX_EMAIL_LENGTH];
    while (1) {
        // Print menu of options
        printf("\nWhat would you like to do?\n");
        printf("1. Add an email address\n");
        printf("2. Delete an email address\n");
        printf("3. View all email addresses\n");
        printf("4. Save and quit\n");
        printf("Enter option number (1-4): ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            // Option 1: Add an email address
            printf("Enter email address to add: ");
            scanf("%s", input);
            addEmail(&head, input);
        } else if (strcmp(input, "2") == 0) {
            // Option 2: Delete an email address
            printf("Enter email address to delete: ");
            scanf("%s", input);
            deleteEmail(&head, input);
        } else if (strcmp(input, "3") == 0) {
            // Option 3: View all email addresses in list
            printEmails(head);
        } else if (strcmp(input, "4") == 0) {
            // Option 4: Save and quit
            printf("Saving changes and quitting...\n");
            writeEmailsToFile("emails.txt", head);
            exit(0);
        } else {
            // Invalid option entered, prompt again
            printf("Invalid option, please try again\n");
        }
    }

    return 0; // never reached, just to satisfy compiler
}