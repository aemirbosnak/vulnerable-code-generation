//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

struct word {
    char *word;
    int count;
};

struct sentence {
    char *sentence;
    int sentiment;
};

struct word_list {
    struct word words[MAX_WORDS];
    int count;
};

struct sentence_list {
    struct sentence sentences[MAX_SENTENCES];
    int count;
};

struct word_list *create_word_list() {
    struct word_list *wl = malloc(sizeof(struct word_list));
    wl->count = 0;
    return wl;
}

void add_word(struct word_list *wl, char *word) {
    int i;
    for (i = 0; i < wl->count; i++) {
        if (strcmp(wl->words[i].word, word) == 0) {
            wl->words[i].count++;
            return;
        }
    }
    wl->words[wl->count].word = strdup(word);
    wl->words[wl->count].count = 1;
    wl->count++;
}

struct sentence_list *create_sentence_list() {
    struct sentence_list *sl = malloc(sizeof(struct sentence_list));
    sl->count = 0;
    return sl;
}

void add_sentence(struct sentence_list *sl, char *sentence, int sentiment) {
    sl->sentences[sl->count].sentence = strdup(sentence);
    sl->sentences[sl->count].sentiment = sentiment;
    sl->count++;
}

int main() {
    struct word_list *wl = create_word_list();
    struct sentence_list *sl = create_sentence_list();

    char *text = "This is a sample text for sentiment analysis.";

    char *words = strtok(text, " ");
    while (words != NULL) {
        add_word(wl, words);
        words = strtok(NULL, " ");
    }

    char *sentences = strtok(text, ".");
    while (sentences != NULL) {
        int sentiment = 0;
        char *words = strtok(sentences, " ");
        while (words != NULL) {
            for (int i = 0; i < wl->count; i++) {
                if (strcmp(wl->words[i].word, words) == 0) {
                    sentiment += wl->words[i].count;
                }
            }
            words = strtok(NULL, " ");
        }
        add_sentence(sl, sentences, sentiment);
        sentences = strtok(NULL, ".");
    }

    for (int i = 0; i < sl->count; i++) {
        printf("%s: %d\n", sl->sentences[i].sentence, sl->sentences[i].sentiment);
    }

    return 0;
}