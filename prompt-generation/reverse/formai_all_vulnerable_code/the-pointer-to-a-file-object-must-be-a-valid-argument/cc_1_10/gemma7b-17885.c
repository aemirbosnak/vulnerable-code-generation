//Gemma-7B DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char **arr = NULL;
    int n = 0, i, j, k, l, m, count = 0;

    // Allocate memory dynamically for the array
    arr = (char **)malloc(n * sizeof(char *));

    // Get the number of lines in the text file
    FILE *fp = fopen("text.txt", "r");
    char line[1024];
    while (fgets(line, 1024, fp) != NULL)
    {
        n++;
    }
    fclose(fp);

    // Read the text file again and store the lines in the array
    fp = fopen("text.txt", "r");
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc((l + 1) * sizeof(char));
        fgets(arr[i], l + 1, fp);
    }
    fclose(fp);

    // Iterate over the array and count the number of words in each line
    for (i = 0; i < n; i++)
    {
        char *p = arr[i];
        while (p)
        {
            if (isspace(*p))
            {
                count++;
            }
            p++;
        }
        printf("Line %d has %d words.\n", i + 1, count);
        count = 0;
    }

    // Free the memory allocated for the array
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}