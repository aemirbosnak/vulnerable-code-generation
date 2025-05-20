//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MAX_WORDS 1000

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Document;

Document *create_document() {
    Document *doc = malloc(sizeof(Document));
    doc->sentences = NULL;
    doc->num_sentences = 0;
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
    Sentence *new_sentence = malloc(sizeof(Sentence));
    new_sentence->text = strdup(sentence);
    new_sentence->length = strlen(sentence);
    doc->sentences = realloc(doc->sentences, sizeof(Sentence) * (doc->num_sentences + 1));
    doc->sentences[doc->num_sentences] = *new_sentence;
    doc->num_sentences++;
}

char *get_sentence(Document *doc, int index) {
    return doc->sentences[index].text;
}

int get_sentence_length(Document *doc, int index) {
    return doc->sentences[index].length;
}

int get_num_sentences(Document *doc) {
    return doc->num_sentences;
}

void print_document(Document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        printf("%s\n", doc->sentences[i].text);
    }
}

int main() {
    Document *doc = create_document();
    char input[MAX_SENTENCE_LENGTH];

    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(doc, input);
    }

    print_document(doc);

    destroy_document(doc);

    return 0;
}