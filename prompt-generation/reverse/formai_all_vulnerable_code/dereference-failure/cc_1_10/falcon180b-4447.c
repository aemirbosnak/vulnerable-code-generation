//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 10000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int numSentences;
} Text;

char* readLine(FILE* file) {
    char* line = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    fgets(line, MAX_SENTENCE_LENGTH, file);
    return line;
}

void addSentence(Text* text, char* sentence) {
    if (text->numSentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    int length = strlen(sentence);
    if (length < MIN_SENTENCE_LENGTH) {
        printf("Error: Sentence too short.\n");
        return;
    }

    strcpy(text->sentences[text->numSentences].text, sentence);
    text->sentences[text->numSentences].length = length;
    text->numSentences++;
}

void summarize(Text* text, int numSentences) {
    int totalLength = 0;
    int i;

    for (i = 0; i < numSentences; i++) {
        totalLength += text->sentences[i].length;
    }

    if (totalLength <= 0) {
        printf("Error: No sentences found.\n");
        return;
    }

    double avgSentenceLength = (double)totalLength / numSentences;
    int numLongSentences = 0;

    printf("Summary:\n");
    printf("Total sentences: %d\n", numSentences);
    printf("Average sentence length: %.2f words\n", avgSentenceLength);

    for (i = 0; i < numSentences; i++) {
        if (text->sentences[i].length > avgSentenceLength * 1.5) {
            printf("%s\n", text->sentences[i].text);
            numLongSentences++;
        }
    }

    if (numLongSentences == 0) {
        printf("No long sentences found.\n");
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Text text = {0};

    char* line;
    while ((line = readLine(file))!= NULL) {
        addSentence(&text, line);
    }

    summarize(&text, text.numSentences);

    fclose(file);
    return 0;
}