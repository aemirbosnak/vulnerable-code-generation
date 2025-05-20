//FormAI DATASET v1.0 Category: Math exercise ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the max size of the array
#define MAX_ARRAY_SIZE 1000

// Define the range of numbers for our array
#define MIN_NUM 1
#define MAX_NUM 10

int main()
{
    // Seed the random function for random numbers
    srand(time(NULL));

    // Allocate memory for the array
    int *nums = (int *)malloc(MAX_ARRAY_SIZE * sizeof(int));

    // Fill the array with random numbers between MIN_NUM and MAX_NUM
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        nums[i] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    }

    // Print the array before performing any calculations
    printf("Original Array:\n");
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n\n");

    // Find the mean of the array
    int sum = 0;
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        sum += nums[i];
    }
    float mean = (float)sum / MAX_ARRAY_SIZE;
    printf("Mean of Array: %.2f\n", mean);

    // Find the median of the array
    int sorted_nums[MAX_ARRAY_SIZE];
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        sorted_nums[i] = nums[i];
    }
    for (int i = 0; i < MAX_ARRAY_SIZE - 1; i++)
    {
        for (int j = i + 1; j < MAX_ARRAY_SIZE; j++)
        {
            if (sorted_nums[i] > sorted_nums[j])
            {
                int temp = sorted_nums[i];
                sorted_nums[i] = sorted_nums[j];
                sorted_nums[j] = temp;
            }
        }
    }
    float median;
    if (MAX_ARRAY_SIZE % 2 == 0)
    {
        median = ((float)sorted_nums[MAX_ARRAY_SIZE / 2] + (float)sorted_nums[MAX_ARRAY_SIZE / 2 - 1]) / 2.0;
    }
    else
    {
        median = sorted_nums[MAX_ARRAY_SIZE / 2];
    }
    printf("Median of Array: %.2f\n", median);

    // Find the standard deviation of the array
    float std_deviation = 0;
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        std_deviation += (nums[i] - mean) * (nums[i] - mean);
    }
    std_deviation = sqrt(std_deviation / MAX_ARRAY_SIZE);
    printf("Standard Deviation of Array: %.2f\n", std_deviation);

    // Free the allocated memory
    free(nums);

    return 0;
}