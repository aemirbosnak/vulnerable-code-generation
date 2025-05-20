//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BankingRecordSystem(char **arr, int size)
{
    int i, j, k, found = 0;
    char search_name[20];

    printf("Enter the name of the account you want to search: ");
    scanf("%s", search_name);

    for (i = 0; i < size; i++)
    {
        if (strcmp(arr[i], search_name) == 0)
        {
            found = 1;
            printf("Account details:\n");
            printf("Name: %s\n", arr[i]);
            printf("Balance: %d\n", arr[i + 1]);
            printf("Transactions:\n");
            for (j = 0; j < arr[i + 2]; j++)
            {
                printf("Date: %s\n", arr[i + 2 + j]);
                printf("Description: %s\n", arr[i + 2 + j + 1]);
                printf("Amount: %d\n", arr[i + 2 + j + 2]);
            }
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }
}

int main()
{
    char **arr = NULL;
    int size = 0;

    // Allocate memory for the array
    arr = (char **)malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (char *)malloc(20);
    }

    // Create a sample data set
    arr[0] = "John Doe";
    arr[1] = 1000;
    arr[2] = 3;
    arr[3] = "2023-01-01";
    arr[4] = "Salary";
    arr[5] = 200;

    arr[6] = "Jane Doe";
    arr[7] = 500;
    arr[8] = 2;
    arr[9] = "2023-01-02";
    arr[10] = "Shopping";
    arr[11] = 100;

    // Call the Banking Record System function
    BankingRecordSystem(arr, size);

    // Free the memory allocated for the array
    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}