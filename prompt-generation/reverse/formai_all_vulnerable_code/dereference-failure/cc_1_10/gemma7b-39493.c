//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void itoa(int num, char *s);

int main()
{
    int n, i, j, k, l;
    char **a;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    a = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(MAX * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            a[i][j] = '\0';
        }
    }

    printf("Enter the number of columns: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            printf("Enter the character for (%d, %d): ", i, j);
            scanf("%c", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}

void itoa(int num, char *s)
{
    int i = 0;
    char *p = s;

    do
    {
        int digit = num % 10;
        num /= 10;
        *p++ = digit + '0';
    } while (num);

    *p = '\0';
}