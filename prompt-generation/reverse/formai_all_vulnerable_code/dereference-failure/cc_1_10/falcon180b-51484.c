//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 32

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compare_words(const void* a, const void* b) {
    WordCount* word_a = (WordCount*)a;
    WordCount* word_b = (WordCount*)b;

    return strcmp(word_a->word, word_b->word);
}

void print_word_counts(WordCount* word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(WordCount), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE* file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    WordCount word_counts[MAX_WORD_SIZE];
    int num_words = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int len = strlen(line);
        if (len == 0 || line[len - 1]!= '\n') {
            printf("Error reading line.\n");
            exit(1);
        }

        char* word = strtok(line, " ");
        while (word!= NULL) {
            int word_len = strlen(word);
            if (word_len > MAX_WORD_SIZE) {
                printf("Word too long: %s\n", word);
                exit(1);
            }

            for (int i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (num_words >= MAX_WORD_SIZE) {
                printf("Too many words.\n");
                exit(1);
            }

            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;

            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    print_word_counts(word_counts, num_words);

    return 0;
}