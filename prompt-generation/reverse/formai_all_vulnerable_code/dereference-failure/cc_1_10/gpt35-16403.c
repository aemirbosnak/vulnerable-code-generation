//FormAI DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numOfStocks;
    printf("How many stocks would you like to track?\n");
    scanf("%d", &numOfStocks);
    printf("\n");

    char** stockNames = (char**)malloc(sizeof(char*) * numOfStocks);
    float* stockValues = (float*)calloc(numOfStocks, sizeof(float));

    for(int i=0; i<numOfStocks; i++)
    {
        printf("Enter the name of stock #%d: ", i+1);
        stockNames[i] = (char*)malloc(sizeof(char) * 20);
        scanf("%s", stockNames[i]);
    }

    printf("\nGreat! You are now tracking the following stocks:\n");
    for(int i=0; i<numOfStocks; i++)
    {
        printf("%s\n", stockNames[i]);
    }

    while(1)
    {
        printf("\n------------------------------\n");
        printf("The current values of your stocks are:\n");
        for(int i=0; i<numOfStocks; i++)
        {
            printf("%s: $%.2f\n", stockNames[i], stockValues[i]);
        }

        printf("\nEnter 'quit' to exit or the name of the stock you would like to update: ");
        char input[20];
        scanf("%s", input);

        if(strcmp(input, "quit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        for(int i=0; i<numOfStocks; i++)
        {
            if(strcmp(input, stockNames[i]) == 0)
            {
                printf("Enter the new value of %s: ", stockNames[i]);
                scanf("%f", &stockValues[i]);
                printf("The value of %s has been updated to $%.2f\n", stockNames[i], stockValues[i]);
                break;
            }

            if(i == numOfStocks - 1)
            {
                printf("Sorry, I couldn't find the stock you were looking for. Please try again.\n");
            }
        }
    }

    for(int i=0; i<numOfStocks; i++)
    {
        free(stockNames[i]);
    }
    free(stockValues);
    free(stockNames);

    return 0;
}