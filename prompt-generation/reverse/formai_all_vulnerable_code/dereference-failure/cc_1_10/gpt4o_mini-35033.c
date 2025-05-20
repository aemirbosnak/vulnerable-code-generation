//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 100
#define INITIAL_CAPACITY 10

typedef struct {
    char **emails;
    size_t size;
    size_t capacity;
} MailingList;

// Function prototypes
MailingList* create_list();
void free_list(MailingList *list);
int add_subscriber(MailingList *list, const char *email);
int remove_subscriber(MailingList *list, const char *email);
void display_subscribers(const MailingList *list);
void resize_list(MailingList *list);

// Main program
int main() {
    MailingList *list = create_list();
    int choice;
    char email[MAX_EMAIL_SIZE];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character after integer input

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline character
                if (add_subscriber(list, email)) {
                    printf("Subscriber '%s' added.\n", email);
                } else {
                    printf("Failed to add subscriber '%s'.\n", email);
                }
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline character
                if (remove_subscriber(list, email)) {
                    printf("Subscriber '%s' removed.\n", email);
                } else {
                    printf("Subscriber '%s' not found.\n", email);
                }
                break;
            case 3:
                display_subscribers(list);
                break;
            case 4:
                free_list(list);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function implementations
MailingList* create_list() {
    MailingList *list = malloc(sizeof(MailingList));
    list->emails = malloc(INITIAL_CAPACITY * sizeof(char*));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void free_list(MailingList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

int add_subscriber(MailingList *list, const char *email) {
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            return 0; // Subscriber already exists
        }
    }
    
    if (list->size == list->capacity) {
        resize_list(list);
    }
    
    list->emails[list->size] = malloc((strlen(email) + 1) * sizeof(char));
    strcpy(list->emails[list->size], email);
    list->size++;
    return 1; // Successfully added
}

void resize_list(MailingList *list) {
    list->capacity *= 2;
    list->emails = realloc(list->emails, list->capacity * sizeof(char*));
}

int remove_subscriber(MailingList *list, const char *email) {
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            list->emails[i] = list->emails[list->size - 1];  // Move last email to the place
            list->size--;
            return 1; // Successfully removed
        }
    }
    return 0; // Email not found
}

void display_subscribers(const MailingList *list) {
    printf("Current Subscribers:\n");
    if (list->size == 0) {
        printf("No subscribers.\n");
        return;
    }
    for (size_t i = 0; i < list->size; i++) {
        printf("%s\n", list->emails[i]);
    }
}