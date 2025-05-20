//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char **argv) {
    FILE *file;
    char *filename;
    char *line;
    char *word;
    WordCount word_counts[MAX_WORD_COUNT];
    int num_words = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    while ((line = fgets(line, MAX_WORD_LENGTH, file))!= NULL) {
        word = strtok(line, " \t\r\n");

        while (word!= NULL) {
            if (num_words >= MAX_WORD_COUNT) {
                printf("Error: Too many words in file '%s'\n", filename);
                fclose(file);
                exit(1);
            }

            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;

            num_words++;

            word = strtok(NULL, " \t\r\n");
        }
    }

    fclose(file);

    printf("Word Count:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}