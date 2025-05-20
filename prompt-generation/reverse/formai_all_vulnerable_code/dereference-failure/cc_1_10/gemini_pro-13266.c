//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: retro
/*
* Mailman - A vintage mailing list manager (c) 1985
*/

#include <stdio.h>
#include <stdlib.h>

/* The structure of a mailing list entry */
struct entry {
    char name[32];         /* Name of the subscriber */
    char email[64];        /* Email address of the subscriber */
    struct entry *next;    /* Pointer to the next entry in the list */
};

/* The head of the mailing list */
struct entry *head = NULL;

/* Add a new subscriber to the mailing list */
void add_subscriber(char *name, char *email) {
    struct entry *new_entry = malloc(sizeof(struct entry));
    if (new_entry == NULL) {
        printf("Error: Not enough memory to add a new subscriber.\n");
        return;
    }
    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    new_entry->next = head;
    head = new_entry;
}

/* Print the mailing list */
void print_mailing_list() {
    struct entry *current_entry = head;
    while (current_entry != NULL) {
        printf("%s (%s)\n", current_entry->name, current_entry->email);
        current_entry = current_entry->next;
    }
}

/* Send a message to all subscribers on the mailing list */
void send_message(char *message) {
    struct entry *current_entry = head;
    while (current_entry != NULL) {
        printf("Sending message to %s (%s):\n\n", current_entry->name, current_entry->email);
        printf("%s\n\n", message);
        current_entry = current_entry->next;
    }
}

/* Main function */
int main() {
    /* Add some subscribers to the mailing list */
    add_subscriber("John Doe", "john.doe@example.com");
    add_subscriber("Jane Doe", "jane.doe@example.com");
    add_subscriber("Bob Smith", "bob.smith@example.com");

    /* Print the mailing list */
    printf("Mailing list:\n");
    print_mailing_list();

    /* Send a message to all subscribers on the mailing list */
    printf("\nSending message:\n\n");
    printf("Hello everyone,\n\n");
    printf("This is just a test message to make sure that the mailing list is working properly.\n\n");
    printf("Please let me know if you have any questions.\n\n");
    printf("Thanks,\n");
    printf("The Mailman\n");
    send_message("Hello everyone,\n\nThis is just a test message to make sure that the mailing list is working properly.\n\nPlease let me know if you have any questions.\n\nThanks,\nThe Mailman");

    return 0;
}