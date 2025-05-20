//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 100

char* summarize(char* input) {
    char* output = calloc(MAX_OUTPUT_SIZE, sizeof(char));
    char* token;
    char* delimiter = ".,;?!";
    int total_sentences = 0;
    int total_words = 0;

    token = strtok(input, delimiter);

    while(token) {
        if(strchr(delimiter, token[strlen(token) - 1])) {
            total_sentences++;
        }
        total_words++;
        token = strtok(NULL, delimiter);
    }

    int avg_words_per_sentence = total_words / total_sentences;
    int output_idx = 0;

    sprintf(output + output_idx, "I analyzed your text and found out that there are %d sentences and %d words.\n", total_sentences, total_words);
    output_idx = strlen(output);

    if(avg_words_per_sentence <= 10) {
        sprintf(output + output_idx, "Wow! Your writing is clear and easy to understand. Keep up the good work!\n");
    } else if(avg_words_per_sentence <= 20) {
        sprintf(output + output_idx, "Your writing is a bit dense. Try breaking up your sentences to make it easier on the reader.\n");
    } else {
        sprintf(output + output_idx, "Your writing is too complex! Break up those long sentences and make your point in simpler terms.\n");
    }

    output_idx = strlen(output);

    if(total_words >= 500) {
        sprintf(output + output_idx, "Seems like you have a lot to say. Consider breaking up this text into smaller, more digestible chunks.\n"); 
    }

    return output;
}

int main() {
    char* input = calloc(MAX_INPUT_SIZE, sizeof(char));

    printf("Hi there! I'm your friendly text summarizer. Please enter some text:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    char* summary = summarize(input);
    printf("\nHere's your summary:\n%s\n", summary);

    free(input);
    free(summary);

    return 0;
}