//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

/* Define the data structure */
typedef struct script_s {
    int index;
    char *character;
    char *dialogue;
    struct script_s *next;
} script;

/* Function to add character's dialogue to the script */
void add_script(script **head, int index, char *character, char *dialogue) {
    script *current = *head;
    script *new_script = malloc(sizeof(script));

    new_script->index = index;
    new_script->character = character;
    new_script->dialogue = dialogue;
    new_script->next = NULL;

    if (current == NULL) {
        *head = new_script;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_script;
    }
}

/* Function to print the script */
void print_script(script **head) {
    script *current = *head;
    printf("===============================\n");
    printf("SCRIPT\n");
    printf("===============================\n");
    while (current != NULL) {
        printf("INDEX: %d\n", current->index);
        printf("CHARACTER: %s\n", current->character);
        printf("DIALOGUE: %s\n", current->dialogue);
        printf("===============================\n");
        current = current->next;
    }
}

int main() {
    /* Creating the script */
    script *head = NULL;
    add_script(&head, 1, "SHERLOCK HOLMES", "It is a capital mistake to theorize before one has data. Insensibly one begins to twist facts to suit theories instead of theories to suit facts.");
    add_script(&head, 2, "DR. JOHN WATSON", "No man burdens his mind with small matters unless he has some very good reason for doing so.");
    add_script(&head, 3, "SHERLOCK HOLMES", "The game is afoot.");

    /* Print the script */
    print_script(&head);

    /* Free the memory */
    script *current = head;
    while (current != NULL) {
        script *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}