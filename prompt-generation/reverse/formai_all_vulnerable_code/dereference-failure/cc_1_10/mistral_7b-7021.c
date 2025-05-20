//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LENGTH 20

// Sentiment scores for positive and negative words
int sentiment[MAX_WORDS][WORD_LENGTH];

void load_sentiment() {
    // Load sentiment scores for positive and negative words from a file
    FILE *fp;
    char filename[50] = "sentiment.txt";
    char line[100];
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open sentiment file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        char word[WORD_LENGTH];
        sscanf(line, "%s", word);
        int len = strlen(word);
        for (i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }
        int score = atoi(strtok(NULL, " "));
        for (i = 0; i < len; i++) {
            for (j = 0; j < MAX_WORDS - len; j++) {
                if (strcmp(sentiment[j], word) == 0) {
                    sentiment[j][strlen(word)] = score;
                    break;
                }
            }
            if (j >= MAX_WORDS - len) {
                for (int k = 0; k < MAX_WORDS; k++) {
                    if (sentiment[k][0] == '\0') {
                        strcpy(sentiment[k], word);
                        sentiment[k][strlen(word)] = score;
                        break;
                    }
                }
            }
        }
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    int total_score = 0;
    int num_words = 0;
    char words[MAX_WORDS][WORD_LENGTH];

    char *token = strtok(text, " .,\n");
    while (token != NULL) {
        strcpy(words[num_words], token);
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in input text.\n");
            exit(1);
        }

        token = strtok(NULL, " .,\n");
    }

    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(sentiment[j], words[i]) == 0) {
                total_score += sentiment[j][strlen(words[i])];
                break;
            }
        }
    }

    return total_score;
}

int main() {
    load_sentiment();

    char text[100] = "I love this program! It's awesome.";
    int sentiment_score = analyze_sentiment(text);
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}