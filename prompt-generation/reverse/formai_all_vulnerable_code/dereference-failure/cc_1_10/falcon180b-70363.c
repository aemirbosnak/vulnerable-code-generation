//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int num_words = 0;
    WordCount words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &len, file))!= -1) {
        char *token;
        char *saveptr;
        int i;

        num_words = 0;
        for (token = strtok_r(line, " ", &saveptr); token!= NULL; token = strtok_r(NULL, " ", &saveptr)) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words in file.\n");
                fclose(file);
                return 1;
            }

            strncpy(words[num_words].word, token, MAX_WORD_LENGTH);
            words[num_words].count = 1;

            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, words[num_words].word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            num_words++;
        }
    }

    fclose(file);

    printf("Total number of words: %d\n", num_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}