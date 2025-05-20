//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 10

typedef struct {
    char* words[MAX_WORDS];
    int num_words;
} sentence;

typedef struct {
    sentence sentences[MAX_SENTENCES];
    int num_sentences;
} text;

text* create_text() {
    text* t = malloc(sizeof(text));
    t->num_sentences = 0;
    return t;
}

void add_sentence(text* t, sentence s) {
    if (t->num_sentences == MAX_SENTENCES) {
        fprintf(stderr, "Error: too many sentences in text\n");
        return;
    }
    t->sentences[t->num_sentences++] = s;
}

void print_text(text* t) {
    for (int i = 0; i < t->num_sentences; i++) {
        sentence s = t->sentences[i];
        for (int j = 0; j < s.num_words; j++) {
            printf("%s ", s.words[j]);
        }
        printf("\n");
    }
}

void free_text(text* t) {
    for (int i = 0; i < t->num_sentences; i++) {
        sentence s = t->sentences[i];
        for (int j = 0; j < s.num_words; j++) {
            free(s.words[j]);
        }
    }
    free(t);
}

int main() {
    text* t = create_text();

    sentence s1;
    s1.num_words = 3;
    s1.words[0] = strdup("The");
    s1.words[1] = strdup("quick");
    s1.words[2] = strdup("brown");
    add_sentence(t, s1);

    sentence s2;
    s2.num_words = 3;
    s2.words[0] = strdup("fox");
    s2.words[1] = strdup("jumps");
    s2.words[2] = strdup("over");
    add_sentence(t, s2);

    sentence s3;
    s3.num_words = 2;
    s3.words[0] = strdup("the");
    s3.words[1] = strdup("lazy");
    add_sentence(t, s3);

    sentence s4;
    s4.num_words = 3;
    s4.words[0] = strdup("dog");
    s4.words[1] = strdup("quickly");
    s4.words[2] = strdup("ran");
    add_sentence(t, s4);

    print_text(t);

    free_text(t);

    return 0;
}