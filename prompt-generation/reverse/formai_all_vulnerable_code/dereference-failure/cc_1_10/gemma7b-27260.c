//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *text = NULL;
    int text_size = 0;
    int i = 0;
    int count = 0;
    double average_sentence_length = 0.0;
    double total_sentence_length = 0.0;

    // Allocate memory for the text
    text = malloc(MAX_BUFFER_SIZE);

    // Read text from the user
    printf("Enter text: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Remove newline character from the text
    text = strchr(buffer, '\n');
    if (text)
    {
        *text = '\0';
    }

    // Calculate the text size
    text_size = strlen(text);

    // Tokenize the text
    char *tokens = strtok(text, " .");

    // Count the number of sentences in the text
    count = 0;
    while (tokens)
    {
        tokens = strtok(NULL, " .");
        count++;
    }

    // Calculate the average sentence length
    average_sentence_length = (double)text_size / count;

    // Calculate the total sentence length
    total_sentence_length = (double)text_size - average_sentence_length * (count - 1);

    // Print the results
    printf("Number of sentences: %d\n", count);
    printf("Average sentence length: %.2lf words\n", average_sentence_length);
    printf("Total sentence length: %.2lf words\n", total_sentence_length);

    // Free the memory allocated for the text
    free(text);

    return 0;
}