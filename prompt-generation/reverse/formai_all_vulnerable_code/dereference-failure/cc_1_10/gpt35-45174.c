//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000

int positive_words_count(char* text, char** pos_words, int pos_words_count);
int negative_words_count(char* text, char** neg_words, int neg_words_count);

int main() {
    char* text = (char*)malloc(MAX_LEN * sizeof(char));
    printf("Enter your text (max 1000 characters):\n");
    fgets(text, MAX_LEN, stdin);

    // Positive words
    char* pos_words[5] = {"good", "great", "excellent", "happy", "love"};
    int pos_words_count = 5;

    // Negative words
    char* neg_words[5] = {"bad", "poor", "terrible", "sad", "hate"};
    int neg_words_count = 5;

    int pos_count = positive_words_count(text, pos_words, pos_words_count);
    int neg_count = negative_words_count(text, neg_words, neg_words_count);

    free(text);

    if(pos_count > neg_count) {
        printf("Overall sentiment: Positive\n");
    } else if(neg_count > pos_count) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }

    return 0;
}

int positive_words_count(char* text, char** pos_words, int pos_words_count) {
    int count = 0;
    char* word = strtok(text, " ");
    while(word != NULL) {
        for(int i = 0; i < pos_words_count; i++) {
            if(strcmp(word, pos_words[i]) == 0) {
                count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return count;
}

int negative_words_count(char* text, char** neg_words, int neg_words_count) {
    int count = 0;
    char* word = strtok(text, " ");
    while(word != NULL) {
        for(int i = 0; i < neg_words_count; i++) {
            if(strcmp(word, neg_words[i]) == 0) {
                count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return count;
}