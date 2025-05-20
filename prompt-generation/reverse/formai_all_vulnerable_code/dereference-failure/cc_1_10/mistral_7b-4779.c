//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *words = NULL;
int wordCount = 0;

void addWord(char *word) {
    Word *newWord = (Word *) malloc(sizeof(Word));
    if (newWord == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newWord->word = strdup(word);
    newWord->next = words;
    words = newWord;

    wordCount++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[4096];
    int inWord = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        int i, len;
        for (i = 0; i < strlen(buffer); i++) {
            if (isspace(buffer[i])) {
                if (inWord) {
                    buffer[i] = '\0';
                    len = i;
                    char *word = strndup(&buffer[0], len);
                    addWord(word);
                    free(word);
                    i = len;
                    inWord = 0;
                }
            } else {
                inWord = 1;
            }
        }

        if (inWord) {
            char *wordEnd = strchr(&buffer[0], '\n');
            if (wordEnd != NULL) {
                *wordEnd = '\0';
                char *word = strndup(&buffer[0], wordEnd - &buffer[0]);
                addWord(word);
                free(word);
            }
        }
    }

    fclose(file);

    printf("Word count: %d\n", wordCount);

    Word *current = words;
    while (current != NULL) {
        printf("%s ", current->word);
        Word *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }

    free(words);

    return EXIT_SUCCESS;
}