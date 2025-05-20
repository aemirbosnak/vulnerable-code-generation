//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: genius
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct SpamData {
    char** words;
    char** sentences;
    int wordCount;
    int sentenceCount;
} SpamData;

SpamData* createSpamData() {
    SpamData* data = malloc(sizeof(SpamData));
    data->words = malloc(MAX_WORDS * sizeof(char*));
    data->sentences = malloc(MAX_SENTENCE_LENGTH * sizeof(char*));
    data->wordCount = 0;
    data->sentenceCount = 0;
    return data;
}

void addWordToSpamData(SpamData* data, char* word) {
    data->words[data->wordCount++] = word;
}

void addSentenceToSpamData(SpamData* data, char* sentence) {
    data->sentences[data->sentenceCount++] = sentence;
}

int isSpam(SpamData* data) {
    int i, j, wordCount = data->wordCount, sentenceCount = data->sentenceCount;
    for (i = 0; i < wordCount; i++) {
        for (j = 0; j < sentenceCount; j++) {
            if (strstr(data->sentences[j], data->words[i]) != NULL) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    SpamData* data = createSpamData();
    addWordToSpamData(data, "Free");
    addWordToSpamData(data, "Offer");
    addSentenceToSpamData(data, "Get free offer now!");
    addSentenceToSpamData(data, "Buy now and get free gift!");

    if (isSpam(data)) {
        printf("The text is spam.\n");
    } else {
        printf("The text is not spam.\n");
    }

    return 0;
}