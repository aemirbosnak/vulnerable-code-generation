//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 10000
#define NUM_SENTIMENTS 6

typedef struct {
    char* name;
    int count;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Happy", 0},
    {"Sad", 0},
    {"Angry", 0},
    {"Surprised", 0},
    {"Fearful", 0},
    {"Disgusted", 0}
};

void analyze_sentiment(char* text) {
    int i = 0;
    while (i < strlen(text)) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
        }
        i++;
    }

    int j = 0;
    while (j < NUM_SENTIMENTS) {
        int k = 0;
        while (k < strlen(sentiments[j].name)) {
            if (strncmp(&text[i], &sentiments[j].name[k], strlen(sentiments[j].name)) == 0) {
                sentiments[j].count++;
                i += strlen(sentiments[j].name);
                k = strlen(sentiments[j].name);
            } else {
                k++;
            }
        }
        j++;
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage:./sentiment_analysis <text>\n");
        return 1;
    }

    char* text = argv[1];
    analyze_sentiment(text);

    printf("Sentiment Analysis:\n");
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].name, sentiments[i].count);
    }

    return 0;
}