//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define NUM_WORDS 100

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *head = NULL;

void add_word(char *word) {
    Word *new_word = (Word *) malloc(sizeof(Word));
    new_word->word = strdup(word);
    new_word->next = head;
    head = new_word;
}

void print_list() {
    Word *current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        free(current->word);
        Word *next = current->next;
        free(current);
        current = next;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            add_word(strdup(token));
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    print_list();

    Word *current = head;
    while (current != NULL) {
        Word *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }

    return 0;
}