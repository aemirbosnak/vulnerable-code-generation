//Falcon-180B DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(FILE *fp, char *filename, WordCount *word_counts, int max_words) {
    char line[MAX_WORD_LEN];
    char *word;
    int i = 0;

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        word = strtok(line, ",.?!;\n");
        while (word!= NULL && i < max_words) {
            if (strlen(word) > 0) {
                word[strcspn(word, "0123456789")] = '\0'; // Remove any numbers from the end of the word
                for (int j = 0; j < strlen(word); j++) {
                    word[j] = tolower(word[j]); // Convert word to lowercase
                }
                int found = 0;
                for (int k = 0; k < i; k++) {
                    if (strcmp(word_counts[k].word, word) == 0) {
                        word_counts[k].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    if (i >= max_words) {
                        printf("Error: Maximum number of words (%d) reached.\n", max_words);
                        exit(1);
                    }
                    word_counts[i].word = strdup(word);
                    word_counts[i].count = 1;
                    i++;
                }
            }
            word = strtok(NULL, ",.?!;\n");
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <max_words>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int max_words = atoi(argv[2]);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    WordCount word_counts[MAX_WORDS];
    read_file(fp, filename, word_counts, max_words);

    fclose(fp);
    print_word_counts(word_counts, max_words);

    return 0;
}