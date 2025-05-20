//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH];
    int emotion;
} Word;

Word emotion_words[MAX_WORDS];
int num_words = 0;

void load_emotion_words() {
    FILE *file = fopen("emotion_words.txt", "r");
    char line[100];
    char *token;
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",\n");
        strcpy(emotion_words[i].word, token);
        emotion_words[i].emotion = 1; // Positive emotion by default

        token = strtok(NULL, ",\n");
        if (token != NULL) {
            emotion_words[i].emotion *= atoi(token); // Multiply by emotion factor if provided
        }

        i++;
        if (i == MAX_WORDS) {
            break;
        }
    }

    fclose(file);
}

void analyze_sentiment(char *text) {
    int sentiment = 0;
    char word[MAX_LENGTH];
    int i;

    char *token = strtok(text, " .,?!");
    while (token != NULL) {
        for (i = 0; i < num_words; i++) {
            if (strcasecmp(token, emotion_words[i].word) == 0) {
                sentiment += emotion_words[i].emotion;
                break;
            }
        }
        token = strtok(NULL, " .,?!");
    }

    printf("Sentiment score: %d\n", sentiment);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    load_emotion_words();

    FILE *file = fopen(argv[1], "r");
    char text[1024];
    fgets(text, sizeof(text), file); // Read the first line as text
    fclose(file);

    analyze_sentiment(text);

    return 0;
}