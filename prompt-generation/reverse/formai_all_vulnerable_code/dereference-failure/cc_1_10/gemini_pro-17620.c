//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARAGRAPHS 10
#define MAX_SENTENCES 100
#define MAX_WORDS 1000

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Paragraph;

typedef struct {
    Paragraph *paragraphs;
    int num_paragraphs;
} Document;

Document *create_document() {
    Document *document = malloc(sizeof(Document));
    document->paragraphs = malloc(sizeof(Paragraph) * MAX_PARAGRAPHS);
    document->num_paragraphs = 0;
    return document;
}

void free_document(Document *document) {
    for (int i = 0; i < document->num_paragraphs; i++) {
        for (int j = 0; j < document->paragraphs[i].num_sentences; j++) {
            free(document->paragraphs[i].sentences[j].text);
        }
        free(document->paragraphs[i].sentences);
    }
    free(document->paragraphs);
    free(document);
}

Paragraph *create_paragraph() {
    Paragraph *paragraph = malloc(sizeof(Paragraph));
    paragraph->sentences = malloc(sizeof(Sentence) * MAX_SENTENCES);
    paragraph->num_sentences = 0;
    return paragraph;
}

void free_paragraph(Paragraph *paragraph) {
    for (int i = 0; i < paragraph->num_sentences; i++) {
        free(paragraph->sentences[i].text);
    }
    free(paragraph->sentences);
    free(paragraph);
}

Sentence *create_sentence(char *text, int length) {
    Sentence *sentence = malloc(sizeof(Sentence));
    sentence->text = malloc(length + 1);
    memcpy(sentence->text, text, length);
    sentence->text[length] = '\0';
    sentence->length = length;
    return sentence;
}

void free_sentence(Sentence *sentence) {
    free(sentence->text);
    free(sentence);
}

void add_paragraph(Document *document, Paragraph *paragraph) {
    document->paragraphs[document->num_paragraphs++] = *paragraph;
}

void add_sentence(Paragraph *paragraph, Sentence *sentence) {
    paragraph->sentences[paragraph->num_sentences++] = *sentence;
}

void print_document(Document *document) {
    for (int i = 0; i < document->num_paragraphs; i++) {
        for (int j = 0; j < document->paragraphs[i].num_sentences; j++) {
            printf("%s ", document->paragraphs[i].sentences[j].text);
        }
        printf("\n");
    }
}

int main() {
    Document *document = create_document();

    // Add some paragraphs to the document
    for (int i = 0; i < 3; i++) {
        Paragraph *paragraph = create_paragraph();
        for (int j = 0; j < 3; j++) {
            char *text = malloc(100);
            sprintf(text, "This is sentence %d of paragraph %d.", j + 1, i + 1);
            Sentence *sentence = create_sentence(text, strlen(text));
            add_sentence(paragraph, sentence);
            free(text);
        }
        add_paragraph(document, paragraph);
    }

    // Print the document
    print_document(document);

    // Free the document
    free_document(document);

    return 0;
}