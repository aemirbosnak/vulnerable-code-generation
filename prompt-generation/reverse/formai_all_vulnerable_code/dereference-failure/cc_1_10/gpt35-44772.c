//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define our phonebook struct */
typedef struct phonebook {
    char name[50];
    char number[20];
    struct phonebook *next;
} phonebook;

/* Function to add a new entry to the phonebook */
phonebook *add_entry(phonebook *head, char *name, char *number) {
    /* Allocate memory for the new entry */
    phonebook *new_entry = malloc(sizeof(phonebook));
    if (new_entry == NULL) {
        fprintf(stderr, "Error: unable to allocate memory\n");
        exit(1);
    }

    /* Copy the name and number into the new entry */
    strncpy(new_entry->name, name, sizeof(new_entry->name) - 1);
    strncpy(new_entry->number, number, sizeof(new_entry->number) - 1);
    new_entry->next = NULL;

    /* If we're adding the first entry, set it as the head */
    if (head == NULL) {
        head = new_entry;
    }
    /* Otherwise, traverse to the end of the list and add the new entry */
    else {
        phonebook *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }

    return head;
}

/* Function to print all entries in the phonebook */
void print_entries(phonebook *head) {
    /* Traverse through the list and print each entry */
    phonebook *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

/* Function to delete an entry from the phonebook */
phonebook *delete_entry(phonebook *head, char *name) {
    /* If the head is null, nothing to delete */
    if (head == NULL) {
        return NULL;
    }

    /* If the head matches the name to delete, set the next entry as the new head */
    if (strcmp(head->name, name) == 0) {
        phonebook *next_entry = head->next;
        free(head);
        return next_entry;
    }

    /* Traverse through the list and delete the specified entry */
    phonebook *previous = head;
    phonebook *current = head->next;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            previous->next = current->next;
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }

    /* If we've reached this point, the name isn't in the phonebook */
    fprintf(stderr, "Error: entry '%s' not found in phonebook\n", name);
    return head;
}

int main() {
    phonebook *head = NULL;
    char buffer[100];
    char *name, *number;

    /* Simple command-line interface to interact with the phonebook */
    while (1) {
        printf("-> ");
        fgets(buffer, sizeof(buffer), stdin);
        if (feof(stdin)) {
            break;
        }
        if (buffer[0] == 'a') {
            /* Add an entry: "a <name> <number>" */
            name = strtok(buffer + 2, " \n");
            number = strtok(NULL, " \n");
            head = add_entry(head, name, number);
        }
        else if (buffer[0] == 'p') {
            /* Print all entries: "p" */
            print_entries(head);
        }
        else if (buffer[0] == 'd') {
            /* Delete an entry: "d <name>" */
            name = strtok(buffer + 2, " \n");
            head = delete_entry(head, name);
        }
        else if (buffer[0] == 'q') {
            /* Quit: "q" */
            break;
        }
        else {
            /* Unrecognized command */
            fprintf(stderr, "Unrecognized command: '%c'\n", buffer[0]);
        }
    }

    /* Free memory allocated for the phonebook */
    phonebook *current = head;
    while (current != NULL) {
        phonebook *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}