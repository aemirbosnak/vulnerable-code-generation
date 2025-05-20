//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} word_t;

word_t words[MAX_WORDS];
int num_words;

void read_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        char *word = strdup(line);
        if (word == NULL) {
            perror("Error allocating memory for word");
            exit(1);
        }

        word[strlen(word) - 1] = '\0'; // Remove newline character

        words[num_words].word = word;
        words[num_words].count = 0;
        num_words++;
    }

    fclose(fp);
}

void count_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening text file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
    }

    fclose(fp);
}

void print_results() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        exit(1);
    }

    read_dictionary(argv[1]);
    count_words(argv[2]);
    print_results();

    return 0;
}