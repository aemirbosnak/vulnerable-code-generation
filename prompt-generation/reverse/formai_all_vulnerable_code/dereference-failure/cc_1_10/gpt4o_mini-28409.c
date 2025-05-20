//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256
#define INITIAL_CAPACITY 10

typedef struct {
    char **emails;
    int size;
    int capacity;
} MailingList;

// Function prototypes
MailingList* create_mailing_list();
void destroy_mailing_list(MailingList* list);
void add_email(MailingList* list, const char* email);
void remove_email(MailingList* list, const char* email);
void view_emails(MailingList* list);
void expand_capacity(MailingList* list);

int main() {
    MailingList* list = create_mailing_list();
    int choice;
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("\nMailing List Manager:\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. View Emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                strtok(email, "\n"); // Remove newline character
                add_email(list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                strtok(email, "\n");
                remove_email(list, email);
                break;
            case 3:
                view_emails(list);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    destroy_mailing_list(list);
    return 0;
}

MailingList* create_mailing_list() {
    MailingList* list = (MailingList*)malloc(sizeof(MailingList));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->emails = (char**)malloc(sizeof(char*) * list->capacity);
    return list;
}

void destroy_mailing_list(MailingList* list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

void add_email(MailingList* list, const char* email) {
    if (list->size == list->capacity) {
        expand_capacity(list);
    }
    list->emails[list->size] = (char*)malloc(strlen(email) + 1);
    strcpy(list->emails[list->size], email);
    list->size++;
    printf("Email '%s' added successfully.\n", email);
}

void remove_email(MailingList* list, const char* email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            list->emails[i] = list->emails[list->size - 1];
            list->size--;
            printf("Email '%s' removed successfully.\n", email);
            return;
        }
    }
    printf("Email '%s' not found in the mailing list.\n", email);
}

void view_emails(MailingList* list) {
    if (list->size == 0) {
        printf("No emails in the mailing list.\n");
        return;
    }
    printf("Current mailing list emails:\n");
    for (int i = 0; i < list->size; i++) {
        printf("- %s\n", list->emails[i]);
    }
}

void expand_capacity(MailingList* list) {
    list->capacity *= 2;
    list->emails = (char**)realloc(list->emails, sizeof(char*) * list->capacity);
}