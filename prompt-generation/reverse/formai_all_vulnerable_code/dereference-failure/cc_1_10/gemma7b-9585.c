//Gemma-7B DATASET v1.0 Category: Email Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    int i, j, k, n, m, size, flag = 0;
    char **arr = NULL;

    // Allocate memory for the array
    arr = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Get the number of messages
    printf("Enter the number of messages: ");
    scanf("%d", &n);

    // Create the messages
    for (i = 0; i < n; i++)
    {
        printf("Enter the message: ");
        getline(arr[i], MAX_SIZE, stdin);
    }

    // Sort the messages
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print the sorted messages
    printf("Sorted messages:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    // Free the memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}