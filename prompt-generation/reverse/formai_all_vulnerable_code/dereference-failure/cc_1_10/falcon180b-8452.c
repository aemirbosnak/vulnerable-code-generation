//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int len;
    time_t timestamp;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void add_word(char *word, int len) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        return;
    }
    Word *w = &words[num_words++];
    w->word = malloc(len + 1);
    strncpy(w->word, word, len);
    w->word[len] = '\0';
    w->len = len;
    w->timestamp = time(NULL);
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s (%ld)\n", words[i].word, words[i].timestamp);
    }
}

void cleanup() {
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
}

int main() {
    char input[MAX_WORD_LEN];
    while (fgets(input, MAX_WORD_LEN, stdin)) {
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[--len] = '\0';
        }
        add_word(input, len);
    }
    print_words();
    cleanup();
    return 0;
}