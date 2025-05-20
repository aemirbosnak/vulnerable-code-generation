//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 100000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} WordCount;

int is_stop_word(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 1;
        }
    }
    return 0;
}

int compare_word_counts(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return wc2->count - wc1->count;
}

int main() {
    FILE *input_file, *output_file;
    char line[100];
    char *token;
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (strlen(token) >= MIN_WORD_LEN && strlen(token) <= MAX_WORD_LEN &&!is_stop_word(token)) {
                for (i = 0; i < num_words; i++) {
                    if (strcmp(words[i].word, token) == 0) {
                        words[i].count++;
                        break;
                    }
                }
                if (i == num_words) {
                    if (num_words >= MAX_WORDS) {
                        printf("Error: Too many unique words.\n");
                        exit(1);
                    }
                    strcpy(words[num_words].word, token);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    qsort(words, num_words, sizeof(WordCount), compare_word_counts);

    fprintf(output_file, "Word\tCount\n");
    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}