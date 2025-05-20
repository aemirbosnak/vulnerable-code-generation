//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <string.h>

typedef struct WordCount {
    char **words;
    int count;
} WordCount;

WordCount *wordCount(char *text) {
    WordCount *wc = malloc(sizeof(WordCount));
    wc->words = malloc(sizeof(char *) * 10);
    wc->count = 0;

    char *p = text;
    char **w = wc->words;

    while (p) {
        char *word = malloc(sizeof(char) * 20);
        *word = 0;

        while (*p && !isspace(*p) && *p) {
            *word = *p;
            p++;
            word++;
        }

        if (*word) {
            wc->words[wc->count++] = word;
        }
    }

    return wc;
}

int main() {
    char *text = "This is a sample text with many words. Some words are short, while others are long. The longest word in this text is definitely long enough to fill this entire line.";

    WordCount *wc = wordCount(text);

    printf("Number of words: %d\n", wc->count);

    for (int i = 0; i < wc->count; i++) {
        printf("Word %d: %s\n", i + 1, wc->words[i]);
    }

    free(wc->words);
    free(wc);

    return 0;
}