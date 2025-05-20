//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_EMAIL_SIZE 256

typedef struct MailingList {
    char **emails;
    int size;
} MailingList;

MailingList *create_list() {
    MailingList *list = malloc(sizeof(MailingList));
    list->emails = malloc(MAX_LIST_SIZE * sizeof(char *));
    list->size = 0;
    return list;
}

void add_email(MailingList *list, const char *email) {
    if (list->size < MAX_LIST_SIZE) {
        list->emails[list->size] = malloc(strlen(email) + 1);
        strcpy(list->emails[list->size], email);
        list->size++;
        printf("Added: %s\n", email);
    } else {
        printf("List is full! Can't add more emails.\n");
    }
}

void remove_email(MailingList *list, const char *email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            for (int j = i; j < list->size - 1; j++) {
                list->emails[j] = list->emails[j + 1];
            }
            list->size--;
            printf("Removed: %s\n", email);
            return;
        }
    }
    printf("Email '%s' not found!\n", email);
}

void display_list(MailingList *list) {
    if (list->size == 0) {
        printf("Mailing list is empty!\n");
    } else {
        printf("Mailing List (%d emails):\n", list->size);
        for (int i = 0; i < list->size; i++) {
            printf("%d: %s\n", i + 1, list->emails[i]);
        }
    }
}

void free_list(MailingList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

int main() {
    MailingList *my_list = create_list();
    char command[10];
    char email[MAX_EMAIL_SIZE];

    printf("Welcome to the Puzzle Mailing List Manager!\n");
    printf("Commands: add <email>, remove <email>, show, exit\n");

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            add_email(my_list, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            remove_email(my_list, email);
        } else if (strcmp(command, "show") == 0) {
            display_list(my_list);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Puzzle Mailing List Manager.\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    free_list(my_list);
    return 0;
}