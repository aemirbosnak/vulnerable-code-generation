//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>

// Function to sort the array in ascending order
void sort(int n, int arr[])
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to find the minimum number of coins required
void findCoins(int n, int arr[], int value)
{
    // Sort the array in ascending order
    sort(n, arr);

    int count = 0;
    // Traverse through the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        while (value >= arr[i])
        {
            // Subtract the value of the coin from the total value
            value -= arr[i];
            count++;
        }
    }

    printf("Minimum number of coins required: %d\n", count);
}

int main()
{
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the values of the coins: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int value;
    printf("Enter the total value: ");
    scanf("%d", &value);

    findCoins(n, arr, value);

    return 0;
}