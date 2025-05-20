//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_t {
    char *word;
    int count;
};

struct word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: too many words\n");
        exit(1);
    }
    words[num_words].word = strdup(word);
    words[num_words].count = 1;
    num_words++;
}

void print_words(void) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    char *text = NULL;
    size_t text_size = 0;
    char buffer[MAX_WORD_LENGTH];
    int in_word = 0;
    int word_length = 0;
    int word_start = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    while ((i = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        text_size += i;
        text = realloc(text, text_size + 1);
        strncat(text, buffer, i);
    }
    fclose(file);

    for (i = 0; i < text_size; i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            in_word = 1;
            word_length = 0;
            word_start = i;
        } else if (in_word) {
            in_word = 0;
            add_word(text + word_start);
        }
    }

    if (in_word) {
        add_word(text + word_start);
    }

    print_words();

    free(text);
    return 0;
}