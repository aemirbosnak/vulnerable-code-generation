//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORDS_PER_LINE 50

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i, j, words_per_line = 0;
    Word *words = malloc(MAX_WORDS_PER_LINE * sizeof(Word));

    if (words == NULL) {
        printf("Error: Could not allocate memory for words.\n");
        return 1;
    }

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        i = 0;
        while (i < strlen(line)) {
            if (isspace(line[i])) {
                line[i] = '\0';
                words[words_per_line].word = strdup(&line[j]);
                words[words_per_line].length = i - j;
                words_per_line++;
                i++;
                j = i;
            } else {
                i++;
            }
        }
    }

    fclose(file);

    for (i = 0; i < words_per_line; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    free(words);

    return 0;
}