//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a mailing list
typedef struct mailing_list {
    char name[50];
    char description[200];
    char* members[100];
    int num_members;
} mailing_list;

// Function to create a new mailing list
mailing_list* create_mailing_list(char* name, char* description) {
    mailing_list* list = malloc(sizeof(mailing_list));
    strcpy(list->name, name);
    strcpy(list->description, description);
    list->num_members = 0;
    return list;
}

// Function to add a member to a mailing list
void add_member(mailing_list* list, char* member) {
    list->members[list->num_members] = malloc(strlen(member) + 1);
    strcpy(list->members[list->num_members], member);
    list->num_members++;
}

// Function to remove a member from a mailing list
void remove_member(mailing_list* list, char* member) {
    int i;
    for (i = 0; i < list->num_members; i++) {
        if (strcmp(list->members[i], member) == 0) {
            free(list->members[i]);
            list->members[i] = list->members[list->num_members - 1];
            list->num_members--;
            break;
        }
    }
}

// Function to print the members of a mailing list
void print_members(mailing_list* list) {
    int i;
    for (i = 0; i < list->num_members; i++) {
        printf("%s\n", list->members[i]);
    }
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list* list = create_mailing_list("Cyberpunks", "A list for all things cyberpunk");

    // Add some members to the list
    add_member(list, "Neo");
    add_member(list, "Trinity");
    add_member(list, "Morpheus");

    // Print the members of the list
    printf("Members of the %s mailing list:\n", list->name);
    print_members(list);

    // Remove a member from the list
    remove_member(list, "Trinity");

    // Print the members of the list again
    printf("\nMembers of the %s mailing list after removing Trinity:\n", list->name);
    print_members(list);

    return 0;
}