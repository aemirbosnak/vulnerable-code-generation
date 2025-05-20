//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 256

typedef struct PassGen
{
    char *pass;
    int length;
} PassGen;

PassGen *createPassGen(int length)
{
    PassGen *pg = malloc(sizeof(PassGen));
    pg->pass = malloc(length);
    pg->length = length;

    return pg;
}

void generatePass(PassGen *pg)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < pg->length; i++)
    {
        pg->pass[i] = (rand() % 2) ? 'a' + rand() % 26 : '0' + rand() % 10;
    }

    pg->pass[pg->length - 1] = '\0';
}

void printPass(PassGen *pg)
{
    printf("%s\n", pg->pass);
}

int main()
{
    PassGen *pg = createPassGen(20);
    generatePass(pg);
    printPass(pg);

    free(pg->pass);
    free(pg);

    return 0;
}