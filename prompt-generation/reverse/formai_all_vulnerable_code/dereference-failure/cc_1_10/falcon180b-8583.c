//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int num_words;

void generate_conspiracy_theory(void)
{
    char theory[MAX_WORD_LENGTH * 50];
    int i, j, k, l;

    srand(time(NULL));
    num_words = rand() % MAX_WORDS + 1;

    for (i = 0; i < num_words; i++)
    {
        words[i] = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
        for (j = 0; j < MAX_WORD_LENGTH; j++)
        {
            words[i][j] = rand() % 26 + 'a';
        }
        words[i][MAX_WORD_LENGTH - 1] = '\0';
    }

    theory[0] = '\0';

    for (i = 0; i < num_words; i++)
    {
        j = rand() % strlen(theory);
        k = rand() % strlen(words[i]);
        l = rand() % strlen(theory) - j - k;

        strncat(theory, words[i] + k, l);
        strncat(theory, " ", 1);
        strncat(theory, &words[i][k + l], strlen(&words[i][k + l]) - l);
        strncat(theory, " ", 1);
    }

    printf("Conspiracy Theory: %s\n", theory);
}

int main(void)
{
    int choice;

    do
    {
        generate_conspiracy_theory();
        printf("Do you want to generate another conspiracy theory? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}