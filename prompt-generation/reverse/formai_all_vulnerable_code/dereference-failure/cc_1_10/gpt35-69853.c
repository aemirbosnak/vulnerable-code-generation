//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000 // maximum size of the text string
#define SPAM_THRESHOLD 0.8 // spam threshold value

// function to calculate the frequency of each word in a given string
void calculate_word_frequency(char *text, int *frequency, int *num_words) {
    char *token;
    token = strtok(text, " "); // tokenize the string using space as delimiter

    while(token != NULL) {
        // increment frequency counter for the current word
        int index = atoi(token) - 1;
        frequency[index]++;

        // move to next word token
        token = strtok(NULL, " ");
    }

    // calculate total number of words in the string
    int total_words = 0;
    for(int i = 0; i < MAX_TEXT_LENGTH; i++) {
        total_words += frequency[i];
    }
    *num_words = total_words;
}

// function to calculate the spam score of a given string
float calculate_spam_score(char *text, int *spam_word_frequency) {
    int frequency[MAX_TEXT_LENGTH] = {0};
    int num_words = 0;

    // calculate frequency of each word in the text string
    calculate_word_frequency(text, frequency, &num_words);

    float spam_score = 0.0;

    // calculate spam score using the frequency of spam words in the text
    for(int i = 0; i < MAX_TEXT_LENGTH; i++) {
        // calculate the percentage of spam word occurrence in the text
        float spam_word_percent = ((float)spam_word_frequency[i]/(float)num_words);
        // calculate the percentage of word occurrence in the text
        float word_percent = ((float)frequency[i]/(float)num_words);

        // add to spam score if the spam word occurs more frequently than the non-spam word
        if(spam_word_percent > word_percent)
            spam_score += spam_word_percent - word_percent;
    }

    return spam_score;
}

// main function to test the spam detection system
int main() {
    // sample spam words
    char *spam_words[MAX_TEXT_LENGTH] = {
        "make", "money", "online", "free", "cash", "guarantee", "limited", "time", "offer", "credit", "card"
    };

    // sample input text
    char *text = "Get free money online in limited time. Make cash five times faster with our guarantee offer using your credit card now!";

    int spam_word_frequency[MAX_TEXT_LENGTH] = {0};

    // calculate frequency of spam words
    for(int i = 0; i < MAX_TEXT_LENGTH; i++) {
        for(int j = 0; j < strlen(spam_words[i]); j++) {
            spam_word_frequency[i] += (int)spam_words[i][j];
        }
    }

    // calculate spam score of the input text
    float spam_score = calculate_spam_score(text, spam_word_frequency);

    // determine whether the input text is spam or not
    if(spam_score > SPAM_THRESHOLD) {
        printf("The input text is SPAM!\n");
    } else {
        printf("The input text is NOT spam.\n");
    }

    return 0;
}