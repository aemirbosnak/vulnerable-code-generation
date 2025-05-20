//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 32

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(FILE* fp, struct WordFrequency* words, int* num_words) {
    char line[1024];
    char* word_start = NULL;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* word_end = line + strlen(line) - 1;
        while (word_end >= line && isspace(*word_end)) {
            *word_end-- = '\0';
        }
        while (isspace(*word_start)) {
            word_start++;
        }
        if (word_start!= NULL && word_start < word_end) {
            strncpy(words[*num_words].word, word_start, MAX_WORD_LENGTH - 1);
            words[*num_words].word[MAX_WORD_LENGTH - 1] = '\0';
            words[*num_words].frequency++;
            (*num_words)++;
        }
        word_start = NULL;
    }
}

void write_file(FILE* fp, struct WordFrequency* words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s %d\n", words[i].word, words[i].frequency);
    }
}

int compare_words(const void* a, const void* b) {
    const struct WordFrequency* word_a = (const struct WordFrequency*)a;
    const struct WordFrequency* word_b = (const struct WordFrequency*)b;
    return strcmp(word_a->word, word_b->word);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    struct WordFrequency words[MAX_WORDS];
    int num_words = 0;

    read_file(input_file, words, &num_words);

    qsort(words, num_words, sizeof(struct WordFrequency), compare_words);

    write_file(output_file, words, num_words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}