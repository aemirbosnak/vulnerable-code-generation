//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING_LENGTH 100

// Function to remove punctuation marks from a string
char* remove_punctuation(char *str) {
    int i, j;
    char *new_str = (char*) malloc(strlen(str) + 1);
    for(i = 0, j = 0; str[i]; i++) {
        if(!ispunct(str[i]) || str[i] == '\'') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to convert all characters in a string to lowercase
char* to_lower_case(char *str) {
    int i;
    char *new_str = (char*) malloc(strlen(str) + 1);
    for(i = 0; str[i]; i++) {
        new_str[i] = tolower(str[i]);
    }
    new_str[i] = '\0';
    return new_str;
}

// Function to calculate the sentiment score of a given word
int get_score(char *word) {
    int score = 0;
    if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
        score = 2;
    } else if(strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0) {
        score = -2;
    } else if(strcmp(word, "okay") == 0) {
        score = 0;
    } else {
        score = 1;
    }
    return score;
}

// Function to calculate the overall sentiment score of a given sentence
int get_sentiment_score(char *sentence) {
    int score = 0;
    char *token;
    char *delim = " ";
    char *new_sentence = remove_punctuation(sentence);
    char *lower_case_sentence = to_lower_case(new_sentence);
    token = strtok(lower_case_sentence, delim);
    while(token != NULL) {
        score += get_score(token);
        token = strtok(NULL, delim);
    }
    free(new_sentence);
    free(lower_case_sentence);
    return score;
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a sentence: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // Remove trailing newline character
    int sentiment_score = get_sentiment_score(input_string);
    printf("The sentiment score of the sentence is %d\n", sentiment_score);
    return 0;
}