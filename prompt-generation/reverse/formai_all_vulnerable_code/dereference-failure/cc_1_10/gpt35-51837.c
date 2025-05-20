//FormAI DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Define the maximum input text length and the maximum output summary length */
#define MAX_INPUT_TEXT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 200

/* Function to check if the character is a sentence-ending punctuation mark */
int is_sentence_end(char c) {
    if (c == '.' || c == '?' || c == '!') {
        return 1;
    }
    return 0;
}

/* Function to generate the summary of the input text */
void generate_summary(char *input_text, char *output_summary) {
    /* Initialize the current length of the summary as zero */
    int summary_length = 0;
    /* Initialize the index of the current sentence as zero */
    int current_sentence_index = 0;
    /* Loop through the input text character by character */
    for (int i = 0; i < strlen(input_text); i++) {
        /* If the current character is a sentence-ending punctuation mark */
        if (is_sentence_end(input_text[i]) && i > 0 && i < strlen(input_text) - 1) {
            /* Copy the sentence to the summary */
            strncat(output_summary, input_text + current_sentence_index, i - current_sentence_index + 1);
            /* Update the summary length */
            summary_length += i - current_sentence_index + 1;
            /* If the summary length exceeds the maximum summary length, break the loop */
            if (summary_length >= MAX_SUMMARY_LENGTH) {
                break;
            }
            /* Update the current sentence index */
            current_sentence_index = i + 1;
        }
    }
}

int main() {
    /* Allocate memory for the input text and the output summary */
    char *input_text = (char *) malloc(MAX_INPUT_TEXT_LENGTH * sizeof(char));
    char *output_summary = (char *) malloc(MAX_SUMMARY_LENGTH * sizeof(char));
    /* Get the input text from the user */
    printf("Enter the input text:\n");
    fgets(input_text, MAX_INPUT_TEXT_LENGTH, stdin);
    /* Convert the input text to lowercase */
    for (int i = 0; i < strlen(input_text); i++) {
        input_text[i] = tolower(input_text[i]);
    }
    /* Generate the summary of the input text */
    generate_summary(input_text, output_summary);
    /* Print the output summary */
    printf("\nThe output summary is:\n%s\n", output_summary);
    /* Free the memory allocated */
    free(input_text);
    free(output_summary);
    return 0;
}