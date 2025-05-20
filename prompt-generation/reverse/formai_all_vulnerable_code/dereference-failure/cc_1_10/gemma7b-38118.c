//Gemma-7B DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int i = 0, j = 0, k = 0;
    int n = 0, m = 0;

    // Allocate memory for the array
    arr = (char**)malloc(n * m * sizeof(char));

    // Read the number of rows and columns
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    // Read the data
    printf("Enter the data: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = getchar();
        }
    }

    // Find the maximum number of consecutive digits
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            int count = 0;
            for (k = 0; arr[i][j] - '0' >= count; k++)
            {
                count++;
            }
            if (count > k)
            {
                k = count;
            }
        }
    }

    // Print the maximum number of consecutive digits
    printf("The maximum number of consecutive digits is: %d", k);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}