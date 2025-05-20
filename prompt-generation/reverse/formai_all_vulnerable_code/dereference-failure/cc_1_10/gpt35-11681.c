//FormAI DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[1000];
    char dictionary[10000];
    char* word;
    char* d_word;
    int counter = 1;
    int valid = 0;

    printf("Enter your input: ");
    fgets(input, 1000, stdin);

    FILE* dict = fopen("dictionary.txt", "r");
    if (dict == NULL)
    {
        printf("Error opening dictionary file\n");
        exit(1);
    }

    while (fgets(dictionary, 10000, dict))
    {
        d_word = strtok(dictionary, "\n");
        if (d_word == NULL)
        {
            printf("Error reading dictionary\n");
            exit(1);
        }

        word = strtok(input, " \n");
        while (word != NULL)
        {
            if (strcmp(d_word, word) == 0)
            {
                valid++;
            }

            word = strtok(NULL, " \n");
        }
        counter++;
    }

    fclose(dict);

    if (valid == counter)
    {
        printf("Your input contains only valid words.\n");
    }
    else
    {
        printf("Your input contains errors.\n");
    }

    return 0;
}