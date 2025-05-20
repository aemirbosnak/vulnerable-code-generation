//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void txt_to_ascii(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        switch (*arr[i])
        {
            case 'a':
            case 'A':
                arr[i] = '\243';
                break;
            case 'b':
            case 'B':
                arr[i] = '\244';
                break;
            case 'c':
            case 'C':
                arr[i] = '\245';
                break;
            case 'd':
            case 'D':
                arr[i] = '\246';
                break;
            case 'e':
            case 'E':
                arr[i] = '\247';
                break;
            default:
                arr[i] = '\0';
                break;
        }
    }
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter text: ");
    getline(stdin, arr, &n);

    txt_to_ascii(arr, n);

    printf("ASCII art:\n");
    for (int i = 0; arr[i] != NULL; i++)
    {
        printf("%c ", arr[i]);
    }

    free(arr);

    return 0;
}