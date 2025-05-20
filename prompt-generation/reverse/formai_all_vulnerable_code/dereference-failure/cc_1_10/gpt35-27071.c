//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

// function to determine sentiment from given input string
int determineSentiment(char inputString[]) {

    int posCount = 0;
    int negCount = 0;
    
    // opening the positive words file
    FILE* posFile = fopen("positiveWords.txt", "r");
    if (posFile == NULL) {
        printf("Error opening file positiveWords.txt!");
        exit(1);
    }

    // opening the negative words file
    FILE* negFile = fopen("negativeWords.txt", "r");
    if (negFile == NULL) {
        printf("Error opening file negativeWords.txt!");
        exit(1);
    }
    
    char word[MAX_INPUT_LENGTH];
    
    // iterating through input string word by word 
    char* token = strtok(inputString, " ");
    while (token != NULL) {
        
        // removing any punctuation from the current word
        int i;
        for (i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                memmove(&token[i], &token[i + 1], strlen(token) - i);
            }
        }
        
        // converting the word to lowercase for consistency
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        
        // checking if the current word appears in either the positive or negative words file
        while (fscanf(posFile, "%s", word) != EOF) {
            if (strcmp(token, word) == 0) {
                posCount++;
            }
        }
        
        while (fscanf(negFile, "%s", word) != EOF) {
            if (strcmp(token, word) == 0) {
                negCount++;
            }
        }
        
        // resetting the file pointer to the beginning of the words file for the next iteration
        fseek(posFile, 0, SEEK_SET);
        fseek(negFile, 0, SEEK_SET);
        
        // getting the next word in the input string
        token = strtok(NULL, " ");
    }
    
    // closing the files
    fclose(posFile);
    fclose(negFile);
    
    // returning the sentiment based on positive and negative word counts
    if (posCount > negCount) {
        return 1; // positive sentiment
    } else if (negCount > posCount) {
        return -1; // negative sentiment
    } else {
        return 0; // neutral sentiment
    }
}

int main() {
    
    char input[MAX_INPUT_LENGTH];
    
    // getting input from the user
    printf("Enter a statement or phrase: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // removing newline character from the input string
    input[strcspn(input, "\n")] = 0;
    
    int sentiment = determineSentiment(input);
    
    // outputting the sentiment
    if (sentiment == 1) {
        printf("Positive sentiment detected!\n");
    } else if (sentiment == -1) {
        printf("Negative sentiment detected!\n");
    } else {
        printf("Neutral sentiment detected!\n");
    }
    
    return 0;
}