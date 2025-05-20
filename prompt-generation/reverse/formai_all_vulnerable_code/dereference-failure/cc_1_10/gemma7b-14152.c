//Gemma-7B DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void analyze_data(char **data, int size)
{
    for (int i = 0; i < size; i++)
    {
        char *line = data[i];
        int words_count = count_words(line);
        printf("Line %d: %s, Words Count: %d\n", i + 1, line, words_count);
    }
}

int count_words(char *line)
{
    int words_count = 0;
    char *word = strtok(line, " ");
    while (word)
    {
        words_count++;
        word = strtok(NULL, " ");
    }
    return words_count;
}

int main()
{
    char **data = NULL;
    int size = 0;

    // Assuming there is a file named "data.txt" in the same directory
    FILE *fp = fopen("data.txt", "r");
    if (fp)
    {
        // Read the file line by line and allocate memory for each line
        while (getline(fp, data[size] = malloc(MAX_SIZE), MAX_SIZE) != -1)
        {
            size++;
        }

        fclose(fp);
    }

    analyze_data(data, size);

    // Free the memory allocated for each line
    for (int i = 0; i < size; i++)
    {
        free(data[i]);
    }

    return 0;
}