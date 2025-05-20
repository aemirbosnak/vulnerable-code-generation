//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWERS 10

int main()
{
    char **answers = NULL;
    int num_answers = 0;
    int i, j, k;

    // Paranoia begins...

    answers = malloc(MAX_ANSWERS * sizeof(char *));
    for (i = 0; i < MAX_ANSWERS; i++)
    {
        answers[i] = malloc(1024 * sizeof(char));
    }

    // ...and intensifies...

    printf("Please enter your answer for the question:");
    scanf("%s", answers[num_answers]);
    num_answers++;

    // ...even further...

    for (i = 0; i < num_answers; i++)
    {
        for (j = 0; j < MAX_ANSWERS; j++)
        {
            for (k = 0; k < 1024; k++)
            {
                if (strcmp(answers[i], answers[j]) == 0 && i != j)
                {
                    printf("ERROR: Answer plagiarism detected!");
                    exit(1);
                }
            }
        }
    }

    // ...and finally...

    printf("Your answer has been recorded. Thank you for participating!");

    // Free memory
    for (i = 0; i < MAX_ANSWERS; i++)
    {
        free(answers[i]);
    }
    free(answers);

    return 0;
}