//Gemma-7B DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{
    // Declare variables
    char **arr = NULL;
    int i, j, k, n, m, ctr = 0, flag = 0;
    float avg = 0.0f, sum = 0.0f, stddev = 0.0f;

    // Allocate memory for the array
    arr = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the number of students and courses
    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the number of courses: ");
    scanf("%d", &m);

    // Get the student's grades
    for (i = 0; i < n; i++)
    {
        printf("Enter the student's name: ");
        scanf("%s", arr[i]);

        for (j = 0; j < m; j++)
        {
            printf("Enter the student's grade for course %d: ", j + 1);
            scanf("%f", &arr[i][j]);
        }
    }

    // Calculate the average grade for each student
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
        avg = sum / m;
        printf("The average grade for student %s is: %.2f\n", arr[i], avg);
    }

    // Calculate the standard deviation for each student
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            stddev = sqrt((sum - avg * m) / (m - 1));
            printf("The standard deviation for student %s is: %.2f\n", arr[i], stddev);
        }
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}