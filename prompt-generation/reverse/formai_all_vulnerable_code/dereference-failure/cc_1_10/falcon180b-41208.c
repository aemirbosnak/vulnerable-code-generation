//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_pair;

int main() {
    FILE *input_file, *output_file;
    char line[100];
    word_pair *word_pairs = malloc(MAX_WORDS * sizeof(word_pair));
    int num_word_pairs = 0;

    // Open input and output files
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Read in words and translations from input file
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        if (num_word_pairs >= MAX_WORDS) {
            printf("Error: too many word pairs.\n");
            exit(1);
        }
        char *token = strtok(line, " ");
        strcpy(word_pairs[num_word_pairs].word, token);
        token = strtok(NULL, " ");
        strcpy(word_pairs[num_word_pairs].translation, token);
        num_word_pairs++;
    }

    // Translate words in sentence
    char sentence[100];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_word_pairs; i++) {
            if (strcmp(word_pairs[i].word, token) == 0) {
                printf("%s ", word_pairs[i].translation);
                break;
            }
        }
        if (i == num_word_pairs) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}