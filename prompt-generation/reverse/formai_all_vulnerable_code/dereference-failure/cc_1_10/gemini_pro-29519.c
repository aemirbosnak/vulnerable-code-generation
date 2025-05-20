//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int count;
} Word;

Word *words[MAX_WORDS];
int word_count = 0;

int compare_words(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    return strcmp(word1->word, word2->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(words[i]->word, word) == 0) {
                    words[i]->count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                words[word_count] = malloc(sizeof(Word));
                words[word_count]->word = strdup(word);
                words[word_count]->count = 1;
                word_count++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(words, word_count, sizeof(Word), compare_words);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->count);
        free(words[i]->word);
        free(words[i]);
    }

    return EXIT_SUCCESS;
}