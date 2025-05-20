//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts, int num_words) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                WordCount new_word_count;
                strcpy(new_word_count.word, token);
                new_word_count.count = 1;
                word_counts = realloc(word_counts, sizeof(WordCount) * (num_words + 1));
                memmove(word_counts + num_words, word_counts, sizeof(WordCount) * num_words);
                word_counts[num_words] = new_word_count;
                num_words++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void write_file(FILE* file, WordCount* word_counts, int num_words) {
    fprintf(file, "Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    int num_words = 0;
    WordCount* word_counts = NULL;

    read_file(input_file, word_counts, num_words);

    write_file(output_file, word_counts, num_words);

    fclose(input_file);
    fclose(output_file);

    free(word_counts);

    return 0;
}