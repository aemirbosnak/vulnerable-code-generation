//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void text_to_ascii(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        switch (*arr[i])
        {
            case 'a':
            case 'A':
                arr[i] = "(\u2422)";
                break;
            case 'b':
            case 'B':
                arr[i] = "(\u2423)";
                break;
            case 'c':
            case 'C':
                arr[i] = "(\u2424)";
                break;
            case 'd':
            case 'D':
                arr[i] = "(\u2425)";
                break;
            case 'e':
            case 'E':
                arr[i] = "(\u2426)";
                break;
            default:
                arr[i] = "*";
        }
    }
}

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    srand(time(NULL));
    int n = rand() % MAX;

    printf("Generating ASCII art...\n");

    for (int i = 0; i < n; i++)
    {
        arr[i] = "Hello, world!";
    }

    text_to_ascii(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}