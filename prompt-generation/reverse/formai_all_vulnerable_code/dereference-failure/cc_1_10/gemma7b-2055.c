//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, j, score, maxScore = 0;
    float avgScore;

    // Allocate memory for an array of student scores
    int *scores = (int *)malloc(n * sizeof(int));

    // Get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Get the student scores
    for (i = 0; i < n; i++)
    {
        printf("Enter the score of student %d: ", i + 1);
        scanf("%d", &scores[i]);

        // Update the maximum score if necessary
        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
        }
    }

    // Calculate the average score
    avgScore = (float)(sumOfScores(scores, n) / n);

    // Print the results
    printf("The maximum score is: %d", maxScore);
    printf("\nThe average score is: %.2f", avgScore);

    // Free the allocated memory
    free(scores);
}

int sumOfScores(int *scores, int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += scores[i];
    }

    return sum;
}