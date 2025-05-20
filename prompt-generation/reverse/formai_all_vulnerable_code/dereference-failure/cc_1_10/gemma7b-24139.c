//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 2000

char** tokenize(char* sentence) {
    char** words = (char**)malloc(MAX_WORDS * sizeof(char*));
    int num_words = 0;
    sentence = sentence;
    char* word = NULL;
    word = strtok(sentence, " ");
    while (word) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }
    words[num_words] = NULL;
    return words;
}

int sentiment_analysis(char* sentence) {
    char** words = tokenize(sentence);
    int sentiment = 0;
    for (int i = 0; words[i] != NULL; i++) {
        if (strcmp(words[i], "good") == 0) {
            sentiment++;
        } else if (strcmp(words[i], "bad") == 0) {
            sentiment--;
        } else if (strcmp(words[i], "neutral") == 0) {
            sentiment = 0;
        }
    }
    free(words);
    return sentiment;
}

int main() {
    char sentence[] = "I am happy and excited about this program.";
    int sentiment = sentiment_analysis(sentence);
    if (sentiment > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (sentiment < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }
    return 0;
}