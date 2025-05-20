//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

// Function to check if a string contains only alpha characters
int is_alpha(char *str)
{
    while (*str)
    {
        if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
            return 0;
        str++;
    }
    return 1;
}

// Function to check if a string contains only alpha-numeric characters
int is_alphanumeric(char *str)
{
    while (*str)
    {
        if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
            return 0;
        str++;
    }
    return 1;
}

// Function to check if a string contains only valid characters for a filename
int is_filename(char *str)
{
    while (*str)
    {
        if (*str == '/' || *str == '\\' || *str == ':' || *str == '*' || *str == '?' || *str == '<' || *str == '>' || *str == '|')
            return 0;
        str++;
    }
    return 1;
}

// Function to check if a string contains only valid characters for an email address
int is_email(char *str)
{
    int at_count = 0;
    int dot_count = 0;
    while (*str)
    {
        if (*str == '@')
            at_count++;
        else if (*str == '.')
            dot_count++;
        else if (*str < '0' || *str > '9' && *str < 'a' || *str > 'z' && *str < 'A' || *str > 'Z' && *str != '_' && *str != '-')
            return 0;
        str++;
    }
    return at_count == 1 && dot_count >= 1;
}

// Function to get a sanitized string from the user
char *get_sanitized_string(char *prompt, int (*sanitize_func)(char *))
{
    char *str = NULL;
    size_t len = 0;
    ssize_t nread;
    int valid = 0;

    while (!valid)
    {
        printf("%s", prompt);
        nread = getline(&str, &len, stdin);
        if (nread == -1)
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        str[nread - 1] = '\0';
        valid = sanitize_func(str);
        if (!valid)
            printf("Invalid input. Please try again.\n");
    }

    return str;
}

int main()
{
    char *name = get_sanitized_string("Enter your name: ", is_alpha);
    char *age = get_sanitized_string("Enter your age: ", is_digits);
    char *filename = get_sanitized_string("Enter a filename: ", is_filename);
    char *email = get_sanitized_string("Enter your email address: ", is_email);

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("Filename: %s\n", filename);
    printf("Email: %s\n", email);

    free(name);
    free(age);
    free(filename);
    free(email);

    return 0;
}