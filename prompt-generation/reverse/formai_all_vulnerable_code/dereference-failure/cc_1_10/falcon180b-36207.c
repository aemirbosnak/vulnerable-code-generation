//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Document;

void init_sentence(Sentence *sentence) {
    sentence->text = NULL;
    sentence->length = 0;
}

void init_document(Document *document) {
    document->sentences = NULL;
    document->num_sentences = 0;
}

void add_sentence(Document *document, char *text) {
    if (document->num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    Sentence *new_sentence = (Sentence *) malloc(sizeof(Sentence));
    init_sentence(new_sentence);

    new_sentence->text = strdup(text);
    new_sentence->length = strlen(text);

    document->sentences = (Sentence *) realloc(document->sentences, sizeof(Sentence) * (document->num_sentences + 1));
    document->sentences[document->num_sentences] = *new_sentence;
    document->num_sentences++;
}

void free_document(Document *document) {
    for (int i = 0; i < document->num_sentences; i++) {
        free(document->sentences[i].text);
    }
    free(document->sentences);
}

int count_words(char *text) {
    int num_words = 0;
    char *word = strtok(text, " ");

    while (word!= NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }

    return num_words;
}

int main() {
    Document document;
    init_document(&document);

    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(&document, input);
    }

    int total_words = 0;
    for (int i = 0; i < document.num_sentences; i++) {
        total_words += count_words(document.sentences[i].text);
    }

    printf("Total words: %d\n", total_words);

    free_document(&document);

    return 0;
}