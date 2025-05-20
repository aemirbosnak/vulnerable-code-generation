//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
/**
 * @file main.c
 * @brief A program that sanitizes user input to prevent common security vulnerabilities.
 * 
 * This program prompts the user to enter a string and then sanitizes the input using a variety of techniques 
 * to prevent common security vulnerabilities such as buffer overflow, SQL injection, and cross-site scripting (XSS).
 * 
 * @author Statistical Program
 * @date 2021-08-24
 */

#include <stdio.h>
#include <string.h>

// The maximum length of the user input string
#define MAX_INPUT_LENGTH 256

// Function prototypes
void sanitizeInput(char * input);

/**
 * @brief The main function of the program.
 * 
 * @return int The exit code of the program.
 */
int main()
{
    // Declare a buffer to hold the user input
    char input[MAX_INPUT_LENGTH];

    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Read the user input
    fgets(input, sizeof(input), stdin);

    // Ensure that the input string is null-terminated
    input[strcspn(input, "\n")] = '\0';

    // Sanitize the input to prevent common security vulnerabilities
    sanitizeInput(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}

/**
 * @brief A function that sanitizes user input to prevent common security vulnerabilities.
 * 
 * This function performs the following sanitization steps:
 *  - Truncates the input string to the maximum allowed length
 *  - Removes any leading or trailing white space
 *  - Replaces any apostrophes or double quotes with their HTML entity equivalents
 *  - Escapes any HTML tags
 *  - Escapes any SQL injection characters
 * 
 * @param input The user input string to sanitize.
 */
void sanitizeInput(char * input)
{
    // Truncate the input string to the maximum allowed length
    if (strlen(input) > MAX_INPUT_LENGTH - 1) {
        input[MAX_INPUT_LENGTH - 1] = '\0';
    }

    // Remove any leading or trailing white space
    char * start = input;
    char * end = input + strlen(input) - 1;
    while (*start == ' ') start++;
    while (*end == ' ' && end >= start) end--;
    *(end + 1) = '\0';
    strcpy(input, start);

    // Replace any apostrophes or double quotes with their HTML entity equivalents
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '\'') {
            input[i] = '&apos;';
        } else if (input[i] == '\"') {
            input[i] = '&quot;';
        }
    }

    // Escape any HTML tags
    char temp[MAX_INPUT_LENGTH];
    memset(temp, 0, MAX_INPUT_LENGTH);
    char * ptemp = temp;
    for (int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
        case '<':
            strcpy(ptemp, "&lt;");
            ptemp += strlen("&lt;");
            break;
        case '>':
            strcpy(ptemp, "&gt;");
            ptemp += strlen("&gt;");
            break;
        case '&':
            strcpy(ptemp, "&amp;");
            ptemp += strlen("&amp;");
            break;
        default:
            *ptemp++ = input[i];
        }
    }
    *ptemp = '\0';
    strcpy(input, temp);

    // Escape any SQL injection characters
    for (int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
        case '\'':
            memmove(input + i + 1, input + i, strlen(input + i) + 1);
            input[i] = '\\';
            i++;
            break;
        case '\"':
            memmove(input + i + 1, input + i, strlen(input + i) + 1);
            input[i] = '\\';
            i++;
            break;
        case '\\':
            memmove(input + i + 1, input + i, strlen(input + i) + 1);
            input[i] = '\\';
            i++;
            break;
        default:
            break;
        }
    }
}