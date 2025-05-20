//Falcon-180B DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE* file, char* text) {
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    if (size > MAX_WORDS * MAX_WORD_LEN) {
        fprintf(stderr, "Error: File is too large.\n");
        exit(1);
    }

    fread(text, size, 1, file);
    text[size] = '\0';
}

void process_text(char* text, WordCount* word_counts) {
    char* word = strtok(text, ",.?!;:\"'");

    while (word!= NULL) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        if (strlen(word) > 0) {
            bool found = false;

            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                if (word_counts->count < MAX_WORDS) {
                    strcpy(word_counts->word, word);
                    word_counts->count = 1;
                }
            }
        }

        word = strtok(NULL, ",.?!;:\"'");
    }
}

void print_word_counts(WordCount* word_counts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char text[MAX_WORDS * MAX_WORD_LEN];
    read_file(fopen(argv[1], "r"), text);

    WordCount word_counts[MAX_WORDS];

    process_text(text, word_counts);
    print_word_counts(word_counts);

    return 0;
}