//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct word {
    char *word;
    struct word *next;
} word_t;

word_t *words = NULL;

void add_word(char *word) {
    word_t *new_word = (word_t *)malloc(sizeof(word_t));
    new_word->word = strdup(word);
    new_word->next = words;
    words = new_word;
}

void process_line(char *line) {
    char *token = strtok(line, " ");
    while (token != NULL) {
        add_word(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        process_line(line);
    }

    word_t *current = words;
    while (current != NULL) {
        printf("%s ", current->word);
        char *temp = current->word;
        int len = strlen(current->word);
        for (int i = 0; i < len / 2; i++) {
            char c = temp[i];
            temp[i] = temp[len - i - 1];
            temp[len - i - 1] = c;
        }
        current->word = temp;
        current = current->next;
    }

    printf("\n");

    word_t *temp_word = words;
    while (temp_word != NULL) {
        word_t *next_word = temp_word->next;
        free(temp_word->word);
        free(temp_word);
        temp_word = next_word;
    }

    return 0;
}