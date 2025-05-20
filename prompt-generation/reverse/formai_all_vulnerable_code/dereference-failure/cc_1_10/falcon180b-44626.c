//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    int num_words = 0;
    struct word_count *words = (struct word_count *)malloc(MAX_NUM_WORDS * sizeof(struct word_count));

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *token = strtok(line, ",.?!;");
        while (token!= NULL) {
            if (num_words >= MAX_NUM_WORDS) {
                printf("Error: maximum number of words reached.\n");
                return 1;
            }
            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;
            token = strtok(NULL, ",.?!;");
        }
    }

    qsort(words, num_words, sizeof(struct word_count), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);
    fclose(input_file);

    return 0;
}