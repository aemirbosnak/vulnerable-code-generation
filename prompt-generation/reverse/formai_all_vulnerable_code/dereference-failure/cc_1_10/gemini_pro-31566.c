//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = NULL;
    size_t input_len = 0;

    printf("Enter a string to check if it's a palindrome: ");
    getline(&input, &input_len, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Calculate the length of the string
    int len = strlen(input);

    // Check if the string is empty or has only one character
    if (len == 0 || len == 1)
    {
        printf("%s is a palindrome\n", input);
        return 0;
    }

    // Compare the first and last characters of the string
    int i = 0;
    int j = len - 1;
    int is_palindrome = 1;
    while (i < j)
    {
        if (input[i] != input[j])
        {
            is_palindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (is_palindrome)
    {
        printf("%s is a palindrome\n", input);
    }
    else
    {
        printf("%s is not a palindrome\n", input);
    }

    free(input);
    return 0;
}