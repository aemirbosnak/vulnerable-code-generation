//Gemma-7B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>

void find_love(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) == 0)
            {
                printf("%s and %s are a perfect pair.\n", arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
    }

    printf("Enter the names of each person: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    find_love(arr, n);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}