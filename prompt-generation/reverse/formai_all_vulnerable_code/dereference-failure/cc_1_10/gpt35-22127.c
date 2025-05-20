//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>

// Function that takes a string of text as input and returns the summary as output
char* summarize(char* text) {
    // Initializing variables
    int i = 0, j = 0, word_count = 0, sentence_count = 0;
    char summary[100];
    char* word, *sentence;
    
    // Looping through each character in the text
    while (text[i] != '\0') {
        // Counting the number of words in the text
        if (text[i] == ' ') {
            word_count++;
        }
        // Counting the number of sentences in the text
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence_count++;
        }
        i++;
    }
    
    // Calculating the average length of a sentence
    double avg_length = (double) word_count / sentence_count;
    
    // Extracting the first sentence of the text
    sentence = strtok(text, ".");
    
    // Looping through each word in the first sentence
    while (word != NULL) {
        word = strtok(sentence, " ");
        // Checking if the word is longer than the average sentence length
        if (strlen(word) > avg_length) {
            // Adding the word to the summary
            strcat(summary, word);
            strcat(summary, " ");
        }
    }
    // Returning the summary
    return summary;
}

int main() {
    // Taking input from the user
    printf("Enter the text you want to summarize:\n");
    char text[1000];
    fgets(text, sizeof(text), stdin);
    
    // Generating the summary and displaying it
    char* summary = summarize(text);
    printf("Summary:\n%s", summary);
    return 0;
}