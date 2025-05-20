//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

void remove_comments(char *html);
void beautify_html(char *html);

int main()
{
    char html[MAX_SIZE];

    printf("Enter HTML code:\n");
    fgets(html, MAX_SIZE, stdin);

    remove_comments(html);
    beautify_html(html);

    printf("\nBeautified HTML:\n%s", html);

    return 0;
}

void remove_comments(char *html)
{
    int i, j;
    int inside_comment = 0;

    for (i = 0, j = 0; html[j]; j++)
    {
        if (html[j] == '<' && html[j+1] == '!' && html[j+2] == '-' && html[j+3] == '-')
        {
            inside_comment = 1;
            j += 3;
        }

        if (!inside_comment)
            html[i++] = html[j];

        if (html[j] == '-' && html[j+1] == '-' && html[j+2] == '>')
        {
            inside_comment = 0;
            j += 2;
        }
    }

    html[i] = '\0';
}

void beautify_html(char *html)
{
    int i, j, indent_level = 0, inside_tag = 0;

    for (i = 0; html[i]; )
    {
        if (html[i] == '<')
        {
            inside_tag = 1;

            if (html[i+1] == '/')
                indent_level--;

            for (j = 0; j < indent_level; j++)
                printf("    ");

            printf("%c", html[i]);
            i++;
        }
        else if (html[i] == '>')
        {
            printf("%c\n", html[i]);

            inside_tag = 0;

            if (html[i-1] == '/')
                indent_level--;
            else if (html[i-2] == '<' && html[i-1] == '!')
                indent_level--;

            for (j = 0; j < indent_level; j++)
                printf("    ");

            if (html[i+1] == '<' && html[i+2] == '/')
                indent_level++;

            i++;
        }
        else
        {
            if (inside_tag)
                printf("%c", html[i]);

            i++;
        }
    }
}