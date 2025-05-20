//Gemma-7B DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    // Allocate memory for the data
    char *data = malloc(MAX_SIZE);

    // Read data from the file
    FILE *fp = fopen("data.txt", "r");
    fscanf(fp, "%s", data);

    // Close the file
    fclose(fp);

    // Tokenize the data
    char *token = strtok(data, ",");

    // Create an array of integers
    int *nums = malloc(MAX_SIZE);

    // Populate the array
    int i = 0;
    while (token)
    {
        nums[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    // Find the maximum number in the array
    int max_num = nums[0];
    for (i = 1; i < i; i++)
    {
        if (nums[i] > max_num)
        {
            max_num = nums[i];
        }
    }

    // Print the maximum number
    printf("The maximum number in the data is: %d\n", max_num);

    // Free the memory
    free(data);
    free(nums);

    return 0;
}