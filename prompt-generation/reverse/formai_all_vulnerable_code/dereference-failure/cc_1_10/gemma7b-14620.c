//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void beautify_c(char *source)
{
    char *p = source;
    char *q = source;
    int indent = 0;
    int state = 0;

    while (*p)
    {
        switch (state)
        {
            case 0:
                if (isspace(*p) || *p == '\n')
                {
                    *q++ = '\n';
                    indent++;
                    state = 1;
                }
                else
                {
                    *q++ = *p;
                }
                break;
            case 1:
                if (isspace(*p) || *p == '\n')
                {
                    *q++ = '\n';
                    indent++;
                    state = 2;
                }
                else
                {
                    *q++ = ' ';
                    *q++ = *p;
                }
                break;
            case 2:
                if (isspace(*p) || *p == '\n')
                {
                    *q++ = '\n';
                    indent--;
                    state = 0;
                }
                else
                {
                    *q++ = ' ';
                    *q++ = *p;
                }
                break;
        }
        p++;
    }

    *q = '\0';
}

int main()
{
    char source[] = "int main() {\n  printf(\"Hello, world!\");\n}\n";
    beautify_c(source);
    printf("%s", source);

    return 0;
}