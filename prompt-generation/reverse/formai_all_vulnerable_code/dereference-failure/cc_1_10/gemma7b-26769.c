//Gemma-7B DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Function to reverse a string
void reverse_string(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to find the index of a substring in a string
int find_index(char *str, char *substring)
{
    int i = 0;
    int j = 0;
    int index = -1;

    while (str[i] != '\0')
    {
        while (substring[j] != '\0' && str[i] == substring[j])
        {
            i++;
            j++;
        }

        if (j == strlen(substring))
        {
            index = i - j + 1;
        }

        i++;
        j = 0;
    }

    return index;
}

// Function to replace a substring in a string with another substring
void replace_string(char *str, char *substring, char *replacement)
{
    int i = 0;
    int j = 0;
    int index = find_index(str, substring);

    if (index != -1)
    {
        int len_replacement = strlen(replacement);
        int len_substring = strlen(substring);

        memmove(str + index, replacement, len_replacement);
        memset(str + index - len_substring, 0, len_substring - 1);
    }
}

int main()
{
    char str[] = "Hello, world!";
    char substring[] = "world";
    char replacement[] = "Universe";

    replace_string(str, substring, replacement);

    printf("%s\n", str);

    return 0;
}