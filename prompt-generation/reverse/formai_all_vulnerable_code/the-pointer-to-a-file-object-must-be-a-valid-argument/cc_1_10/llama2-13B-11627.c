//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_COUNT 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char *word;
    int count;
} word_t;

word_t words[MAX_WORD_COUNT];
int word_count = 0;

void load_words(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *word = strtok(line, " ");

        while (word != NULL) {
            int i = 0;
            for (i = 0; i < word_count; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == word_count) {
                words[word_count].word = word;
                words[word_count].count = 1;
                word_count++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(file);
}

void print_word_counts() {
    for (int i = 0; i < word_count; i++) {
        printf("%d. %s\n", i + 1, words[i].word);
    }
}

int main() {
    srand(time(NULL));

    load_words("example.txt");

    print_word_counts();

    return 0;
}