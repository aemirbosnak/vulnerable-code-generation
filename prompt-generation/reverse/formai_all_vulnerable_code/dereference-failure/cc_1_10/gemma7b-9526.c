//Gemma-7B DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDLES 10

int main()
{
    int numCandles = MAX_CANDLES;
    char **candleShapes = (char **)malloc(numCandles * sizeof(char *));
    for (int i = 0; i < numCandles; i++)
    {
        candleShapes[i] = (char *)malloc(20 * sizeof(char));
    }

    // Shape shifting gameplay loop
    while (numCandles)
    {
        // Display candle shapes
        for (int i = 0; i < numCandles; i++)
        {
            printf("%s ", candleShapes[i]);
        }

        // Choose an action
        int action = rand() % 3;

        // Candle burning
        if (action == 0)
        {
            numCandles--;
            free(candleShapes[numCandles]);
            candleShapes[numCandles] = NULL;
        }
        // Candle splitting
        else if (action == 1)
        {
            int newCandles = numCandles * 2;
            candleShapes = (char **)realloc(candleShapes, newCandles * sizeof(char *));
            for (int i = numCandles; i < newCandles; i++)
            {
                candleShapes[i] = (char *)malloc(20 * sizeof(char));
            }
            numCandles *= 2;
        }
        // Candle merging
        else if (action == 2)
        {
            numCandles--;
            free(candleShapes[numCandles]);
            candleShapes[numCandles] = NULL;
            numCandles--;
            free(candleShapes[numCandles]);
            candleShapes[numCandles] = NULL;
            numCandles--;
        }

        // Display the result of the action
        printf("Action: %d, Number of candles: %d\n", action, numCandles);
    }

    // Free memory
    for (int i = 0; i < numCandles; i++)
    {
        free(candleShapes[i]);
    }
    free(candleShapes);

    return 0;
}