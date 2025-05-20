//FormAI DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for mailing list entry
typedef struct mailing_list_entry {
    char name[50];
    char email[100];
    struct mailing_list_entry *next;
} Mailing_List_Entry;

// Function to create a new mailing list entry
Mailing_List_Entry* create_entry(char *name, char *email) {
    Mailing_List_Entry *new_entry = malloc(sizeof(Mailing_List_Entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    new_entry->next = NULL;
    return new_entry;
}

// Function to add a new entry to the mailing list
void add_to_list(Mailing_List_Entry **head, char *name, char *email) {
    if (*head == NULL) {
        *head = create_entry(name, email);
    } else {
        Mailing_List_Entry *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = create_entry(name, email);
    }
}

// Function to print all entries in the mailing list
void print_list(Mailing_List_Entry *head) {
    printf("Mailing List:\n");
    while (head != NULL) {
        printf("%s: %s\n", head->name, head->email);
        head = head->next;
    }
}

// Function to search for an entry in the mailing list by name
Mailing_List_Entry* search_list(Mailing_List_Entry *head, char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to remove an entry from the mailing list by name
void remove_from_list(Mailing_List_Entry **head, char *name) {
    Mailing_List_Entry *current = *head;
    Mailing_List_Entry *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Error: Entry not found in mailing list.\n");
}

// Main function
int main() {
    Mailing_List_Entry *head = NULL;
    int choice;
    char name[50], email[100];
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Search for entry\n");
        printf("4. Print all entries\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_to_list(&head, name, email);
                printf("Entry added to mailing list.\n");
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_from_list(&head, name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                Mailing_List_Entry *found = search_list(head, name);
                if (found != NULL) {
                    printf("%s: %s\n", found->name, found->email);
                } else {
                    printf("Entry not found in mailing list.\n");
                }
                break;
            case 4:
                print_list(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}