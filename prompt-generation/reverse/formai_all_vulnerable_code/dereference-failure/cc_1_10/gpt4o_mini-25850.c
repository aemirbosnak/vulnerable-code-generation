//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_CAPACITY 5

typedef struct {
    char **members;
    int count;
    int capacity;
} MailingList;

// Function prototypes
MailingList* createMailingList();
void addMember(MailingList *list, const char *name);
void removeMember(MailingList *list, const char *name);
void displayMembers(const MailingList *list);
void freeMailingList(MailingList *list);

int main() {
    MailingList *mailingList = createMailingList();
    char choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("Welcome to the Mailing List Manager!\n");
        printf("Choose an option:\n");
        printf("a) Add member\n");
        printf("r) Remove member\n");
        printf("d) Display members\n");
        printf("q) Quit\n");
        printf("Your choice: ");

        choice = getchar();
        getchar(); // Consume newline

        switch (choice) {
            case 'a':
                printf("Enter member name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                addMember(mailingList, name);
                break;
            case 'r':
                printf("Enter member name to remove: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                removeMember(mailingList, name);
                break;
            case 'd':
                displayMembers(mailingList);
                break;
            case 'q':
                freeMailingList(mailingList);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }

    return 0;
}

MailingList* createMailingList() {
    MailingList *list = malloc(sizeof(MailingList));
    list->count = 0;
    list->capacity = INITIAL_CAPACITY;
    list->members = malloc(sizeof(char*) * list->capacity);
    return list;
}

void addMember(MailingList *list, const char *name) {
    if (list->count == list->capacity) {
        list->capacity *= 2; // Double the capacity
        list->members = realloc(list->members, sizeof(char*) * list->capacity);
    }
    list->members[list->count] = malloc(strlen(name) + 1);
    strcpy(list->members[list->count], name);
    list->count++;
    printf("Added member: %s\n", name);
}

void removeMember(MailingList *list, const char *name) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i], name) == 0) {
            free(list->members[i]);
            list->members[i] = list->members[list->count - 1]; // Move last member to this spot
            list->count--;
            printf("Removed member: %s\n", name);
            return;
        }
    }
    printf("Member %s not found!\n", name);
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Current members of the mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->members[i]);
    }
}

void freeMailingList(MailingList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->members[i]);
    }
    free(list->members);
    free(list);
}