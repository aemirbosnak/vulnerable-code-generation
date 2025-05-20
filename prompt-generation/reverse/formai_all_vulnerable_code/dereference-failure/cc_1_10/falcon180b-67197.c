//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count_t {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(const char* filename, struct word_count_t* word_counts) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char ch;
    int in_word = 0;
    int word_length = 0;
    char* word_buffer = (char*) malloc(MAX_WORD_LENGTH);
    if (word_buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
        } else if (in_word) {
            in_word = 0;
            word_buffer[word_length] = '\0';
            strcpy(word_counts->word, word_buffer);
            word_counts->count++;
            word_length = 0;
        }

        if (in_word && word_length < MAX_WORD_LENGTH - 1) {
            word_buffer[word_length++] = tolower(ch);
        }
    }

    if (in_word) {
        word_buffer[word_length] = '\0';
        strcpy(word_counts->word, word_buffer);
        word_counts->count++;
    }

    fclose(file);
    free(word_buffer);
}

void print_word_counts(struct word_count_t* word_counts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct word_count_t word_counts[MAX_WORDS];
    read_file(argv[1], word_counts);
    print_word_counts(word_counts);

    return 0;
}