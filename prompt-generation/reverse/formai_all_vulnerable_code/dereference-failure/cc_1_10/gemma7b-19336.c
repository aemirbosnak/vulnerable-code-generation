//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int n = 0, i = 0;
    char msg[] = "This is a hidden message!";

    printf("Enter the number of lines you want to store: ");
    scanf("%d", &n);

    arr = (char**)malloc(n * sizeof(char*));

    for (i = 0; i < n; i++)
    {
        arr[i] = (char*)malloc(256 * sizeof(char));
    }

    printf("Enter the data for each line: ");

    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < 256; j++)
        {
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
            {
                arr[i][j] ^= msg[i];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    printf("Here is the hidden message: ");

    for (i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }

    return 0;
}