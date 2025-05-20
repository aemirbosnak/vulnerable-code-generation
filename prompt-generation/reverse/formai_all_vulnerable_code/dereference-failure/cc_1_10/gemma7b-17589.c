//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <string.h>

void beautify_html(char **html)
{
    int i = 0;
    char *p = *html;
    char *q = NULL;
    int indent = 0;

    while (p && *p)
    {
        switch (*p)
        {
            case '<':
                q = strchr(p, '>');
                if (q)
                {
                    int tag_len = q - p;
                    char *tag = malloc(tag_len + 1);
                    memcpy(tag, p, tag_len);
                    tag[tag_len] = '\0';

                    if (indent)
                    {
                        printf("%*s", indent, "");
                    }

                    printf("<%s>\n", tag);

                    indent++;
                }
                else
                {
                    printf("%c", *p);
                }
                break;
            case ' ':
                if (q && strchr(p, '/') == NULL)
                {
                    printf(" ");
                }
                break;
            default:
                printf("%c", *p);
                break;
        }

        p++;
    }

    free(*html);
}

int main()
{
    char *html = "<p>This is <b>bold</b> text.</p>\n";

    beautify_html(&html);

    printf("%s", html);

    return 0;
}