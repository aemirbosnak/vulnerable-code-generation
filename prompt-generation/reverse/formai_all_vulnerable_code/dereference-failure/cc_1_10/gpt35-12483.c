//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform sentiment analysis
void sentiment_analysis(char *text) {
    
    // Initializing the pointers to represent the sentiment values
    int *positive = (int*)malloc(sizeof(int));
    int *negative = (int*)malloc(sizeof(int));
    int *neutral = (int*)malloc(sizeof(int));
    
    // Initializing the counts to zero
    *positive = 0;
    *negative = 0;
    *neutral = 0;
    
    // Splitting the text into words
    char *word = strtok(text, " ");
    
    // Processing each word for sentiment
    while(word != NULL) {
        
        // Converting the word to lower case
        char *lower_word = (char*)malloc(sizeof(char) * strlen(word));
        for(int i=0; i<strlen(word); i++) {
            lower_word[i] = tolower(word[i]);
        }
        
        // Checking if the word is positive or negative
        if(strcmp(lower_word, "good") == 0 || strcmp(lower_word, "great") == 0 || strcmp(lower_word, "excellent") == 0) {
            (*positive)++;
        }
        else if(strcmp(lower_word, "bad") == 0 || strcmp(lower_word, "terrible") == 0 || strcmp(lower_word, "horrible") == 0) {
            (*negative)++;
        }
        else {
            (*neutral)++;
        }
        
        // Updating the pointer to represent the next word
        word = strtok(NULL, " ");
    }
    
    // Printing the sentiment values
    printf("Sentiment Analysis Result\n");
    printf("Positive Words: %d\n", *positive);
    printf("Negative Words: %d\n", *negative);
    printf("Neutral Words: %d\n", *neutral);
    
    // Freeing the memory
    free(positive);
    free(negative);
    free(neutral);
}

int main() {
    char text[1000];
    printf("Enter some text for sentiment analysis: ");
    fgets(text, 1000, stdin);
    
    // Calling the sentiment analysis function
    sentiment_analysis(text);
    
    return 0;
}