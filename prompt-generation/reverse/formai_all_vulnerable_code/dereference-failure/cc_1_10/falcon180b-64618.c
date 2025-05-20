//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

void read_input(char *input_str, int *input_len) {
    printf("Enter a string: ");
    fgets(input_str, MAX_STR_LEN, stdin);
    *input_len = strlen(input_str) - 1;
}

void tokenize_string(char *input_str, int input_len, char **tokens, int *num_tokens) {
    char *token = strtok(input_str, " ");
    int i = 0;
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    *num_tokens = i;
}

void count_words(char **tokens, int num_tokens, WordCount *word_counts, int max_words) {
    int i, j;
    for (i = 0; i < num_tokens; i++) {
        for (j = 0; j < max_words; j++) {
            if (strcmp(tokens[i], word_counts[j].word) == 0) {
                word_counts[j].count++;
                break;
            }
        }
        if (j == max_words) {
            word_counts[j].word = strdup(tokens[i]);
            word_counts[j].count = 1;
            max_words++;
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char input_str[MAX_STR_LEN];
    int input_len;
    char *tokens[MAX_WORDS];
    int num_tokens;
    WordCount word_counts[MAX_WORDS];
    int max_words = 0;

    read_input(input_str, &input_len);
    tokenize_string(input_str, input_len, tokens, &num_tokens);
    count_words(tokens, num_tokens, word_counts, max_words);
    print_word_counts(word_counts, max_words);

    return 0;
}