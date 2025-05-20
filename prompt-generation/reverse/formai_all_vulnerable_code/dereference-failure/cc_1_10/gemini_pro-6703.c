//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int text_len;
    int sentence_count;
    int *sentence_lens;
} Text;

Text *create_text(char *text) {
    Text *t = malloc(sizeof(Text));
    t->text = strdup(text);
    t->text_len = strlen(text);
    t->sentence_count = 0;
    t->sentence_lens = NULL;
    return t;
}

void free_text(Text *t) {
    free(t->text);
    free(t->sentence_lens);
    free(t);
}

void print_text(Text *t) {
    printf("%s\n", t->text);
}

void summarize_text(Text *t) {
    int i, j, k;
    char *sentence_start;
    char *sentence_end;
    int sentence_len;

    for (i = 0; i < t->text_len; i++) {
        if (t->text[i] == '.' || t->text[i] == '!' || t->text[i] == '?') {
            sentence_end = &t->text[i];
            sentence_len = sentence_end - sentence_start;
            t->sentence_lens[t->sentence_count] = sentence_len;
            t->sentence_count++;
        }
    }
}

int main() {
    char *text = "This is a sample text. It has multiple sentences. Each sentence is separated by a period, exclamation mark, or question mark. The text can be summarized by extracting the first sentence of each paragraph.";
    Text *t = create_text(text);
    summarize_text(t);
    print_text(t);
    free_text(t);
    return 0;
}