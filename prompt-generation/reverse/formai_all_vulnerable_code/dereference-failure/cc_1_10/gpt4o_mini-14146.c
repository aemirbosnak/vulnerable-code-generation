//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char **emails;
    int size;
    int capacity;
} MailingList;

// Function declarations
MailingList* create_mailing_list();
void free_mailing_list(MailingList *list);
void add_email(MailingList *list, const char *email);
void remove_email(MailingList *list, const char *email);
void display_emails(const MailingList *list);
int email_exists(const MailingList *list, const char *email);

// Entry point
int main() {
    MailingList *list = create_mailing_list();
    int choice;

    printf("Welcome to the Mailing List Manager! 🎉\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Emails\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clearing input buffer

        char email[MAX_EMAIL_LENGTH];

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                strtok(email, "\n"); // Remove newline character
                add_email(list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                strtok(email, "\n"); // Remove newline character
                remove_email(list, email);
                break;
            case 3:
                printf("Current emails in the list:\n");
                display_emails(list);
                break;
            case 4:
                printf("Exiting the Mailing List Manager. Goodbye! 👋\n");
                break;
            default:
                printf("Unexpected choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    free_mailing_list(list);
    return 0;
}

// Create a new mailing list
MailingList* create_mailing_list() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->emails = (char **)malloc(list->capacity * sizeof(char *));
    return list;
}

// Free the mailing list
void free_mailing_list(MailingList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

// Add an email to the mailing list
void add_email(MailingList *list, const char *email) {
    if (email_exists(list, email)) {
        printf("Email %s already exists in the list! 🛑\n", email);
        return;
    }

    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->emails = (char **)realloc(list->emails, list->capacity * sizeof(char *));
    }

    list->emails[list->size] = (char *)malloc((strlen(email) + 1) * sizeof(char));
    strcpy(list->emails[list->size], email);
    list->size++;
    printf("Email %s added successfully! 🎯\n", email);
}

// Remove an email from the mailing list
void remove_email(MailingList *list, const char *email) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            list->emails[i] = list->emails[list->size - 1];
            list->size--;
            found = 1;
            printf("Email %s removed successfully! ✅\n", email);
            break;
        }
    }
    if (!found) {
        printf("Email %s not found in the list! ❌\n", email);
    }
}

// Display all emails in the mailing list
void display_emails(const MailingList *list) {
    if (list->size == 0) {
        printf("No emails in the list! 📭\n");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

// Check if an email exists in the mailing list
int email_exists(const MailingList *list, const char *email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            return 1;
        }
    }
    return 0;
}