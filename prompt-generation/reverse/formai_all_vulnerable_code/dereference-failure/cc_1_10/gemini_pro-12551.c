//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VOCABULARY_SIZE 1000

typedef struct {
    char *word;
    int sentiment;
} Word;

typedef struct {
    Word vocabulary[MAX_VOCABULARY_SIZE];
    int size;
} Vocabulary;

Vocabulary *create_vocabulary() {
    Vocabulary *vocabulary = malloc(sizeof(Vocabulary));
    vocabulary->size = 0;
    return vocabulary;
}

void add_word_to_vocabulary(Vocabulary *vocabulary, char *word, int sentiment) {
    if (vocabulary->size >= MAX_VOCABULARY_SIZE) {
        printf("Vocabulary is full. Cannot add new word.\n");
        return;
    }
    vocabulary->vocabulary[vocabulary->size].word = word;
    vocabulary->vocabulary[vocabulary->size].sentiment = sentiment;
    vocabulary->size++;
}

int find_word_in_vocabulary(Vocabulary *vocabulary, char *word) {
    for (int i = 0; i < vocabulary->size; i++) {
        if (strcmp(vocabulary->vocabulary[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentiment(Vocabulary *vocabulary, char *text) {
    char *words[100];
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }
    int sentiment = 0;
    for (int i = 0; i < num_words; i++) {
        int index = find_word_in_vocabulary(vocabulary, words[i]);
        if (index != -1) {
            sentiment += vocabulary->vocabulary[index].sentiment;
        }
    }
    return sentiment;
}

int main() {
    Vocabulary *vocabulary = create_vocabulary();
    add_word_to_vocabulary(vocabulary, "love", 1);
    add_word_to_vocabulary(vocabulary, "hate", -1);
    add_word_to_vocabulary(vocabulary, "happy", 1);
    add_word_to_vocabulary(vocabulary, "sad", -1);
    add_word_to_vocabulary(vocabulary, "good", 1);
    add_word_to_vocabulary(vocabulary, "bad", -1);
    char *text = "I love you.";
    int sentiment = analyze_sentiment(vocabulary, text);
    printf("The sentiment of the text is: %d\n", sentiment);
    return 0;
}