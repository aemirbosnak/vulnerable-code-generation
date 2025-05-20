//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n, t, score = 0, speed = 0;
    char str[100];

    printf("Welcome to the C Typing Speed Test!\n");

    // Get the number of tests
    printf("How many tests do you want to take? ");
    scanf("%d", &n);

    // Start the timer
    time_t start = time(NULL);

    // Take the tests
    for (t = 0; t < n; t++)
    {
        // Get the test string
        printf("Enter a string: ");
        scanf("%s", str);

        // Calculate the score
        score = strlen(str) * 10;

        // Calculate the speed
        speed = score / (time(NULL) - start);

        // Print the results
        printf("Your score: %d\n", score);
        printf("Your speed: %d words per second\n", speed);

        // Reset the score and speed
        score = 0;
        speed = 0;
    }

    // End the timer
    time_t end = time(NULL);

    // Print the total time taken
    printf("Total time taken: %f seconds\n", end - start);

    // Thank the user
    printf("Thank you for taking the C Typing Speed Test!\n");

    return 0;
}