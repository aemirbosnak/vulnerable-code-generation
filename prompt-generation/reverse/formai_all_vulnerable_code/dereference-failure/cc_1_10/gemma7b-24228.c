//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_c(char *source)
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i, j, k, indent = 0, line_number = 0;

    for (i = 0; source[i] != '\0'; i++)
    {
        switch (source[i])
        {
            case '{' :
            case '}' :
            case '(':
            case ')':
            case ';':
                buffer[k++] = source[i];
                buffer[k++] = '\n';
                indent++;
                break;
            case ' ':
                if (source[i - 1] != ' ' && source[i - 1] != '\n')
                {
                    buffer[k++] = ' ';
                }
                break;
            default:
                buffer[k++] = source[i];
                break;
        }

        line_number++;
    }

    free(buffer);

    printf("%s", buffer);
}

int main()
{
    char source[] = "int main() {\n  printf(\"Hello, world!\");\n}\n";

    beautify_c(source);

    return 0;
}