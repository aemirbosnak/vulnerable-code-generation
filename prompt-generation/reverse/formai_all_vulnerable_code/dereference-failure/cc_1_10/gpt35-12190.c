//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *data)
{
    char *temp = malloc(strlen(data) + 1);
    char *p = data;
    char *q = temp;
    int indent = 0;
    int newline = 1;

    while (*p != '\0')
    {
        if (*p == '<')
        {
            if (*(p + 1) == '/')
            {
                indent--;
            }

            for (int i = 0; i < indent; i++)
            {
                printf("    ");
                *q++ = ' ';
            }
            *q++ = *p++;

            if (*(p + 1) != '/')
            {
                indent++;
            }

            newline = 1;
        }
        else if (*p == '>')
        {
            *q++ = *p++;
            printf("%s", temp);

            if (!strncmp(temp, "<br", 3) || !strncmp(temp, "<hr", 3) || !strncmp(temp, "<img", 4) || !strncmp(temp, "<input", 6))
            {
                newline = 1;
            }
        }
        else
        {
            if (newline)
            {
                for (int i = 0; i < indent; i++)
                {
                    printf("    ");
                    *q++ = ' ';
                }
                newline = 0;
            }
            *q++ = *p++;
        }
    }
    *q = '\0';
    free(temp);
}

int main()
{
    char data[] = "<html>\n<body>\n        <h1>Title</h1>\n        <p>Welcome to my page!</p>\n</body>\n</html>";
    printf("Input:\n%s\n", data);
    printf("Beautified Output:\n");
    beautify(data);
    printf("\n");
    return 0;
}