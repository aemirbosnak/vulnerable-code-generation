//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1024

typedef struct Word {
    char* word;
    int frequency;
    struct Word* next;
} Word;

Word* createWord(char* word, int frequency) {
    Word* newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = frequency;
    newWord->next = NULL;
    return newWord;
}

void addWord(Word* head, char* word, int frequency) {
    Word* newWord = createWord(word, frequency);
    if (head == NULL) {
        head = newWord;
    } else {
        Word* currentWord = head;
        while (currentWord->next) {
            currentWord = currentWord->next;
        }
        currentWord->next = newWord;
    }
}

int main() {
    char* text = "This is a sample text for sentiment analysis. It is a very long text, but I will keep it short for this example.";
    Word* head = NULL;
    addWord(head, "sample", 2);
    addWord(head, "long", 2);
    addWord(head, "short", 2);
    addWord(head, "text", 3);
    addWord(head, "This", 1);
    addWord(head, "is", 2);
    addWord(head, "a", 2);
    addWord(head, "very", 2);
    addWord(head, "much", 1);

    int sentiment = analyzeSentiment(head);
    if (sentiment > 0) {
        printf("The text has a positive sentiment.\n");
    } else if (sentiment < 0) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }

    return 0;
}

int analyzeSentiment(Word* head) {
    int positiveWords = 0;
    int negativeWords = 0;
    for (Word* currentWord = head; currentWord; currentWord = currentWord->next) {
        if (strcmp(currentWord->word, "positive") == 0) {
            positiveWords++;
        } else if (strcmp(currentWord->word, "negative") == 0) {
            negativeWords++;
        }
    }

    return positiveWords - negativeWords;
}