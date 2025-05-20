//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

typedef struct {
    char *word;
    int sentiment;
} Word;

typedef struct {
    Word *words[MAX_WORDS];
    int num_words;
} Dictionary;

typedef struct {
    char *sentence;
    int sentiment;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences;

Dictionary dictionary;

void init_dictionary() {
    FILE *fp = fopen("sentiment-words.txt", "r");
    if (fp == NULL) {
        perror("Could not open sentiment-words.txt");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *word = strtok(line, "\t");
        int sentiment = atoi(strtok(NULL, "\t"));

        Word *w = malloc(sizeof(Word));
        w->word = strdup(word);
        w->sentiment = sentiment;

        dictionary.words[dictionary.num_words++] = w;
    }

    fclose(fp);
}

void free_dictionary() {
    for (int i = 0; i < dictionary.num_words; i++) {
        free(dictionary.words[i]->word);
        free(dictionary.words[i]);
    }
}

void init_sentences() {
    FILE *fp = fopen("sentences.txt", "r");
    if (fp == NULL) {
        perror("Could not open sentences.txt");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *sentence = strdup(line);
        int sentiment = 0;

        char *word = strtok(line, " ");
        while (word != NULL) {
            for (int i = 0; i < dictionary.num_words; i++) {
                if (strcmp(word, dictionary.words[i]->word) == 0) {
                    sentiment += dictionary.words[i]->sentiment;
                }
            }

            word = strtok(NULL, " ");
        }

        Sentence s = {sentence, sentiment};
        sentences[num_sentences++] = s;
    }

    fclose(fp);
}

void free_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i].sentence);
    }
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s: %d\n", sentences[i].sentence, sentences[i].sentiment);
    }
}

int main() {
    init_dictionary();
    init_sentences();

    print_sentences();

    free_sentences();
    free_dictionary();

    return 0;
}