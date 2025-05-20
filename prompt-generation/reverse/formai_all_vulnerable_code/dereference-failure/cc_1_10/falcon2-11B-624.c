//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Initialize variables
    char *filename = "input.txt";
    char *word = NULL;
    int wordCount = 0;
    int i, j, k;
    int frequency[256] = {0};

    // Open file for reading
    FILE *fp = fopen(filename, "r");

    // Check if file opened successfully
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Read words from file and count frequency
    while (fgets(word, sizeof(word), fp))
    {
        // Convert word to lowercase
        for (i = 0; i < strlen(word); i++)
        {
            word[i] = tolower(word[i]);
        }

        // Count frequency of each character
        for (i = 0; i < strlen(word); i++)
        {
            frequency[word[i]]++;
        }

        // Increment word count
        wordCount++;
    }

    // Close file
    fclose(fp);

    // Print word frequency
    printf("Word frequency:\n");
    for (i = 0; i < 256; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%c: %d\n", i, frequency[i]);
        }
    }

    // Free memory
    free(word);

    return 0;
}