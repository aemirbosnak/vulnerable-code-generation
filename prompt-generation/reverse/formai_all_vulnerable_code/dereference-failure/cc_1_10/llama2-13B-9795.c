//LLAMA2-13B DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define GRATITUDE_MESSAGE "Thank you for being an amazing human! Your kindness is appreciated more than you know."

void printGratitudeMessage(void);
void generateRandomGratitudeMessage(char* message);

int main(void)
{
    srand(time(NULL));

    generateRandomGratitudeMessage(GRATITUDE_MESSAGE);

    printGratitudeMessage();

    return 0;
}

void printGratitudeMessage(void)
{
    printf("%s\n", GRATITUDE_MESSAGE);
}

void generateRandomGratitudeMessage(char* message)
{
    int i, j;
    char randomChar;

    for (i = 0; i < MAX_LENGTH; i++)
    {
        randomChar = 'a' + (rand() % 26);
        message[i] = randomChar;
    }

    for (j = 0; j < MAX_LENGTH; j++)
    {
        if (message[j] == 'a')
        {
            message[j] = 'A';
        }
        else if (message[j] == 'A')
        {
            message[j] = 'a';
        }
    }
}