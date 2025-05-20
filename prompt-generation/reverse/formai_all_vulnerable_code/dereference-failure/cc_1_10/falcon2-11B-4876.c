//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information of a mailing list member
struct MailingListMember {
    char name[50];
    char email[50];
};

// Structure to hold information of the mailing list
struct MailingList {
    char name[50];
    int size;
    struct MailingListMember* members;
};

// Function to add a new member to the mailing list
void add_member(struct MailingList* list, char* name, char* email) {
    struct MailingListMember* new_member = malloc(sizeof(struct MailingListMember));
    strcpy(new_member->name, name);
    strcpy(new_member->email, email);

    if (list->size >= list->members - 1) {
        list->members = realloc(list->members, (list->size + 1) * sizeof(struct MailingListMember));
    }

    list->members[list->size] = *new_member;
    list->size++;
}

// Function to display the mailing list
void display_list(struct MailingList* list) {
    printf("Mailing List: %s\n", list->name);
    printf("Total Members: %d\n", list->size);
    for (int i = 0; i < list->size; i++) {
        printf("Member %d: %s (%s)\n", i+1, list->members[i].name, list->members[i].email);
    }
}

int main() {
    struct MailingList* list = malloc(sizeof(struct MailingList));
    strcpy(list->name, "My Mailing List");
    list->size = 0;
    list->members = NULL;

    add_member(list, "Alice", "alice@example.com");
    add_member(list, "Bob", "bob@example.com");
    add_member(list, "Charlie", "charlie@example.com");

    display_list(list);

    free(list);

    return 0;
}