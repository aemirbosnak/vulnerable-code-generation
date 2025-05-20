//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>

int sanitize(char **str)
{
    char temp[256];
    int i = 0, j = 0;

    printf("Enter a string: ");
    getline(str, temp, 256);

    for (i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] >= 'a' && temp[i] <= 'z')
        {
            temp[j] = temp[i] - 32;
            j++;
        }
        else if (temp[i] >= 'A' && temp[i] <= 'Z')
        {
            temp[j] = temp[i] + 32;
            j++;
        }
        else if (temp[i] >= '0' && temp[i] <= '9')
        {
            temp[j] = temp[i];
            j++;
        }
        else if (temp[i] == ' ')
        {
            temp[j] = ' ';
            j++;
        }
        else
        {
            printf("Invalid character.\n");
            return -1;
        }
    }

    temp[j] = '\0';
    *str = strdup(temp);

    return 0;
}

int main()
{
    char *str = NULL;

    sanitize(&str);

    printf("Sanitized string: %s\n", str);

    return 0;
}