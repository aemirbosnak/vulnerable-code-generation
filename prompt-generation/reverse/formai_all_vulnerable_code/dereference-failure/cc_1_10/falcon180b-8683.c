//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename, WordCount *word_counts, int num_words) {
    char line[1024];
    char word[MAX_WORD_LENGTH];
    int i, j;

    while (fgets(line, sizeof(line), file)!= NULL) {
        i = 0;
        while ((j = strcspn(line, " \t\r\n\f\v"))!= 0) {
            if (i >= MAX_WORD_LENGTH) {
                break;
            }
            word[i++] = tolower(line[j]);
            line[j] = '\0';
        }
        word[i] = '\0';

        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
    }
}

void display_word_counts(WordCount *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[1024];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    while (num_words < MAX_WORDS && fgets(filename, sizeof(filename), file)!= NULL) {
        if (filename[0]!= '#') {
            strcpy(word_counts[num_words].word, filename);
            num_words++;
        }
    }

    fclose(file);

    read_file(file, filename, word_counts, num_words);
    display_word_counts(word_counts, num_words);

    return 0;
}