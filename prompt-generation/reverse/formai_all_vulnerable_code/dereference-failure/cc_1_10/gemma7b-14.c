//Gemma-7B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    int i, j, found = 0;
    FILE *fp;

    printf("Enter a command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Split the command into words
    char **words = NULL;
    char *word = strtok(cmd, " ");
    while (word)
    {
        words = realloc(words, (i + 1) * sizeof(char *));
        words[i++] = word;
        word = strtok(NULL, " ");
    }

    // Check if the command is valid
    for (j = 0; j < i; j++)
    {
        if (strcmp(words[j], "create") == 0)
        {
            found = 1;
            break;
        }
        else if (strcmp(words[j], "delete") == 0)
        {
            found = 1;
            break;
        }
        else if (strcmp(words[j], "list") == 0)
        {
            found = 1;
            break;
        }
    }

    // If the command is not valid, display an error message
    if (!found)
    {
        printf("Error: Invalid command.\n");
    }

    // Free the memory allocated for the words array
    free(words);

    return 0;
}