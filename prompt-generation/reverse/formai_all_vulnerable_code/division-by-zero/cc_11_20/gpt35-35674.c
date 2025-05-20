//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
/*
* Program: Text Summarizer
* Author: [Your name]
* Purpose: Summarize any given text by picking important sentences and reducing the word count.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_SUMMARY_LENGTH 1000

int main() {
    char text[MAX_SENTENCES][MAX_SENTENCE_LENGTH]; // Store each sentence of the text
    char summary[MAX_SUMMARY_LENGTH]; // Store the summary
    int sentence_scores[MAX_SENTENCES] = {0}; // Store the score of each sentence
    int sentence_lengths[MAX_SENTENCES] = {0}; // Store the length of each sentence
    int total_sentences = 0; // Total number of sentences in the text
    int summary_length = 0; // Total length of the summary
    int max_sentence_score = 0; // Maximum score of a sentence

    // Get the text from the user
    printf("Enter the text to be summarized:\n");
    while(total_sentences < MAX_SENTENCES) {
        fgets(text[total_sentences], MAX_SENTENCE_LENGTH, stdin);
        if(text[total_sentences][0] == '\n') break;
        sentence_lengths[total_sentences] = strlen(text[total_sentences]);
        total_sentences++;
    }

    // Calculate the score of each sentence
    for(int i = 0; i < total_sentences; i++) {
        char *token = strtok(text[i], " "); // Get the first word of the sentence
        while(token != NULL) {
            if(strstr(token, "important")) sentence_scores[i] += 5; // If the word is important, add 5 to the score
            if(strstr(token, "essential")) sentence_scores[i] += 4; // If the word is essential, add 4 to the score
            if(strstr(token, "key")) sentence_scores[i] += 3; // If the word is key, add 3 to the score
            if(strstr(token, "relevant")) sentence_scores[i] += 2; // If the word is relevant, add 2 to the score
            if(strstr(token, "interesting")) sentence_scores[i] += 1; // If the word is interesting, add 1 to the score
            token = strtok(NULL, " "); // Get the next word
        }
        if(sentence_scores[i] > max_sentence_score) max_sentence_score = sentence_scores[i]; // Update the maximum score
    }

    // Generate the summary
    for(int i = 0; i < total_sentences; i++) {
        if((sentence_scores[i] * 100 / max_sentence_score) >= 50 && summary_length + sentence_lengths[i] <= MAX_SUMMARY_LENGTH) {
            strcat(summary, text[i]); // Add the sentence to the summary
            summary_length += sentence_lengths[i];
        }
    }

    // Print the summary
    printf("\nSummary:\n");
    printf("%s", summary);

    return 0;
}