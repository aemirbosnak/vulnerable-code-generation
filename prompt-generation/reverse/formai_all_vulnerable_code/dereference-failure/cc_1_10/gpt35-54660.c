//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

void analyze_sentiment(char *str);
int get_sentiment_score(char *word);

int main() {
    char input_str[MAX_STRING_LENGTH];
    int i, j;

    printf("Enter a sentence: ");
    fgets(input_str, MAX_STRING_LENGTH, stdin);

    // Remove the newline character from input string
    for (i = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] == '\n') {
            input_str[i] = '\0';
            break;
        }
    }

    // Split input string into separate words and analysis sentiment
    char *words[MAX_STRING_LENGTH];
    char *delim = " ";
    char *ptr = strtok(input_str, delim);
    i = 0;
    while (ptr != NULL) {
        words[i] = ptr;
        ptr = strtok(NULL, delim);
        i++;
    }
    words[i] = NULL;

    for (j = 0; j < i; j++) {
        analyze_sentiment(words[j]);
    }

    return 0;
}

// Helper function to analyze the sentiment of a word
void analyze_sentiment(char *str) {
    char *p;
    int sentiment_score = 0;

    // Remove any trailing punctuation from the string
    for (p = str + strlen(str) - 1; ispunct(*p); p--) {
        *p = '\0';
    }

    sentiment_score = get_sentiment_score(str);

    printf("%s: ", str);
    if (sentiment_score > 0) {
        printf("Positive\n");
    } else if (sentiment_score < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }
}

// Helper function to calculate the sentiment score of a word
int get_sentiment_score(char *word) {
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
        return 1;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
        return -1;
    } else {
        return 0;
    }
}