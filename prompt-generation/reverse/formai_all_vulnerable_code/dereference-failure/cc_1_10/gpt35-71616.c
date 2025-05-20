//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove unwanted spaces
char *removeSpaces(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}

// Function to beautify HTML code
char *beautifyHtml(char *html)
{
    char *cleanStr = (char *)malloc(sizeof(char) * strlen(html));
    int i = 0, j = 0, spaces = 0;
    while (html[i])
    {
        if (html[i] != '<' && html[i] != '>')
        {
            if (html[i] == '/')
            {
                spaces--;
                if (html[i - 1] == '>')
                    sprintf(&cleanStr[j++], "\n%*c", spaces, ' ');
                else
                    sprintf(&cleanStr[j++], " %c", html[i]);
            }
            else
                sprintf(&cleanStr[j++], "%c", html[i]);
        }
        else if (html[i] == '<')
        {
            sprintf(&cleanStr[j++], "\n%*c%c", spaces, ' ', html[i]);
            spaces += 4;
        }
        else if (html[i] == '>')
        {
            spaces -= 4;
            if (html[i - 1] != '/')
                sprintf(&cleanStr[j++], "\n%*c", spaces, ' ');
            sprintf(&cleanStr[j++], "%c", html[i]);
        }
        i++;
    }
    cleanStr[j] = '\0';
    return cleanStr;
}

// Main function to test the program
int main()
{
    char *html = "<html><head><title>HTML Beautifier</title></head><body><h1> Hello, World! </h1></body></html>";

    printf("Original HTML:\n%s\n", html);

    // Remove unwanted spaces
    char *cleanHtml = removeSpaces(html);

    printf("\nCleaned HTML:\n%s\n", cleanHtml);

    // Beautify the HTML code
    char *beautyHtml = beautifyHtml(cleanHtml);

    printf("\nBeautified HTML:\n%s", beautyHtml);

    free(cleanHtml);
    free(beautyHtml);

    return 0;
}