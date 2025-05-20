//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_LINE_LENGTH 10000
#define MAX_FILE_SIZE 1000000

char *sentence;
int sentence_length;
char *translated_sentence;
int translated_sentence_length;

void init() {
    sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    translated_sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
}

void read_file(FILE *file) {
    sentence_length = 0;
    while (fgets(sentence + sentence_length, MAX_LINE_LENGTH - sentence_length, file)!= NULL) {
        sentence_length += strlen(sentence + sentence_length);
    }
}

void translate() {
    int i;
    for (i = 0; i < sentence_length; i++) {
        if (isalpha(sentence[i])) {
            translated_sentence[i] = sentence[i] + 'a' - 'A';
        } else {
            translated_sentence[i] = sentence[i];
        }
    }
    translated_sentence_length = sentence_length;
}

void write_file(FILE *file) {
    fwrite(translated_sentence, sizeof(char), translated_sentence_length, file);
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
        return 1;
    }

    init();
    read_file(input_file);
    translate();
    write_file(output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}