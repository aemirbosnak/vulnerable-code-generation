//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_word_char(char c) {
    return isalnum(c) || c == '\'';
}

void process_text(const char *filename, WordCount counts[], int *total_unique_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \n\t.,;:!?()-\"");
        while (token != NULL) {
            to_lowercase(token);
            if (is_word_char(token[0])) {
                int found = 0;
                for (int i = 0; i < *total_unique_words; i++) {
                    if (strcmp(counts[i].word, token) == 0) {
                        counts[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found && *total_unique_words < MAX_WORDS) {
                    strcpy(counts[*total_unique_words].word, token);
                    counts[*total_unique_words].count = 1;
                    (*total_unique_words)++;
                }
            }
            token = strtok(NULL, " \n\t.,;:!?()-\"");
        }
    }

    fclose(file);
}

void sort_word_counts(WordCount counts[], int total_unique_words) {
    for (int i = 0; i < total_unique_words - 1; i++) {
        for (int j = 0; j < total_unique_words - i - 1; j++) {
            if (counts[j].count < counts[j + 1].count) {
                WordCount temp = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = temp;
            }
        }
    }
}

void print_top_words(const WordCount counts[], int total_unique_words, int top_n) {
    printf("Top %d words:\n", top_n);
    for (int i = 0; i < top_n && i < total_unique_words; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <top_n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    int top_n = atoi(argv[2]);
    if (top_n <= 0) {
        fprintf(stderr, "Error: top_n must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    WordCount counts[MAX_WORDS] = {0};
    int total_unique_words = 0;

    process_text(filename, counts, &total_unique_words);
    sort_word_counts(counts, total_unique_words);
    print_top_words(counts, total_unique_words, top_n);

    return 0;
}