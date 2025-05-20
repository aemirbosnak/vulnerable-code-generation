//Gemma-7B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct Candle
{
    char *name;
    int wick_length;
    struct Candle *next;
} Candle;

int main()
{
    Candle *head = NULL;
    Candle *tail = NULL;

    // Allocate memory for the first candle
    head = (Candle *)malloc(sizeof(Candle));
    head->name = "Rose Candle";
    head->wick_length = 5;
    head->next = NULL;

    tail = head;

    // Allocate memory for the second candle
    tail->next = (Candle *)malloc(sizeof(Candle));
    tail->next->name = "Lavender Candle";
    tail->next->wick_length = 3;
    tail->next->next = NULL;

    tail = tail->next;

    // Allocate memory for the third candle
    tail->next = (Candle *)malloc(sizeof(Candle));
    tail->next->name = "Vanilla Candle";
    tail->next->wick_length = 2;
    tail->next->next = NULL;

    tail = tail->next;

    // Display the candles
    for (Candle *current = head; current; current = current->next)
    {
        printf("%s has a wick length of %d.\n", current->name, current->wick_length);
    }

    // Free the memory of the candles
    for (Candle *current = head; current; current = current->next)
    {
        free(current);
    }

    return 0;
}