//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define SENTENCE_TERMINATORS ".?! "

typedef struct {
    char *text;
    int length;
    int position;
} Sentence;

typedef struct {
    Sentence *sentences;
    int count;
    int position;
} Paragraph;

void initializeParagraph(Paragraph *paragraph) {
    paragraph->sentences = (Sentence *)malloc(MAX_SENTENCES * sizeof(Sentence));
    paragraph->count = 0;
    paragraph->position = 0;
}

void addSentence(Paragraph *paragraph, char *sentence) {
    if (paragraph->count >= MAX_SENTENCES) {
        printf("Error: exceeded maximum number of sentences.\n");
        return;
    }

    int length = strlen(sentence);
    if (length >= MAX_SENTENCE_LENGTH) {
        printf("Error: sentence too long.\n");
        return;
    }

    Sentence *newSentence = (Sentence *)malloc(sizeof(Sentence));
    newSentence->text = (char *)malloc(length + 1);
    strcpy(newSentence->text, sentence);
    newSentence->length = length;
    newSentence->position = paragraph->position;

    paragraph->sentences[paragraph->count] = *newSentence;
    paragraph->count++;
}

void printParagraph(Paragraph *paragraph) {
    for (int i = 0; i < paragraph->count; i++) {
        printf("%s", paragraph->sentences[i].text);
    }
}

void freeParagraph(Paragraph *paragraph) {
    for (int i = 0; i < paragraph->count; i++) {
        free(paragraph->sentences[i].text);
    }
    free(paragraph->sentences);
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    Paragraph paragraph;

    initializeParagraph(&paragraph);

    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        input[strcspn(input, SENTENCE_TERMINATORS)] = '\0';
        addSentence(&paragraph, input);
    }

    printParagraph(&paragraph);

    freeParagraph(&paragraph);

    return 0;
}