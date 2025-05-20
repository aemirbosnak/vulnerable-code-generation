//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_CHARS_PER_WORD 50

typedef struct word {
    char *text;
    int count;
} Word;

void read_words(FILE *input_file, Word words[]) {
    char word_buffer[MAX_CHARS_PER_WORD];
    char *word_text = NULL;
    size_t word_length = 0;
    int word_count = 0;

    while (fscanf(input_file, "%s", word_buffer)!= EOF) {
        word_text = realloc(word_text, word_length + strlen(word_buffer) + 1);
        strcat(word_text, word_buffer);
        word_length += strlen(word_buffer);
        word_count++;
    }

    words[0].text = word_text;
    words[0].count = word_count;
}

void count_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].text, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    Word words[MAX_WORDS];
    read_words(input_file, words);

    count_words(words, 1);

    fclose(input_file);
    return 0;
}