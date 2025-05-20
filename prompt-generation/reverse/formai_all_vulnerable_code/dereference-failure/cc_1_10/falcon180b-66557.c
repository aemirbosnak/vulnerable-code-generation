//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_WORDS 100

typedef struct {
    char *word;
    int position;
} Word;

typedef struct {
    char *text;
    int size;
    int num_words;
    Word *words;
} Text;

void read_text(Text *text) {
    char buffer[MAX_SIZE];
    char *token;
    int i = 0;

    printf("Enter text: ");
    fgets(buffer, MAX_SIZE, stdin);

    text->text = malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(text->text, buffer);

    text->size = strlen(text->text);
    text->num_words = 0;

    token = strtok(text->text, " ");
    while (token!= NULL) {
        if (text->num_words >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        text->words[text->num_words].word = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(text->words[text->num_words].word, token);

        text->words[text->num_words].position = i;
        text->num_words++;

        i += strlen(token) + 1; // +1 for space or newline

        token = strtok(NULL, " ");
    }
}

void search_word(Text *text, char *query) {
    int i;
    Word *result = NULL;

    for (i = 0; i < text->num_words; i++) {
        if (strcmp(text->words[i].word, query) == 0) {
            result = &text->words[i];
            break;
        }
    }

    if (result == NULL) {
        printf("Word not found.\n");
    } else {
        printf("Word found at position %d.\n", result->position);
    }
}

int main() {
    Text text;
    char query[MAX_SIZE];

    read_text(&text);

    while (1) {
        printf("Enter word to search: ");
        fgets(query, MAX_SIZE, stdin);

        search_word(&text, query);
    }

    return 0;
}