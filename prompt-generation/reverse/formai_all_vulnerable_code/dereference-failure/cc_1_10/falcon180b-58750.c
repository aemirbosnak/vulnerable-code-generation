//Falcon-180B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename, WordCount words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            words[i].word[strlen(words[i].word) - 1] = '\0';
            i++;
        } else {
            strncat(words[i].word, &ch, 1);
        }
    }

    words[i].word[strlen(words[i].word) - 1] = '\0';
    words[i].count = 1;
}

void write_file(FILE *fp, WordCount words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(fp, "%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    WordCount words[MAX_WORDS];
    read_file(input_file, argv[1], words);
    write_file(output_file, words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}