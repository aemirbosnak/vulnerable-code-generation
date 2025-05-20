//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LENGTH 100

// Function to remove unwanted characters from user input
char* sanitize_input(char* input)
{
    int i, j;
    int length = strlen(input);
    char* sanitized_input = (char*)malloc(sizeof(char)*length);

    for(i=0, j=0; i<length; i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            sanitized_input[j++] = input[i];
        }
        else if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            sanitized_input[j++] = input[i];
        }
        else if(input[i] == ' ')
        {
            sanitized_input[j++] = '_';
        }
    }
    sanitized_input[j] = '\0';

    return sanitized_input;
}

int main()
{
    char input[MAX_INPUT_LENGTH];
    char* sanitized_input;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    sanitized_input = sanitize_input(input);

    printf("Sanitized string is: %s\n", sanitized_input);

    free(sanitized_input);

    return 0;
}