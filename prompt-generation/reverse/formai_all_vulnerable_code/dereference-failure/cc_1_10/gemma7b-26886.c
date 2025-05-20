//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <string.h>

char *user_input_sanitizer(char *str)
{
    char *sanitized_str = malloc(strlen(str) + 1);
    int i = 0, j = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
        {
            sanitized_str[j] = str[i];
            j++;
        }
    }

    sanitized_str[j] = '\0';

    return sanitized_str;
}

char *remove_special_characters(char *str)
{
    char *sanitized_str = malloc(strlen(str) + 1);
    int i = 0, j = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
        {
            sanitized_str[j] = str[i];
            j++;
        }
    }

    sanitized_str[j] = '\0';

    return sanitized_str;
}

int main()
{
    char *user_input = malloc(100);
    printf("Enter a string: ");
    fgets(user_input, 100, stdin);

    char *sanitized_user_input = user_input_sanitizer(user_input);
    printf("Sanitized user input: %s\n", sanitized_user_input);

    char *sanitized_user_input_without_special_characters = remove_special_characters(user_input);
    printf("Sanitized user input without special characters: %s\n", sanitized_user_input_without_special_characters);

    free(user_input);
    free(sanitized_user_input);
    free(sanitized_user_input_without_special_characters);

    return 0;
}