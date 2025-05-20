//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate sentiment score of a given sentence
int calcSentimentScore(char* sentence) {
    int score = 0;
    char* word;
    char* remainder = sentence;

    // define list of positive and negative words
    char* posWords[] = {"happy","amazing","great","love","awesome","fantastic","excellent","pleased","fun","enthusiastic","energetic","vibrant","fabulous","magnificent","delighted","satisfied","joyful","blissful","hopeful","confident"};
    char* negWords[] = {"sad","bad","terrible","hate","awful","disgusting","dreadful","miserable","unhappy","horrible","anguished","depressed","despondent","glum","gloomy","melancholy","sorrowful","unfortunate","woeful","devastated"};

    // loop through each word in the sentence
    while ((word = strtok_r(remainder, " ", &remainder))) {
        // check if word is in positive or negative list of words
        int isPos = 0;
        int isNeg = 0;
        for (int i = 0; i < 20; i++) {
            if (strcmp(word, posWords[i]) == 0) {
                isPos = 1;
                break;
            }
            if (strcmp(word, negWords[i]) == 0) {
                isNeg = 1;
                break;
            }
        }
        // increment or decrement score based on whether word is positive or negative
        if (isPos) {
            score++;
        }
        if (isNeg) {
            score--;
        }
    }
    return score;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to analyze sentiment: ");
    fgets(sentence, 1000, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // remove trailing newline character

    int score = calcSentimentScore(sentence);
    if (score > 0) {
        printf("This sentence has a positive sentiment score of %d!\n", score);
    }
    else if (score < 0) {
        printf("This sentence has a negative sentiment score of %d :(\n", score);
    }
    else {
        printf("This sentence has a neutral sentiment score of %d :|\n", score);
    }

    return 0;
}