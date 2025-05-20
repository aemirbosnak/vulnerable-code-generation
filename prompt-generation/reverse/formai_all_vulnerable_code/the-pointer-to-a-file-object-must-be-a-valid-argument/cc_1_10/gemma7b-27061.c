//Gemma-7B DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **arr = NULL;
    int i, j, k, n = 0, m = 0;

    // Allocate memory for the array
    arr = (char **)malloc(MAX * sizeof(char *));

    // Get the number of lines in the text file
    FILE *fp = fopen("text.txt", "r");
    char line[100];
    while (fgets(line, 100, fp) != NULL)
    {
        n++;
    }
    fclose(fp);

    // Allocate memory for each line in the array
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the text file again and store each line in the array
    fp = fopen("text.txt", "r");
    i = 0;
    while (fgets(line, 100, fp) != NULL)
    {
        strcpy(arr[i++], line);
    }
    fclose(fp);

    // Find the maximum length of a line in the array
    for (i = 0; i < n; i++)
    {
        m = (m < strlen(arr[i])) ? strlen(arr[i]) : m;
    }

    // Print the maximum length of a line
    printf("The maximum length of a line in the text file is: %d\n", m);

    // Free the memory allocated for the array
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}