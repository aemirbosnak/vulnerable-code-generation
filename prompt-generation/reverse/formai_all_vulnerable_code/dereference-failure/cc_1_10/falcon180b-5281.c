//Falcon-180B DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *word;
    int count;
} WordCount;

void print_word_counts(const char *filename, int num_words, WordCount *word_counts) {
    printf("Top %d most frequent words:\n", num_words);
    for (int i = 0; i < num_words; i++) {
        printf("%d. %s: %d\n", i + 1, word_counts[i].word, word_counts[i].count);
    }
}

bool compare_word_counts(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return wc1->count > wc2->count;
}

int main() {
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char ch;
    int num_words = 0;
    WordCount *word_counts = NULL;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            num_words++;
            if (num_words > 100) {
                break;
            }
            char *word = malloc(100);
            int word_len = 0;
            while (isalpha(ch)) {
                word[word_len++] = tolower(ch);
                ch = fgetc(file);
            }
            word[word_len] = '\0';
            WordCount *new_word_counts = realloc(word_counts, sizeof(WordCount) * num_words);
            if (new_word_counts == NULL) {
                printf("Error reallocating memory.\n");
                return 2;
            }
            word_counts = new_word_counts;
            word_counts[num_words - 1].word = word;
            word_counts[num_words - 1].count = 1;
        }
    }

    fclose(file);

    qsort(word_counts, num_words, sizeof(WordCount), compare_word_counts);

    print_word_counts(filename, num_words, word_counts);

    for (int i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return 0;
}