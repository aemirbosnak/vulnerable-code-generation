//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    struct word_count word_counts[100];
    int num_words = 0;
    int word_index = 0;

    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words == 100) {
                    printf("Error: too many unique words.\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }

    fprintf(output_file, "Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}