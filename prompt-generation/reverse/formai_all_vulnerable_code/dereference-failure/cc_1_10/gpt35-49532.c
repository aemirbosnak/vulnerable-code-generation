//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of our two numbers
#define SIZE 100

int main()
{
    // We need to seed our random number generator
    srand(time(NULL));
    
    // Allocate memory for our arrays
    int* num1 = (int*)malloc(sizeof(int) * SIZE);
    int* num2 = (int*)malloc(sizeof(int) * SIZE);
    int* result = (int*)malloc(sizeof(int) * (SIZE + 1));
    
    // Generate two random numbers
    for(int i = 0; i < SIZE; i++)
    {
        num1[i] = rand() % 10;
        num2[i] = rand() % 10;
    }
    
    // Add the two numbers together
    int carry = 0;
    for(int i = SIZE - 1; i >= 0; i--)
    {
        int sum = num1[i] + num2[i] + carry;
        carry = sum / 10;
        result[i + 1] = sum % 10;
    }
    result[0] = carry;
    
    // Print out the problem and solution
    printf("What is the sum of the following two numbers?\n\n");
    for(int i = 0; i < SIZE; i++)
        printf("%d ", num1[i]);
    printf("\n+");
    for(int i = 0; i < SIZE; i++)
        printf(" %d", num2[i]);
    printf("\n");
    for(int i = 0; i < SIZE + 1; i++)
        printf("- ");
    printf("\n");
    for(int i = 0; i < SIZE + 1; i++)
        printf("%d ", result[i]);
    
    // Free the memory we allocated
    free(num1);
    free(num2);
    free(result);
    
    return 0;
}