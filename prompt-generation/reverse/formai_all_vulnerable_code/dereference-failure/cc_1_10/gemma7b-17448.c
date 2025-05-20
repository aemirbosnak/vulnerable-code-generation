//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 2048

void beautify_html(char *source)
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0, j = 0, k = 0, tag_start = -1, tag_end = -1;

    while (source[i] != '\0')
    {
        switch (source[i])
        {
            case '<':
                tag_start = i;
                break;
            case ' ':
                if (tag_start != -1)
                {
                    tag_end = i;
                    buffer[j++] = '\n';
                    buffer[j++] = ' ';
                }
                break;
            default:
                buffer[j++] = source[i];
                break;
        }
        i++;
    }

    if (tag_start != -1)
    {
        buffer[j++] = '\n';
    }

    free(buffer);

    printf("%s", buffer);
}

int main()
{
    char *source = "<p>This is <b>bold</b> text.</p>";
    beautify_html(source);

    return 0;
}