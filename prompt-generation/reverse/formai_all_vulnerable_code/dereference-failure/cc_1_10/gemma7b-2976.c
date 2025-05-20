//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch;
    int i = 0, j = 0, k = 0;
    char **a = NULL, **b = NULL;
    a = (char**)malloc(sizeof(char*) * 10);
    for (i = 0; i < 10; i++)
    {
        a[i] = (char*)malloc(sizeof(char) * 20);
    }
    b = (char**)malloc(sizeof(char*) * 10);
    for (i = 0; i < 10; i++)
    {
        b[i] = (char*)malloc(sizeof(char) * 20);
    }

    while ((ch = getchar()) != EOF)
    {
        switch (ch)
        {
            case 'a':
                a[k++] = ch;
                break;
            case 'b':
                b[j++] = ch;
                break;
            default:
                printf("Wrong input\n");
                break;
        }
    }

    printf("Content of a:\n");
    for (i = 0; i < k; i++)
    {
        printf("%c ", a[i]);
    }
    printf("\nContent of b:\n");
    for (i = 0; i < j; i++)
    {
        printf("%c ", b[i]);
    }

    free(a);
    free(b);
    return 0;
}