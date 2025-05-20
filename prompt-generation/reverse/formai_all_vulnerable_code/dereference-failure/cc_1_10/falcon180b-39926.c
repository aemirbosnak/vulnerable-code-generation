//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_WORDS 100

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
    int total_words;
} Document;

Document *create_document() {
    Document *doc = (Document *) malloc(sizeof(Document));
    doc->sentences = (Sentence *) malloc(MAX_SENTENCES * sizeof(Sentence));
    doc->num_sentences = 0;
    doc->total_words = 0;
    return doc;
}

void destroy_document(Document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        free(doc->sentences[i].text);
    }
    free(doc->sentences);
    free(doc);
}

void add_sentence(Document *doc, char *sentence) {
    if (doc->num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }
    doc->sentences[doc->num_sentences].text = strdup(sentence);
    doc->sentences[doc->num_sentences].length = strlen(sentence);
    doc->num_sentences++;
    doc->total_words += count_words(sentence);
}

int count_words(char *sentence) {
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        num_words++;
        token = strtok(NULL, " ");
    }
    return num_words;
}

void print_document(Document *doc) {
    printf("Total sentences: %d\n", doc->num_sentences);
    printf("Total words: %d\n", doc->total_words);
    for (int i = 0; i < doc->num_sentences; i++) {
        printf("Sentence %d: %s\n", i+1, doc->sentences[i].text);
    }
}

int main() {
    Document *doc = create_document();
    char sentence[MAX_SENTENCE_LENGTH];

    while (fgets(sentence, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(doc, sentence);
    }

    print_document(doc);
    destroy_document(doc);

    return 0;
}