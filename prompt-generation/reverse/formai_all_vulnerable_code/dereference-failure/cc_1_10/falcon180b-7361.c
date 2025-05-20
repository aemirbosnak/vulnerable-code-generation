//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *buffer) {
    int ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (i < MAX_WORD_LENGTH) {
            if (isalpha(ch)) {
                buffer[i++] = tolower(ch);
            } else {
                buffer[i] = '\0';
                i = 0;
            }
        }
    }
    if (i > 0) {
        buffer[i] = '\0';
    }
}

void count_words(char *buffer, WordCount *word_counts, int n) {
    char *word = strtok(buffer, ",.?!");
    while (word!= NULL) {
        int i;
        for (i = 0; i < n; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == n) {
            if (n < MAX_WORDS) {
                strcpy(word_counts[n].word, word);
                word_counts[n].count = 1;
                n++;
            }
        }
        word = strtok(NULL, ",.?!");
    }
}

void print_word_counts(WordCount *word_counts, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int n = 0;

    read_file(file, buffer);
    count_words(buffer, word_counts, n);

    print_word_counts(word_counts, n);

    fclose(file);
    return 0;
}