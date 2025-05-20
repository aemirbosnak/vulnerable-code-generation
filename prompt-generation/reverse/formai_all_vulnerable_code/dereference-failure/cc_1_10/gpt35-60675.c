//FormAI DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#define MAXHTML 1000000        // Maximum HTML size
 
// function to remove extra spaces and tabs 
void removeSpaces(char* str)
{
    int i, j;
    for (i = 0, j = 0; str[i]; i++)
        if (str[i] != ' ' && str[i] != '\t')
            str[j++] = str[i];
    str[j] = '\0';
}
 
// function to format the HTML code
void beautifyHTML(char* htmlCode)
{
    int i, j, k, indentLevel = 0;
    char formattedHTML[MAXHTML];
 
    for (i = 0, j = 0; htmlCode[i];)
    {
        if (htmlCode[i] == '<')
        {
            if (htmlCode[i + 1] == '/')  // end tag
            {
                indentLevel--;
                // remove extra spaces and tabs
                removeSpaces(&formattedHTML[j - 1]);
                for (k = 0; k < indentLevel; k++)
                    formattedHTML[j++] = '\t';
            }
            else    // start tag or single tag
            {
                if (htmlCode[i + 1] != '!' && htmlCode[i + 1] != '?')   // ignore comments and directives
                {
                    // remove extra spaces and tabs
                    removeSpaces(&formattedHTML[j - 1]);
                    for (k = 0; k < indentLevel; k++)
                        formattedHTML[j++] = '\t';
                    indentLevel++;
                }
            }
        }
        formattedHTML[j++] = htmlCode[i++];
    }
    formattedHTML[j] = '\0';    // add null character at the end
 
    printf("Formatted HTML code: \n%s\n", formattedHTML);
}
 
int main()
{
    printf("Enter the unformatted HTML code: \n");
 
    char unformattedHTML[MAXHTML];
    fgets(unformattedHTML, MAXHTML, stdin);
 
    beautifyHTML(unformattedHTML);
 
    return 0;
}