//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main()
{
    char **words = NULL;
    int i, j, k, time_start, time_end, total_time = 0;
    words = malloc(MAX_WORDS * sizeof(char *));

    for (i = 0; i < MAX_WORDS; i++)
    {
        words[i] = malloc(20 * sizeof(char));
    }

    // Fill the words array with random words
    for (i = 0; i < MAX_WORDS; i++)
    {
        for (j = 0; j < 20; j++)
        {
            words[i][j] = rand() % 26 + 97;
        }
    }

    // Start the timer
    time_start = clock();

    // Have the user type the words
    for (k = 0; k < MAX_WORDS; k++)
    {
        printf("Enter word %d: ", k + 1);
        scanf("%s", words[k]);
    }

    // Stop the timer
    time_end = clock();

    // Calculate the total time
    total_time = time_end - time_start;

    // Print the results
    printf("Total time: %d seconds\n", total_time);

    // Free the memory
    for (i = 0; i < MAX_WORDS; i++)
    {
        free(words[i]);
    }

    free(words);

    return 0;
}