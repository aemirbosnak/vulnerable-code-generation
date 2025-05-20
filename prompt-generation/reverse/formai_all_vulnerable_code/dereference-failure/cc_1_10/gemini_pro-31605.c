//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all spaces and newlines from a string
char *remove_spaces(char *str)
{
    char *new_str = (char *)malloc(strlen(str) + 1);
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to indent a string
char *indent(char *str, int level)
{
    char *new_str = (char *)malloc(strlen(str) + level + 1);
    memset(new_str, ' ', level);
    strcpy(new_str + level, str);
    return new_str;
}

// Function to beautify HTML code
char *beautify_html(char *html)
{
    // Remove all spaces and newlines from the HTML code
    char *clean_html = remove_spaces(html);

    // Create a new string to store the beautified HTML code
    char *beautified_html = (char *)malloc(strlen(clean_html) + 1);
    strcpy(beautified_html, clean_html);

    // Indent the HTML code
    int level = 0;
    int i = 0;
    while (beautified_html[i] != '\0')
    {
        if (beautified_html[i] == '<')
        {
            if (beautified_html[i + 1] == '/')
            {
                level--;
            }
            else
            {
                level++;
            }
        }
        beautified_html[i] = indent(beautified_html[i], level);
        i++;
    }

    // Return the beautified HTML code
    return beautified_html;
}

// Main function
int main()
{
    // Get the HTML code from the user
    char *html = (char *)malloc(1024 * sizeof(char));
    printf("Enter HTML code: ");
    gets(html);

    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("Beautified HTML code:\n%s", beautified_html);

    // Free the allocated memory
    free(html);
    free(beautified_html);

    return 0;
}