//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *text) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            text[i++] = tolower(ch);
        }
    }

    text[i] = '\0';
}

int compare_words(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(WordCount), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[100];
    char text[1000000];

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, text);

    char *word = strtok(text, ",.?!;:");

    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    while (word!= NULL) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }

        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        strcpy(word_counts[num_words].word, word);
        word_counts[num_words].count = 1;
        num_words++;

        word = strtok(NULL, ",.?!;:");
    }

    print_word_counts(word_counts, num_words);

    return 0;
}