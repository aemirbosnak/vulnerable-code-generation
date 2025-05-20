//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_SENTENCE_SIZE 1000

struct word_count {
    char word[MAX_WORD_SIZE];
    int count;
};

void read_file(FILE *file, char *buffer, int max_size) {
    int ch;
    int index = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (index >= max_size - 1) {
            fprintf(stderr, "Error: sentence is too long.\n");
            exit(1);
        }
        buffer[index++] = tolower(ch);
    }
    buffer[index] = '\0';
}

void tokenize_sentence(char *sentence, struct word_count *word_counts, int num_word_counts) {
    char *token;
    char *context = sentence;
    int num_tokens = 0;

    while ((token = strtok_r(context, " \t\n\r\f", &context))) {
        if (num_tokens >= num_word_counts) {
            fprintf(stderr, "Error: too many words in sentence.\n");
            exit(1);
        }
        strncpy(word_counts[num_tokens].word, token, MAX_WORD_SIZE);
        word_counts[num_tokens].count = 1;
        num_tokens++;
    }
}

void print_word_counts(struct word_count *word_counts, int num_word_counts) {
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file.\n");
        return 1;
    }

    char buffer[MAX_SENTENCE_SIZE];
    read_file(file, buffer, MAX_SENTENCE_SIZE);

    struct word_count word_counts[100];
    int num_word_counts = 0;

    tokenize_sentence(buffer, word_counts, num_word_counts);

    print_word_counts(word_counts, num_word_counts);

    return 0;
}