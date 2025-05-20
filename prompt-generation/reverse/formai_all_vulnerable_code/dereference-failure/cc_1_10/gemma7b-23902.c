//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <string.h>

// Define the structure of a mailing list entry
typedef struct mailing_list_entry {
    char name[255];
    char email[255];
    struct mailing_list_entry* next;
} mailing_list_entry;

// Define the functions to manage the mailing list
void insert_entry(mailing_list_entry** head, char* name, char* email);
void print_entries(mailing_list_entry* head);
void search_entries(mailing_list_entry* head, char* name);

int main() {
    mailing_list_entry* head = NULL;

    // Insert some entries
    insert_entry(&head, "John Doe", "john.doe@example.com");
    insert_entry(&head, "Jane Doe", "jane.doe@example.com");
    insert_entry(&head, "Bob Smith", "bob.smith@example.com");

    // Print the entries
    print_entries(head);

    // Search for an entry
    search_entries(head, "Jane Doe");

    return 0;
}

void insert_entry(mailing_list_entry** head, char* name, char* email) {
    mailing_list_entry* new_entry = malloc(sizeof(mailing_list_entry));

    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    new_entry->next = NULL;

    if (*head == NULL) {
        *head = new_entry;
    } else {
        (*head)->next = new_entry;
    }
}

void print_entries(mailing_list_entry* head) {
    while (head) {
        printf("%s (%s)\n", head->name, head->email);
        head = head->next;
    }
}

void search_entries(mailing_list_entry* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("%s (%s)\n", head->name, head->email);
        }
        head = head->next;
    }
}