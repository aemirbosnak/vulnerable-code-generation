//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *word;
    int count;
} WordFrequency;

#define INITIAL_SIZE 10

void to_lowercase(char *str) {
    for (char *p = str; *p; ++p) {
        *p = tolower(*p);
    }
}

int compare(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *)a;
    WordFrequency *wf2 = (WordFrequency *)b;
    return wf2->count - wf1->count; // Descending order
}

void add_word(WordFrequency **list, int *size, int *capacity, const char *word) {
    for (int i = 0; i < *size; ++i) {
        if (strcmp((*list)[i].word, word) == 0) {
            (*list)[i].count++;
            return;
        }
    }

    if (*size >= *capacity) {
        *capacity *= 2;
        *list = realloc(*list, (*capacity) * sizeof(WordFrequency));
    }

    (*list)[*size].word = strdup(word);
    (*list)[*size].count = 1;
    (*size)++;
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    WordFrequency *wordList = malloc(INITIAL_SIZE * sizeof(WordFrequency));
    int size = 0, capacity = INITIAL_SIZE;
    char buffer[256];

    while (fscanf(file, "%255s", buffer) == 1) {
        to_lowercase(buffer);
        add_word(&wordList, &size, &capacity, buffer);
    }

    fclose(file);

    qsort(wordList, size, sizeof(WordFrequency), compare);

    printf("Word Frequency Count:\n");
    for (int i = 0; i < size; ++i) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
        free(wordList[i].word); // Free the duplicated string
    }
    
    free(wordList);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    return EXIT_SUCCESS;
}