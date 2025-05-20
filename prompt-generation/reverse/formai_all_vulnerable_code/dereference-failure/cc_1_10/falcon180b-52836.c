//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    FILE *input_fp, *output_fp;
    WordTranslation words[MAX_WORDS];
    int num_words = 0;
    char line[MAX_WORD_LENGTH];
    char *word, *translation;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input and output files
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file '%s'\n", input_file);
        exit(1);
    }
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file '%s'\n", output_file);
        exit(1);
    }

    // Read input file and store translations in array
    while (fgets(line, MAX_WORD_LENGTH, input_fp)!= NULL) {
        word = strtok(line, " ");
        translation = strtok(NULL, " ");
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in input file\n");
            exit(1);
        }
        strcpy(words[num_words].word, word);
        strcpy(words[num_words].translation, translation);
        num_words++;
    }

    // Write translations to output file
    for (int i = 0; i < num_words; i++) {
        fprintf(output_fp, "%s %s\n", words[i].word, words[i].translation);
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    printf("Translation complete!\n");
    return 0;
}