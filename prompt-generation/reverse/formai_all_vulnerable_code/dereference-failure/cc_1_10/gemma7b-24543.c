//Gemma-7B DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

int main()
{
    // Allocate memory for the data
    char *data = (char *)malloc(MAX * sizeof(char));

    // Read the data from the file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    int i = 0;
    char line[MAX];
    while (fgets(line, MAX, fp) != NULL)
    {
        strcpy(data + i * MAX, line);
        i++;
    }
    fclose(fp);

    // preprocess the data
    char *processed_data = (char *)malloc(MAX * sizeof(char));
    i = 0;
    while (data[i] != '\0')
    {
        // Remove punctuation and convert to lowercase
        char ch = data[i];
        if (ispunct(ch) || ch >= 'A' && ch <= 'Z')
        {
            data[i] = '\0';
        }
        else
        {
            data[i] = tolower(ch);
        }
        i++;
    }

    // Create a frequency table
    int frequency[MAX] = {0};
    i = 0;
    while (processed_data[i] != '\0')
    {
        frequency[processed_data[i]]++;
        i++;
    }

    // Print the frequency table
    for (i = 0; i < MAX; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%c: %d\n", i, frequency[i]);
        }
    }

    // Free the memory
    free(data);
    free(processed_data);

    return 0;
}