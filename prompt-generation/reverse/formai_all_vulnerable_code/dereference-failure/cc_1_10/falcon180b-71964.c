//Falcon-180B DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *input_file, *output_file;
    char line[MAX_WORD_LEN + 1];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    // Open input and output files
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file and count word occurrences
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(words[num_words].word, token);
                words[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Write output file
    fprintf(output_file, "Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\t%d\n", words[i].word, words[i].count);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}