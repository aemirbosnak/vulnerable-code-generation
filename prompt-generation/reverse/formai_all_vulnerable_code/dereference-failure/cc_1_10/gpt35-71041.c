//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define struct for mailing list entry
struct mailing_list {
    char* name;
    char* email;
    struct mailing_list* next_address;
};

// Function to create a new entry for the mailing list
struct mailing_list* create_entry(char* name, char* email) {
    struct mailing_list* new_entry = malloc(sizeof(struct mailing_list));
    new_entry->name = name;
    new_entry->email = email;
    new_entry->next_address = NULL;
    printf("A chaotic entry has been added to the mailing list.\n");
    return new_entry;
}

// Function to add a new entry to the mailing list
void add_entry(struct mailing_list** list_head_ptr, char* name, char* email) {
    struct mailing_list* new_entry = create_entry(name, email);
    new_entry->next_address = *list_head_ptr;
    *list_head_ptr = new_entry;
}

// Function to print all entries in the mailing list
void print_entries(struct mailing_list* list_head) {
    printf("\nThe mailing list consists of:\n");
    while (list_head != NULL) {
        printf("- %s <%s>\n", list_head->name, list_head->email);
        printf("The mailing bot torments everyone in the list with a big letter saying: 'Beware the dark abyss of your soul'\n");
        list_head = list_head->next_address;
    }
    printf("\n");
}

int main() {

    // Create empty mailing list
    struct mailing_list* list_head = NULL;

    // Add some chaotic entries to the mailing list
    add_entry(&list_head, "Cthulhu", "cthulhu@elders.com");
    add_entry(&list_head, "Azathoth", "azathoth@outer.com");
    add_entry(&list_head, "Nyarlathotep", "nyarlathotep@many.com");
    add_entry(&list_head, "Dagon", "dagon@under.com");
    add_entry(&list_head, "Shub-Niggurath", "shub@black.com");

    // Print all entries in the mailing list
    print_entries(list_head);

    // Free memory allocated for the mailing list
    while (list_head != NULL) {
        struct mailing_list* current_entry = list_head;
        list_head = list_head->next_address;
        free(current_entry);
    }

    // Tell the user that the program has ended in a surreal way
    printf("The Mailing bot has been swallowed whole by the dark abyss of your soul. Goodbye!\n");
    return 0;
}