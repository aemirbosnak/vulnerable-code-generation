//Gemma-7B DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, n, line_number = 1, word_count = 0;

    // Read the input text
    printf("Enter text: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Split the text into lines
    char *line = strtok(buffer, "\n");
    while (line)
    {
        // Count the number of words in each line
        n = count_words(line);
        word_count += n;

        // Increment the line number
        line_number++;

        // Free the memory allocated for the line
        free(line);
        line = strtok(NULL, "\n");
    }

    // Print the word count
    printf("Total number of words: %d\n", word_count);

    return 0;
}

int count_words(char *line)
{
    char *word = strtok(line, " ");
    int word_count = 0;

    while (word)
    {
        word_count++;
        word = strtok(NULL, " ");
    }

    return word_count;
}