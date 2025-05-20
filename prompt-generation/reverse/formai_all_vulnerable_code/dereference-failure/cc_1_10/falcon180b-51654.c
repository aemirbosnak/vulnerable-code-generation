//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MAX_WORDS_IN_SENTENCE 50

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int numSentences;
} Document;

void initializeDocument(Document *doc) {
    doc->sentences = (Sentence *)malloc(MAX_SENTENCES * sizeof(Sentence));
    doc->numSentences = 0;
}

void addSentence(Document *doc, char *sentence) {
    if (doc->numSentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }
    Sentence *newSentence = (Sentence *)malloc(sizeof(Sentence));
    newSentence->text = (char *)malloc((strlen(sentence) + 1) * sizeof(char));
    strcpy(newSentence->text, sentence);
    newSentence->length = strlen(sentence);
    doc->sentences[doc->numSentences++] = *newSentence;
    free(newSentence->text);
    free(newSentence);
}

void freeDocument(Document *doc) {
    for (int i = 0; i < doc->numSentences; i++) {
        free(doc->sentences[i].text);
    }
    free(doc->sentences);
}

void printDocument(Document *doc) {
    for (int i = 0; i < doc->numSentences; i++) {
        printf("%s\n", doc->sentences[i].text);
    }
}

int countWords(char *sentence) {
    int count = 0;
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int main() {
    Document doc;
    initializeDocument(&doc);
    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        addSentence(&doc, input);
    }
    int totalWords = 0;
    for (int i = 0; i < doc.numSentences; i++) {
        totalWords += countWords(doc.sentences[i].text);
    }
    printf("Total number of words: %d\n", totalWords);
    printDocument(&doc);
    freeDocument(&doc);
    return 0;
}