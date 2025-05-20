//Gemma-7B DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    scanf("Enter the number of players: ", &n);

    int arr[n][MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Each player gets a random number of cards
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = rand() % 13 + 1;
        }
    }

    // Sort the cards in descending order
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE - 1; j++)
        {
            for (int k = j + 1; k < MAX_SIZE; k++)
            {
                if (arr[i][j] < arr[i][k])
                {
                    swap(&arr[i][j], &arr[i][k]);
                }
            }
        }
    }

    // Print the sorted cards
    for (int i = 0; i < n; i++)
    {
        printf("Player %d's cards: ", i + 1);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}