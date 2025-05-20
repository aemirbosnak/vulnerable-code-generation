//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char quote[] = "Peace comes from within. Do not seek it without.";
    int quote_length = sizeof(quote) / sizeof(quote[0]);
    int i, j, k, c, speed, time_taken, word_count = 0, len = 0;
    float accuracy;

    printf("Welcome to the C Typing Speed Test!\n\n");
    printf("Type the following quote: \n\n");

    for (i = 0; i < quote_length; i++)
    {
        printf("%c", quote[i]);
    }

    printf("\n\nPress Enter to start the test.");
    getchar();

    time_t start_time, end_time;

    time(&start_time);

    while (len != quote_length)
    {
        c = getchar();
        if (quote[len] == c)
        {
            len++;
        }
    }

    time(&end_time);

    time_taken = (int) difftime(end_time, start_time);

    printf("\n\nTime taken to complete the test: %d seconds\n\n", time_taken);

    for (i = 0; quote[i] != '\0'; i++)
    {
        if (quote[i] == ' ' || quote[i] == '\n')
        {
            word_count++;
        }
    }

    printf("Number of words in the quote: %d\n\n", word_count);

    speed = (quote_length / 5) / (time_taken / 60);

    printf("Typing speed: %d wpm (words per minute).\n\n", speed);

    printf("Your accuracy: ");

    for (j = 0; j < quote_length; j++)
    {
        if (quote[j] != ' ' && quote[j] != '\n')
        {
            if (getchar() == quote[j])
            {
                accuracy++;
            }
        }
    }

    accuracy = ((accuracy / quote_length) * 100);

    printf("%.2f%%\n\n", accuracy);

    if (accuracy >= 90)
    {
        printf("Well done! You have excellent typing skills!");
    }
    else if (accuracy >= 70)
    {
        printf("Good job! With a little practice, you can improve your typing skills!");
    }
    else
    {
        printf("Oops! You need to work on your typing skills!");
    }

    return 0;
}