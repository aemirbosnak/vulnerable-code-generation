//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char **readCSV(char **buffer)
{
    int i = 0, j = 0, count = 0, state = 0;
    char *line = NULL, **data = NULL;

    line = malloc(MAX_BUFFER_SIZE);
    data = malloc(MAX_BUFFER_SIZE * 10);

    while (fgets(line, MAX_BUFFER_SIZE, stdin) != NULL)
    {
        switch (state)
        {
            case 0:
                if (line[0] == '"')
                {
                    state = 1;
                }
                else
                {
                    data[count++] = strdup(line);
                }
                break;
            case 1:
                if (line[0] == '"')
                {
                    state = 0;
                }
                else
                {
                    data[count++] = strdup(line);
                }
                break;
        }
    }

    free(line);
    free(data);

    return data;
}

int main()
{
    char **buffer = NULL;
    char **data = readCSV(&buffer);

    for (int i = 0; data[i] != NULL; i++)
    {
        printf("%s\n", data[i]);
    }

    free(data);

    return 0;
}