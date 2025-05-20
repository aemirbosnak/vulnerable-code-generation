//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *word;
    struct Node *next;
};

struct Dictionary {
    struct Node *head;
};

struct Dictionary *create_dictionary(char *filepath) {
    struct Dictionary *dictionary = malloc(sizeof(struct Dictionary));
    dictionary->head = NULL;

    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filepath);
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *word = strdup(line);
        word[strlen(word) - 1] = '\0';  // Remove newline character

        struct Node *node = malloc(sizeof(struct Node));
        node->word = word;
        node->next = dictionary->head;
        dictionary->head = node;
    }

    fclose(file);

    return dictionary;
}

void free_dictionary(struct Dictionary *dictionary) {
    struct Node *current = dictionary->head;
    while (current) {
        struct Node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }

    free(dictionary);
}

int check_spelling(char *word, struct Dictionary *dictionary) {
    struct Node *current = dictionary->head;
    while (current) {
        if (strcmp(word, current->word) == 0) {
            return 1;  // Word is spelled correctly
        }
        current = current->next;
    }

    return 0;  // Word is not spelled correctly
}

int main() {
    // Create a dictionary
    struct Dictionary *dictionary = create_dictionary("dictionary.txt");
    if (!dictionary) {
        return 1;
    }

    // Get a word from the user
    char word[1024];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(word, dictionary);

    // Print the result
    if (is_correct) {
        printf("Yay! The word '%s' is spelled correctly.\n", word);
    } else {
        printf("Oops! The word '%s' is not spelled correctly.\n", word);
    }

    // Free the dictionary
    free_dictionary(dictionary);

    return 0;
}