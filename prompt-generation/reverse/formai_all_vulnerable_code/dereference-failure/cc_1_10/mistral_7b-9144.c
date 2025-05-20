//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *head = NULL;

void loadDictionary() {
    FILE *file = fopen("dictionary.txt", "r");
    char line[1024];
    Word *newWord = NULL;

    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        size_t len = strlen(line);
        line[len - 1] = '\0'; // Remove newline character

        newWord = (Word *) malloc(sizeof(Word));
        newWord->word = (char *) malloc((len + 1) * sizeof(char));
        strcpy(newWord->word, line);
        newWord->next = head;
        head = newWord;
    }

    fclose(file);
}

bool isInDictionary(char *word) {
    Word *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

int main() {
    loadDictionary();

    char input[1024];
    bool validWord = false;

    printf("Welcome to the irregular C Spell Checker!\n");
    printf("Please type the words you want to check, separated by spaces.\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printf("\nYour input: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        validWord = isInDictionary(input);

        if (validWord) {
            printf("'%s' is a valid word.\n", input);
        } else {
            printf("'%s' is not a valid word. You may have made a typo.\n", input);
        }
    }

    // Free memory allocated for linked list
    Word *current = head;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current->word);
        free(current);
    }

    return 0;
}