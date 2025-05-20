//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define INPUT_SIZE 100

//Function to remove leading and trailing spaces from input
char *trim(char *str)
{
    char *end = str + strlen(str) - 1;
 
    while(end > str && isspace((unsigned char) *end)) end--;
 
    *(end + 1) = '\0';
 
    while(*str && isspace((unsigned char) *str)) str++;
 
    return str;
}

//Function to remove non-alphanumeric characters from input
void sanitize(char *input)
{
    int i, j;

    for(i=0, j=0; input[i]!='\0'; i++)
    {
        if(isalnum(input[i]))
        {
            input[j] = input[i];
            j++;
        }
    }

    input[j] = '\0';
}

int main()
{
    char input[INPUT_SIZE];

    printf("Enter a string containing non-alphanumeric characters: ");
    fgets(input, INPUT_SIZE, stdin);

    //Remove newline character added by fgets
    input[strcspn(input, "\n")] = 0;

    //Trim input string
    char *trimmed_input = trim(input);
    printf("Trimmed input: %s\n", trimmed_input);

    //Sanitize input string
    sanitize(trimmed_input);

    printf("Sanitized input: %s\n", trimmed_input);

    return 0;
}