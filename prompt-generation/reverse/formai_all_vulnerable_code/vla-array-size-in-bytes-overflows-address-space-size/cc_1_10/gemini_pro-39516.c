//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to print all the subsets of a given set
void printSubsets(int arr[], int n)
{
    // Base case: if the set is empty, print the empty set
    if (n == 0)
    {
        printf("Empty set\n");
        return;
    }

    // Recursive case: for each element in the set, print the subsets that include that element and the subsets that do not include that element
    for (int i = 0; i < (1 << n); i++)
    {
        // Print the subset that includes the current element
        printf("{");
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");

        // Print the subsets that do not include the current element
        printSubsets(arr, n - 1);
    }
}

// Main function
int main()
{
    // Get the set of elements
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print all the subsets of the set
    printSubsets(arr, n);

    return 0;
}