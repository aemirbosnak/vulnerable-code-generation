//Falcon-180B DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void read_file(FILE *file) {
    char ch;
    int word_length = 0;
    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[word_length] = tolower(ch);
            word_length++;
        } else if (word_length > 0) {
            word[word_length] = '\0';
            strcpy(words[num_words], word);
            num_words++;
            word_length = 0;
        }
    }

    if (word_length > 0) {
        word[word_length] = '\0';
        strcpy(words[num_words], word);
        num_words++;
    }

    free(word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file);
    fclose(file);

    printf("Number of words: %d\n", num_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}