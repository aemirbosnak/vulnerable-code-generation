//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A sentiment dictionary with positive and negative words
typedef struct {
    char* word;
    int sentiment;
} SentimentDictionaryEntry;

// Initialize the sentiment dictionary
SentimentDictionaryEntry sentimentDictionary[] = {
    {"good", 1},
    {"bad", -1},
    {"excellent", 2},
    {"terrible", -2},
    {"amazing", 3},
    {"awful", -3},
    {"positive", 1},
    {"negative", -1},
    {"happy", 1},
    {"sad", -1},
    {"joyful", 2},
    {"depressed", -2},
    {"wonderful", 3},
    {"horrible", -3}
};

// Calculate the sentiment of a given text
int calculateSentiment(char* text) {
    int sentiment = 0;
    char* word = strtok(text, " ");
    while (word != NULL) {
        for (int i = 0; i < sizeof(sentimentDictionary) / sizeof(SentimentDictionaryEntry); i++) {
            if (strcmp(word, sentimentDictionary[i].word) == 0) {
                sentiment += sentimentDictionary[i].sentiment;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return sentiment;
}

// Print the sentiment of a given text
void printSentiment(char* text) {
    int sentiment = calculateSentiment(text);
    if (sentiment > 0) {
        printf("Yay! %s is a positive text!\n", text);
    } else if (sentiment < 0) {
        printf("Oh no! %s is a negative text!\n", text);
    } else {
        printf("Oops! %s is a neutral text!\n", text);
    }
}

// Get a text from the user
char* getText() {
    char* text = malloc(1024);
    printf("Enter a text to analyze: ");
    fgets(text, 1024, stdin);
    return text;
}

// Main function
int main() {
    char* text = getText();
    printSentiment(text);
    free(text);
    return 0;
}