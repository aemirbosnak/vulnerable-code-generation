//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char **buffer)
{
    char *p = *buffer;
    char *q = NULL;
    int depth = 0;

    while (p)
    {
        if (p[0] == '<' && p[1] == 'p')
        {
            depth++;
            q = strchr(p, '>');
            if (q)
            {
                int len = q - p + 1;
                char *new_p = malloc(len);
                memcpy(new_p, p, len);
                new_p[len - 1] = '\0';
                *buffer = realloc(*buffer, MAX_BUFFER_SIZE * (depth + 1));
                *buffer = strcat(*buffer, new_p);
                free(new_p);
            }
        }
        else if (depth)
        {
            q = strchr(p, '</');
            if (q)
            {
                depth--;
            }
        }
        p++;
    }

    return;
}

int main()
{
    char *buffer = NULL;
    buffer = malloc(MAX_BUFFER_SIZE);
    buffer = strcat(buffer, "<p><b>This is a bold text</b></p>");
    buffer = strcat(buffer, "<p><i>This is an italic text</i></p>");
    buffer = strcat(buffer, "<p><b><i>This is a bold and italic text</i></b></p>");

    beautify_html(&buffer);

    printf("%s", buffer);

    free(buffer);

    return 0;
}