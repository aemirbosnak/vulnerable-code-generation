//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_words(FILE *file, struct word words[], int *num_words) {
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (i >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    *num_words = i;
}

void find_misspelled_words(struct word words[], int num_words, FILE *output_file) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (words[i].count > 1) {
            fprintf(output_file, "Possible misspelling: %s\n", words[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    struct word words[MAX_WORDS];
    int num_words;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    read_words(input_file, words, &num_words);
    find_misspelled_words(words, num_words, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}