//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ada Lovelace
/* =========================================
 * User Input Sanitizer Program
 * Written by [Your Name]
 * Inspired by Ada Lovelace
 * ========================================= */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

/* ------------------------ FUNCTION PROTOTYPES ------------------------ */

int is_valid_input(char *str);
void sanitize_input(char *input);
char *get_input();

/* ------------------------ MAIN PROGRAM ------------------------ */

int main()
{
    char *input;

    printf("Please enter your input: ");

    input = get_input();

    if (is_valid_input(input))
    {
        printf("Your input is valid and has been sanitized.\n\n");
        sanitize_input(input);
        printf("Sanitized Input: %s\n", input);
    }
    else
    {
        printf("Your input is not valid. Please try again.\n");
    }

    free(input);

    return 0;
}

/* ------------------------ FUNCTIONS ------------------------ */

/* Function to check if input is valid */

int is_valid_input(char *str)
{
    int i;

    /* checking for any invalid characters */
    for (i = 0; i < strlen(str); i++)
    {
        if (!isalpha(str[i]) && !isspace(str[i]) && !isdigit(str[i]))
        {
            return 0;
        }
    }

    return 1;
}

/* Function to sanitize input */

void sanitize_input(char *input)
{
    int i;

    /* converting all characters to lowercase */
    for (i = 0; i < strlen(input); i++)
    {
        input[i] = tolower(input[i]);
    }

    /* removing any leading spaces */
    while (isspace(*input))
    {
        input++;
    }

    /* removing any trailing spaces */
    i = strlen(input) - 1;
    while (isspace(input[i]))
    {
        input[i] = '\0';
        i--;
    }

    /* removing any consecutive spaces */
    for (i = 0; i < strlen(input); i++)
    {
        if (isspace(input[i]) && isspace(input[i + 1]))
        {
            memmove(&input[i], &input[i + 1], strlen(input) - i);
            i--;
        }
    }
}

/* Function to get input from user */

char *get_input()
{
    char *str = malloc(MAX_INPUT_LENGTH + 1);
    int c;
    int i = 0;

    while ((c = getchar()) != '\n' && c != EOF && i < MAX_INPUT_LENGTH)
    {
        str[i++] = c;
    }

    str[i] = '\0';

    return str;
}