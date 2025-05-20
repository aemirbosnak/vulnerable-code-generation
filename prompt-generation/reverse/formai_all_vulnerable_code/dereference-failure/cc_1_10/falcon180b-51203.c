//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void read_file(FILE *file, char *buffer, int *buffer_size) {
    int c;
    while ((c = fgetc(file))!= EOF) {
        if (*buffer_size == 0) {
            *buffer_size += 1000;
            buffer = realloc(buffer, *buffer_size);
        }
        buffer[*buffer_size - 1] = c;
        (*buffer_size)--;
    }
    buffer[*buffer_size] = '\0';
}

void tokenize(char *buffer, WordFrequency *word_frequencies, int num_words) {
    char *token = strtok(buffer, ",.?!;:");
    while (token!= NULL && num_words > 0) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_frequencies[i].word, token) == 0) {
                word_frequencies[i].frequency++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words == MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                exit(1);
            }
            word_frequencies[num_words].word = strdup(token);
            word_frequencies[num_words].frequency = 1;
            num_words++;
        }
        token = strtok(NULL, ",.?!;:");
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    char *buffer = NULL;
    int buffer_size = 0;
    read_file(file, buffer, &buffer_size);
    fclose(file);

    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;
    tokenize(buffer, word_frequencies, num_words);

    print_word_frequencies(word_frequencies, num_words);

    for (int i = 0; i < num_words; i++) {
        free(word_frequencies[i].word);
    }
    free(buffer);

    return 0;
}