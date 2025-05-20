//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program generates a summary of a given text. 
 * The program uses a naive approach to determine the sentence worthiness.
 * The program takes user input on the text to summarize as well as the percent of the text to summarize.
 * The program outputs the summary of the text based on the percentage taken.
 * This program only works for English text.
**/

/**
 * @brief Function that determines if a char is a sentence ending character.
 * 
 * @param   c   the char to check
 * @return      1 if the char is a sentence ending character, 0 otherwise
**/
int is_sentence_ending(char c){
    // The ending of a sentence can be determined by one of these characters: ".", "?", "!"
    if (c == '.' || c == '?' || c == '!'){
        return 1;
    }
    return 0;
}

/**
 * @brief Function that determines if a sentence contains any of the common stop words.
 * 
 * @param   sentence    the sentence to check
 * @return              1 if the sentence contains a stop word, 0 otherwise
**/
int contains_stop_word(char* sentence){
    // Common stop words found in English text.
    const char* stop_words[] = {"a", "an", "the", "this", "that", "these", "those", "my", "your", "his", "her", "its", "our", "their", "of", "in", "to", "for", "on", "at", "by"};
    int num_of_stop_words = sizeof(stop_words)/sizeof(stop_words[0]);

    // Tokenize the string by spaces to get individual words.
    char* word;
    word = strtok(sentence, " ");
    while (word != NULL){
        for (int i=0; i<num_of_stop_words; i++){
            if (strcmp(word, stop_words[i]) == 0){
                return 1;
            }
        }
        word = strtok(NULL, " ");
    }

    return 0;
}

/**
 * @brief Function that generates a summary of a given text based on percent taken.
 * 
 * @param   text            the text to summarize
 * @param   percent_taken   the percentage of text to summarize
 * @return                  the generated summary
**/
char* generate_summary(char* text, double percent_taken){

    // The summary will be stored in this string.
    char* summary = (char*) malloc(sizeof(char)*10000);
    summary[0] = '\0';

    // Split text into sentences based on sentence ending characters.
    char* sentence;
    sentence = strtok(text, ".?!");
    while (sentence != NULL){

        // Check if sentence contains any of the common stop words.
        if (!contains_stop_word(sentence)){

            // Calculate the sentence worth based on the number of chars.
            int num_of_chars = strlen(sentence);
            double sentence_worth = (double) num_of_chars / strlen(text) * 100;

            // If sentence is worthy, add it to the summary.
            if (sentence_worth >= percent_taken){
                strcat(summary, sentence);
                strcat(summary, ". ");
            }
        }

        // Get the next sentence.
        sentence = strtok(NULL, ".?!");
    }

    return summary;
}

int main(){

    // Get user input on text to summarize and percentage of text to summarize.
    char* text = "";
    double percent_taken;
    printf("Enter the text you want to summarize:\n");
    scanf("%[^\n]s", text);
    printf("Enter the percentage of text to summarize (0-100):\n");
    scanf("%lf", &percent_taken);

    // Generate summary of text based on percent taken, and output the summary.
    char* summary = generate_summary(text, percent_taken);
    printf("\nSummary:\n%s\n", summary);

    // Free the allocated memory.
    free(summary);

    return 0;
}