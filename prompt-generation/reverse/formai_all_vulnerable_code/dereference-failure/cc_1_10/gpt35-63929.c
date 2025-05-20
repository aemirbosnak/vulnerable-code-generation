//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void get_word(char* word, FILE* file) {
    int c;
    int i = 0;
    do {
        c = fgetc(file);
        if (c != EOF) {
            word[i++] = c;
        }
    } while (isalpha(c) || c == '\'');
    word[i] = '\0';
}

int count_word_occurrences(FILE* file, char* target_word) {
    char word[100];
    int count = 0;
    while (!feof(file)) {
        get_word(word, file);
        if (strcasecmp(word, target_word) == 0) {
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: cannot open file '%s'.\n", argv[1]);
        return 1;
    }
    int total_word_count = 0;
    int unique_word_count = 0;
    char word[100];
    int* counts = malloc(1000 * sizeof(int));
    char** words = malloc(1000 * sizeof(char*));
    for (int i = 0; i < 1000; i++) {
        counts[i] = 0;
        words[i] = malloc(100 * sizeof(char));
    }
    while (!feof(file)) {
        get_word(word, file);
        total_word_count++;
        if (strlen(word) > 0) {
            int found = 0;
            for (int i = 0; i < unique_word_count; i++) {
                if (strcasecmp(word, words[i]) == 0) {
                    counts[i]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                counts[unique_word_count]++;
                strcpy(words[unique_word_count], word);
                unique_word_count++;
            }
        }
    }
    printf("Total words: %d\n", total_word_count);
    printf("Unique words: %d\n", unique_word_count);
    printf("------------------------\n");
    printf("| Word\t| Frequency\t|\n");
    printf("|------|-------------|\n");
    for (int i = 0; i < unique_word_count; i++) {
        int frequency = (counts[i] * 100) / total_word_count;
        printf("| %s\t| %d%%\t\t|\n", words[i], frequency);
    }
    printf("------------------------\n");
    fclose(file);
    free(counts);
    for (int i = 0; i < 1000; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}