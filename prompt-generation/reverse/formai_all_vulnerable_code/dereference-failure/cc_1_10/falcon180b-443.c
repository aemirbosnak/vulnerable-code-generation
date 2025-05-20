//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename, WordCount words[]) {
    char line[MAX_WORD_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (i >= MAX_WORDS) {
                break;
            }
            strcpy(words[i].word, token);
            words[i].count = 1;
            i++;
            token = strtok(NULL, " ");
        }
    }
}

void write_file(FILE *file, WordCount words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(file, "%s %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_WORD_LENGTH], output_filename[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    read_file(input_file, input_filename, words);

    write_file(output_file, words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}