//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mirror_reflection(int*);
void spectral_whisper(int*);
void ghostly_presence(int*);

int main()
{
    int* soul = (int*)malloc(sizeof(int));
    *soul = 0;

    srand(time(NULL));

    mirror_reflection(soul);
    spectral_whisper(soul);
    ghostly_presence(soul);

    free(soul);

    return 0;
}

void mirror_reflection(int* soul)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *soul = rand() % 2 == 0 ? 1 : 0;
    }
}

void spectral_whisper(int* soul)
{
    switch (*soul)
    {
        case 0:
            printf("The wind whispers secrets through the trees...\n");
            break;
        case 1:
            printf("The voices of the damned echo through the halls...\n");
            break;
    }
}

void ghostly_presence(int* soul)
{
    if (*soul)
    {
        printf("A cold wind whips through your hair... you feel an icy hand brush against your skin...\n");
    }
    else
    {
        printf("A sense of dread fills you... you hear the ticking of a clock, but there is no sound... \n");
    }
}