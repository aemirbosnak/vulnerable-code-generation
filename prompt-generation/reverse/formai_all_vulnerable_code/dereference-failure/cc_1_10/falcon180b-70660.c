//Falcon-180B DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(FILE *file, Word words[]) {
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                strncpy(words[MAX_WORDS - 1].word, word, MAX_WORD_LENGTH);
                words[MAX_WORDS - 1].count = 1;
            }
            word = strtok(NULL, " ");
        }
    }
}

void write_file(FILE *file, Word words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(file, "%s %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    Word words[MAX_WORDS];

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    read_file(input_file, words);
    write_file(output_file, words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}