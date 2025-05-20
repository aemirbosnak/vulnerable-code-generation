//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 10

typedef struct {
    char *word;
    int count;
} word_count;

typedef struct {
    word_count words[MAX_WORDS];
    int num_words;
} sentence;

typedef struct {
    sentence sentences[MAX_SENTENCES];
    int num_sentences;
} document;

document *new_document() {
    document *doc = malloc(sizeof(document));
    doc->num_sentences = 0;
    return doc;
}

void free_document(document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        for (int j = 0; j < doc->sentences[i].num_words; j++) {
            free(doc->sentences[i].words[j].word);
        }
    }
    free(doc);
}

sentence *new_sentence() {
    sentence *sent = malloc(sizeof(sentence));
    sent->num_words = 0;
    return sent;
}

void free_sentence(sentence *sent) {
    for (int i = 0; i < sent->num_words; i++) {
        free(sent->words[i].word);
    }
    free(sent);
}

void add_word_to_sentence(sentence *sent, char *word) {
    if (sent->num_words == MAX_WORDS) {
        return;
    }

    sent->words[sent->num_words].word = strdup(word);
    sent->words[sent->num_words].count = 1;
    sent->num_words++;
}

void add_sentence_to_document(document *doc, sentence *sent) {
    if (doc->num_sentences == MAX_SENTENCES) {
        return;
    }

    doc->sentences[doc->num_sentences] = *sent;
    doc->num_sentences++;
}

void print_document(document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        for (int j = 0; j < doc->sentences[i].num_words; j++) {
            printf("%s ", doc->sentences[i].words[j].word);
        }
        printf("\n");
    }
}

int main() {
    document *doc = new_document();

    char *text = "This is a sample text. This is a sample text. This is a sample text.";

    char *token = strtok(text, " ");
    while (token != NULL) {
        sentence *sent = new_sentence();
        add_word_to_sentence(sent, token);

        while ((token = strtok(NULL, " ")) != NULL) {
            add_word_to_sentence(sent, token);
        }

        add_sentence_to_document(doc, sent);
        free_sentence(sent);
    }

    print_document(doc);
    free_document(doc);

    return 0;
}