//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_input(FILE *input_file, struct word_count *word_counts) {
    char line[MAX_WORD_LENGTH];
    int word_index = 0;
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (word_index >= MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                exit(1);
            }
            strcpy(word_counts[word_index].word, word);
            word_counts[word_index].count = 1;
            word_index++;
            word = strtok(NULL, ",.!?;:");
        }
    }
}

void write_output(struct word_count *word_counts) {
    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    struct word_count word_counts[MAX_WORDS];
    read_input(input_file, word_counts);
    write_output(word_counts);
    fclose(input_file);
    fclose(output_file);
    return 0;
}