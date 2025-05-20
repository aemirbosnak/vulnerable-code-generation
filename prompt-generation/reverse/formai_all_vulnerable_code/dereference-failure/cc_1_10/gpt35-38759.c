//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of input text
#define MAX_SUMMARY 100 // Maximum length of summary

char* summarize(char* input_text, int max_summary_length)
{
    // Initialize variables
    char* summary = malloc(sizeof(char) * MAX_SUMMARY); // Allocate memory for summary
    char* token;

    // Copy input text to temporary variable
    char temp_text[MAX_LENGTH];
    strcpy(temp_text, input_text);

    // Identify the end of the sentence
    char* end_sentence = strrchr(temp_text, '.');

    // If the end of the sentence is found
    if (end_sentence != NULL)
    {
        // Replace the end of the sentence with a null character
        *end_sentence = '\0';
    }

    // Tokenize the input text
    token = strtok(temp_text, " ");

    // Loop through the words until the max summary length is reached
    int i = 0;
    while (token != NULL && i < max_summary_length)
    {
        strcat(summary, token);
        strcat(summary, " ");
        token = strtok(NULL, " ");
        i++;
    }

    // Add ellipsis if summary is not complete
    if (i == max_summary_length)
    {
        strcat(summary, "...");
    }

    return summary;
}

int main()
{
    // Initialize variables
    char input_text[MAX_LENGTH];
    char* summary;

    // Get input text from user
    printf("Enter the text to be summarized:\n");
    fgets(input_text, MAX_LENGTH, stdin);

    // Get desired summary length from user
    int max_summary_length;
    printf("Enter the maximum length of the summary:\n");
    scanf("%d", &max_summary_length);

    // Get the summary of the input text
    summary = summarize(input_text, max_summary_length);

    // Print the summary
    printf("Summary:\n%s", summary);

    // Free memory
    free(summary);

    return 0;
}