//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DOT "."
#define DASH "-"
#define MAX_MORSE_SIZE 50

const char *morseAlphabet[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char *convertToMorse(char *input);
int translateMorse(char *input);

int main()
{
    srand(time(NULL));
    char input[100];

    while (1)
    {
        printf("\nEnter text to translate (-1 to exit): ");
        fgets(input, 100, stdin);

        // remove newline character
        input[strcspn(input, "\n")] = 0;

        // check if user wants to exit
        if (strcmp(input, "-1") == 0)
        {
            printf("\nGoodbye!\n");
            break;
        }

        // check if input is alphabetic
        for (int i = 0; i < strlen(input); i++)
        {
            if (!isalpha(input[i]) && !isspace(input[i]))
            {
                printf("\nInvalid input. Please enter alphabetic characters only.\n");
                goto end;
            }
        }

        char *inputMorse = convertToMorse(input);
        printf("\nMorse code: %s\n", inputMorse);

        int successful = translateMorse(inputMorse);

        if (successful)
        {
            printf("\nTranslation: %s\n", input);
        }
        else
        {
            printf("\nUnable to translate. Please try again.\n");
        }

        end:
            continue;
    }

    return 0;
}

char *convertToMorse(char *input)
{
    int inputLength = strlen(input);
    char *result = calloc(inputLength * MAX_MORSE_SIZE, sizeof(char));

    for (int i = 0; i < inputLength; i++)
    {
        // skip spaces
        if (isspace(input[i]))
        {
            strcat(result, " ");
            continue;
        }

        int asciiVal = (int) toupper(input[i]) - 65;
        strcat(result, morseAlphabet[asciiVal]);
        strcat(result, " ");
    }

    // remove trailing space
    result[strcspn(result, " ")] = '\0';

    return result;
}

int translateMorse(char *input)
{
    char *token, *savePtr;
    char *temp = strdup(input);
    int successful = 1;

    token = strtok_r(temp, " ", &savePtr);

    while (token != NULL)
    {
        // delay between letters
        usleep(500000);

        for (int i = 0; i < strlen(token); i++)
        {
            if (token[i] == '.')
            {
                printf("%s", DOT);
                fflush(stdout);
                usleep(500000);
            }
            else if (token[i] == '-')
            {
                printf("%s", DASH);
                fflush(stdout);
                usleep(1000000);
            }
            else
            {
                printf(" ");
                fflush(stdout);
                usleep(1000000);
            }
        }

        token = strtok_r(NULL, " ", &savePtr);
    }

    printf("\n");

    // random chance (25%) that translation will fail
    int randomNumber = rand() % 4;

    if (randomNumber == 0)
    {
        successful = 0;
    }

    free(temp);

    return successful;
}