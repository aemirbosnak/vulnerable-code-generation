//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *line, int max_length) {
    fgets(line, max_length, file);
    if (line[strcspn(line, "\r\n")]!= '\0') {
        fprintf(stderr, "Line too long: %s\n", line);
        exit(1);
    }
    line[strcspn(line, "\r\n")] = '\0';
}

void tokenize(char *line, char *words[], int max_words) {
    char *word = strtok(line, ",.!?;:\"'()[]{}<>");
    int num_words = 0;
    while (word!= NULL && num_words < max_words) {
        if (strlen(word) > 0) {
            words[num_words] = word;
            num_words++;
        }
        word = strtok(NULL, ",.!?;:\"'()[]{}<>");
    }
}

void count_words(char *words[], int num_words, WordCount counts[], int max_counts) {
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < max_counts; j++) {
            if (strcmp(words[i], counts[j].word) == 0) {
                counts[j].count++;
                break;
            }
        }
        if (counts[max_counts - 1].count == 0) {
            strcpy(counts[max_counts - 1].word, words[i]);
            counts[max_counts - 1].count = 1;
        }
    }
}

void print_counts(WordCount counts[], int num_counts) {
    for (int i = 0; i < num_counts; i++) {
        if (counts[i].count > 0) {
            printf("%s: %d\n", counts[i].word, counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    WordCount counts[MAX_NUM_WORDS];
    int num_counts = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        read_file(file, line, MAX_LINE_LENGTH);
        tokenize(line, counts[num_counts].word, MAX_WORD_LENGTH);
        count_words(counts[num_counts].word, 1, counts, MAX_NUM_WORDS);
        num_counts++;
    }

    fclose(file);
    print_counts(counts, num_counts);

    return 0;
}