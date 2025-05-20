//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SENTENCE_LENGTH 50 // Maximum sentence length
#define MAX_ATTEMPTS 5 // Maximum number of attempts
#define SECOND_IN_MICROSECONDS 1000000 // Number of microseconds in a second

// Generate random sentence for typing test
char* generate_sentence()
{
    char *sentence = malloc(SENTENCE_LENGTH * sizeof(char));
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
    int i;
    for (i = 0; i < SENTENCE_LENGTH - 1; i++)
    {
        sentence[i] = alphabet[rand() % 53];
    }
    sentence[SENTENCE_LENGTH - 1] = '\0';
    return sentence;
}

// Main function to calculate typing speed
int main()
{
    int i, j = 0, correct_entries = 0, speed;
    char *sentence, *input = malloc(SENTENCE_LENGTH * sizeof(char));
    struct timespec start_time, end_time;

    // Seed random number generator
    srand(time(NULL));

    // Generate random sentence
    sentence = generate_sentence();

    // Display sentence to user
    printf("Type the following sentence: \n\n%s\n\n", sentence);

    // Record starting time
    clock_gettime(CLOCK_REALTIME, &start_time);

    // Allow user to input sentence
    for (i = 0; i < MAX_ATTEMPTS; i++)
    {
        printf("Attempt %d: ", i + 1);
        fgets(input, SENTENCE_LENGTH, stdin);

        // Strip newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Check if input matches sentence
        if (strcmp(input, sentence) == 0)
        {
            correct_entries = 1;
            clock_gettime(CLOCK_REALTIME, &end_time);
            break;
        }
        else
        {
            printf("Incorrect entry. Try again.\n");
        }
    }

    // Calculate typing speed if entry is correct
    if (correct_entries)
    {
        // Calculate elapsed time
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

        // Calculate typing speed in characters per minute and round to nearest integer
        speed = (int) ((SENTENCE_LENGTH / elapsed_time) * (60.0 / 5.0) + 0.5);

        printf("Congrats! You typed the sentence correctly in %.2lf seconds.\n", elapsed_time);
        printf("Your typing speed is %d characters per minute.\n", speed);
    }
    else
    {
        printf("Failed to type the sentence correctly.\n");
    }

    // Free allocated memory
    free(sentence);
    free(input);

    return 0;
}