//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

typedef struct {
    char* word;
    int count;
} WordCount;

void word_count(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file. ");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file. ");
        exit(1);
    }

    char* line = NULL;
    size_t line_size = 0;

    WordCount word_counts[MAX_WORD_LENGTH];
    int num_words = 0;

    while (getline(&line, &line_size, input)!= -1) {
        char* word = strtok(line, " \t\r\n\f\v,.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words == MAX_WORD_LENGTH) {
                    printf("Error: too many unique words. ");
                    exit(1);
                }
                word_counts[num_words].word = strdup(word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, " \t\r\n\f\v,.?!;:");
        }
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(output, "%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    word_count(argv[1], argv[2]);

    return 0;
}