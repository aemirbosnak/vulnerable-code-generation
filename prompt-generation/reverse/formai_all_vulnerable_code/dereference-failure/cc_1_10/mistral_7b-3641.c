//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: Cryptic
#define _CRYPTIC_SPELL_CHECK_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _word {
    char *word;
    struct _word *next;
} word_t;

void _load_dictionary(word_t **head) {
    FILE *fp;
    char line[128];
    word_t *new_word, *current;

    if (!(fp = fopen("dictionary.txt", "r"))) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        size_t len = strlen(line);
        if (line[len - 1] == '\n') line[--len] = '\0';

        new_word = (word_t *)malloc(sizeof(word_t));
        new_word->word = malloc(len + 1);
        strcpy(new_word->word, line);
        new_word->next = NULL;

        if (*head == NULL) {
            *head = new_word;
            continue;
        }

        current = *head;
        while (current->next != NULL) current = current->next;
        current->next = new_word;
    }

    fclose(fp);
}

int _is_valid_word(char *word, word_t *head) {
    word_t *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) return 1;
        current = current->next;
    }

    return 0;
}

int main() {
#define INPUT_SIZE 1024
    char input[INPUT_SIZE];
    word_t *head = NULL;

    _load_dictionary(&head);

    while (1) {
        printf("Enter word to check or type 'quit' to exit: ");
        fgets(input, INPUT_SIZE, stdin);

        if (strchr(input, '\n') == NULL) {
            printf("Invalid input, please try again.\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "quit") == 0) break;

        int valid = _is_valid_word(input, head);

        if (valid) printf("Word is valid\n");
        else printf("Word is not valid\n");
    }

    while (head != NULL) {
        word_t *temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }

    return EXIT_SUCCESS;
}