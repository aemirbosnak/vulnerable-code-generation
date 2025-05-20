//Gemma-7B DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void analyze_text(char **text, int size) {
    int i, j, word_count = 0, character_count = 0;
    char **words = NULL;

    for (i = 0; i < size; i++) {
        for (j = 0; text[i][j] != '\0'; j++) {
            character_count++;
            if (text[i][j] == ' ') {
                word_count++;
            }
        }
    }

    words = malloc(word_count * sizeof(char *));
    word_count = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; text[i][j] != '\0'; j++) {
            if (text[i][j] == ' ') {
                words[word_count++] = malloc((character_count + 1) * sizeof(char));
                character_count = 0;
            }
            words[word_count - 1][character_count++] = text[i][j];
        }
        words[word_count++] = NULL;
    }

    printf("Word Count: %d\n", word_count);
    printf("Character Count: %d\n", character_count);
    printf("Words:\n");

    for (i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
    }

    free(words);
}

int main() {
    char **text = malloc(MAX_SIZE * sizeof(char *));
    text[0] = "This is a sample text. It has many words.";

    analyze_text(text, MAX_SIZE);

    free(text);

    return 0;
}