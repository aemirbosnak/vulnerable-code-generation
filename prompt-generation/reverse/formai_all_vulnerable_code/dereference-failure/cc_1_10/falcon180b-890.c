//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 100
#define MAX_WORDS 1000

typedef struct {
    int length;
    char *text;
} Sentence;

typedef struct {
    int count;
    Sentence *sentences;
} Document;

void read_sentences(FILE *file, Sentence *sentences, int *count) {
    char ch;
    int length = 0;
    Sentence *current_sentence = sentences;

    while ((ch = fgetc(file))!= EOF) {
        if (ch == '.' || ch == '!' || ch == '?') {
            if (length > 0) {
                current_sentence->text[length] = '\0';
                current_sentence->length = length;
                current_sentence++;
                length = 0;
            }
        } else if (length < MAX_SENTENCE_LENGTH - 1) {
            current_sentence->text[length++] = ch;
        }
    }

    if (length > 0) {
        current_sentence->text[length] = '\0';
        current_sentence->length = length;
        current_sentence++;
    }

    *count = current_sentence - sentences;
}

void read_document(FILE *file, Document *document) {
    Sentence sentences[MAX_SENTENCES];
    int count;

    read_sentences(file, sentences, &count);
    document->count = count;
    document->sentences = malloc(count * sizeof(Sentence));
    memcpy(document->sentences, sentences, count * sizeof(Sentence));
}

void free_document(Document *document) {
    free(document->sentences);
}

void print_sentence(Sentence *sentence) {
    printf("%s\n", sentence->text);
}

void print_document(Document *document) {
    int i;

    for (i = 0; i < document->count; i++) {
        print_sentence(&document->sentences[i]);
    }
}

int main() {
    FILE *file;
    Document document;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_document(file, &document);
    fclose(file);

    print_document(&document);

    free_document(&document);

    return 0;
}