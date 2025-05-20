//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a note
typedef struct note {
    char *title;
    char *content;
    struct note *next;
} note;

// Function to create a new note
note *create_note(char *title, char *content) {
    note *new_note = (note *)malloc(sizeof(note));
    new_note->title = (char *)malloc(strlen(title) + 1);
    strcpy(new_note->title, title);
    new_note->content = (char *)malloc(strlen(content) + 1);
    strcpy(new_note->content, content);
    new_note->next = NULL;
    return new_note;
}

// Function to add a new note to the diary
void add_note(note **head, char *title, char *content) {
    note *new_note = create_note(title, content);
    if (*head == NULL) {
        *head = new_note;
    } else {
        note *current_note = *head;
        while (current_note->next != NULL) {
            current_note = current_note->next;
        }
        current_note->next = new_note;
    }
}

// Function to print the diary
void print_diary(note *head) {
    if (head == NULL) {
        printf("Your diary is empty.\n");
    } else {
        note *current_note = head;
        while (current_note != NULL) {
            printf("Title: %s\n", current_note->title);
            printf("Content: %s\n\n", current_note->content);
            current_note = current_note->next;
        }
    }
}

// Function to search for a note by title
note *search_note(note *head, char *title) {
    note *current_note = head;
    while (current_note != NULL) {
        if (strcmp(current_note->title, title) == 0) {
            return current_note;
        }
        current_note = current_note->next;
    }
    return NULL;
}

// Function to edit a note
void edit_note(note *note, char *new_content) {
    free(note->content);
    note->content = (char *)malloc(strlen(new_content) + 1);
    strcpy(note->content, new_content);
}

// Function to delete a note
void delete_note(note **head, char *title) {
    if (*head == NULL) {
        return;
    } else if (strcmp((*head)->title, title) == 0) {
        note *temp = *head;
        *head = (*head)->next;
        free(temp->title);
        free(temp->content);
        free(temp);
    } else {
        note *current_note = *head;
        while (current_note->next != NULL) {
            if (strcmp(current_note->next->title, title) == 0) {
                note *temp = current_note->next;
                current_note->next = current_note->next->next;
                free(temp->title);
                free(temp->content);
                free(temp);
                break;
            }
            current_note = current_note->next;
        }
    }
}

int main() {
    // Create a new diary
    note *head = NULL;

    // Add some notes to the diary
    add_note(&head, "My first note", "This is my first note.");
    add_note(&head, "My second note", "This is my second note.");

    // Print the diary
    printf("Your diary:\n");
    print_diary(head);

    // Search for a note by title
    note *found_note = search_note(head, "My first note");
    if (found_note != NULL) {
        printf("Found note:\n");
        printf("Title: %s\n", found_note->title);
        printf("Content: %s\n", found_note->content);
    } else {
        printf("Note not found.\n");
    }

    // Edit a note
    edit_note(found_note, "This is my edited note.");

    // Print the diary again
    printf("Your diary:\n");
    print_diary(head);

    // Delete a note
    delete_note(&head, "My second note");

    // Print the diary again
    printf("Your diary:\n");
    print_diary(head);

    return 0;
}