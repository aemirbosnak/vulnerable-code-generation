//FormAI DATASET v1.0 Category: Funny ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* randomInspirationQuote(void);

int main(void)
{
    srand(time(NULL));
    for(int i = 0; i < 5; i++)
    {
        char* quote = randomInspirationQuote();
        if(quote != NULL)
        {
            printf("%s\n", quote);
            free(quote);
        }
    }
    return 0;
}

char* randomInspirationQuote(void)
{
    char* quotes[10] = {
        "You are never too old to set another goal or to dream a new dream.",
        "Believe you can and you're halfway there.",
        "The most difficult thing is the decision to act, the rest is merely tenacity.",
        "Success is not final, failure is not fatal: It is the courage to continue that counts.",
        "If you are not willing to risk the usual you will have to settle for the ordinary.",
        "The only limit to our realization of tomorrow will be our doubts of today.",
        "The best way to predict the future is to invent it.",
        "Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.",
        "Don't watch the clock; do what it does. Keep going.",
        "You miss 100% of the shots you don't take.",
    };

    sleep(rand() % 3); // Simulate some processing time
    int index = rand() % 10; // Get a random index for the quote array

    char* quote = malloc(strlen(quotes[index]) + 1); // Allocate memory for the quote string
    if(quote != NULL)
    {
        strcpy(quote, quotes[index]); // Copy the quote to the allocated memory
        return quote;
    }
    else
    {
        printf("Error: Couldn't allocate memory for quote.\n");
        return NULL;
    }
}