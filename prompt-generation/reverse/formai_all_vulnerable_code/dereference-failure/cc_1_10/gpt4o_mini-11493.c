//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define BUFFER_SIZE 256

typedef struct {
    char **emails;
    int size;
    int capacity;
} MailingList;

// Function prototypes
MailingList* create_mailing_list();
void add_email(MailingList *list, const char *email);
void remove_email(MailingList *list, const char *email);
void list_emails(MailingList *list);
void free_mailing_list(MailingList *list);
int email_exists(MailingList *list, const char *email);
void resize_list(MailingList *list, int new_capacity);
void print_menu();

int main() {
    MailingList *list = create_mailing_list();
    char email[BUFFER_SIZE];
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, BUFFER_SIZE, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                add_email(list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, BUFFER_SIZE, stdin);
                email[strcspn(email, "\n")] = 0; 
                remove_email(list, email);
                break;
            case 3:
                list_emails(list);
                break;
            case 4:
                free_mailing_list(list);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

MailingList* create_mailing_list() {
    MailingList *list = malloc(sizeof(MailingList));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->emails = malloc(list->capacity * sizeof(char*));
    return list;
}

void add_email(MailingList *list, const char *email) {
    if (email_exists(list, email)) {
        printf("Email already exists.\n");
        return;
    }
    if (list->size >= list->capacity) {
        resize_list(list, list->capacity * 2);
    }
    list->emails[list->size] = strdup(email);
    list->size++;
    printf("Email added successfully.\n");
}

void remove_email(MailingList *list, const char *email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            for (int j = i; j < list->size - 1; j++) {
                list->emails[j] = list->emails[j + 1];
            }
            list->size--;
            printf("Email removed successfully.\n");
            return;
        }
    }
    printf("Email not found in the list.\n");
}

void list_emails(MailingList *list) {
    if (list->size == 0) {
        printf("No emails in the mailing list.\n");
        return;
    }
    printf("Mailing List Emails:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list->emails[i]);
    }
}

void resize_list(MailingList *list, int new_capacity) {
    list->capacity = new_capacity;
    list->emails = realloc(list->emails, new_capacity * sizeof(char*));
}

int email_exists(MailingList *list, const char *email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            return 1; // Email exists
        }
    }
    return 0; // Email does not exist
}

void free_mailing_list(MailingList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
    printf("Mailing list freed successfully.\n");
}

void print_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Email\n");
    printf("2. Remove Email\n");
    printf("3. List Emails\n");
    printf("4. Exit\n");
}