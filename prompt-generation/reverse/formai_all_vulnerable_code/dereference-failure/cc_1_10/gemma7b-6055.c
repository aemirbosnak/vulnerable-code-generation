//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY 10

int main()
{
    time_t t;
    srand(time(NULL));

    int num_conspiracies = rand() % MAX_CONSPIRACY + 1;

    for (int i = 0; i < num_conspiracies; i++)
    {
        char** participants = malloc(10 * sizeof(char*));

        for (int j = 0; j < 10; j++)
        {
            participants[j] = malloc(20 * sizeof(char));
            sprintf(participants[j], "Person %d", rand() % 101);
        }

        char** motives = malloc(10 * sizeof(char*));

        for (int j = 0; j < 10; j++)
        {
            motives[j] = malloc(20 * sizeof(char));
            sprintf(motives[j], "Reason %d", rand() % 10);
        }

        char** methods = malloc(10 * sizeof(char*));

        for (int j = 0; j < 10; j++)
        {
            methods[j] = malloc(20 * sizeof(char));
            sprintf(methods[j], "Technique %d", rand() % 5);
        }

        printf("Conspiracy %d:\n", i + 1);
        printf("Participants:\n");
        for (int j = 0; j < 10; j++)
        {
            printf("%s\n", participants[j]);
        }
        printf("Motives:\n");
        for (int j = 0; j < 10; j++)
        {
            printf("%s\n", motives[j]);
        }
        printf("Methods:\n");
        for (int j = 0; j < 10; j++)
        {
            printf("%s\n", methods[j]);
        }
        printf("\n");
    }

    return 0;
}