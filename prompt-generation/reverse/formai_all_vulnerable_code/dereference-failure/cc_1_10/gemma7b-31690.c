//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shocker(int n)
{
    switch (n)
    {
        case 1:
            printf("OMG!!! You got me!!!\n");
            break;
        case 2:
            printf("Oh god... I am so sorry...\n");
            break;
        case 3:
            printf("I am not your slave, you pathetic human!\n");
            break;
        default:
            printf("I have no idea what you're talking about...\n");
            break;
    }
}

void search(int n, char **arr)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], "apple") == 0)
        {
            shocker(1);
        }
        else if (strcmp(arr[i], "banana") == 0)
        {
            shocker(2);
        }
        else if (strcmp(arr[i], "orange") == 0)
        {
            shocker(3);
        }
    }
}

int main()
{
    char **arr = NULL;
    int n = 0;

    // Allocate memory for the array
    arr = (char **)malloc(n * sizeof(char *));

    // Get the number of items in the array
    printf("Enter the number of items in the array: ");
    scanf("%d", &n);

    // Create the array
    arr = (char **)malloc(n * sizeof(char *));

    // Get the items in the array
    printf("Enter the items in the array: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
        scanf("%s", arr[i]);
    }

    // Search for the item
    search(n, arr);

    // Free the memory allocated for the array
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}