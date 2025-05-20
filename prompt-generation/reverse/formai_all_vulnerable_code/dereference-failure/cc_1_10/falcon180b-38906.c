//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

typedef struct {
    char word[WORD_LENGTH];
    int count;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void print_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char **argv) {
    char word[WORD_LENGTH];
    char input_file[100];
    char output_file[100];
    FILE *in, *out;

    if (argc!= 4) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    in = fopen(input_file, "r");
    if (in == NULL) {
        printf("Error: Could not open input file!\n");
        exit(1);
    }

    out = fopen(output_file, "w");
    if (out == NULL) {
        printf("Error: Could not open output file!\n");
        exit(1);
    }

    while (fscanf(in, "%s", word)!= EOF) {
        add_word(word);
    }

    fclose(in);
    fclose(out);

    print_words();

    return 0;
}