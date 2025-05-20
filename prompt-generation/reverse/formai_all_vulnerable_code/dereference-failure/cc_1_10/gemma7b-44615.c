//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void beautify_html(char **html)
{
    int i, j, k, indent = 0;
    char **lines = NULL;

    lines = malloc(MAX * sizeof(char *));

    for (i = 0; i < MAX; i++)
    {
        lines[i] = malloc(MAX * sizeof(char));
    }

    k = 0;
    for (i = 0; html[i] != NULL; i++)
    {
        for (j = 0; html[i][j] != '\0'; j++)
        {
            lines[k][j] = html[i][j];
        }

        lines[k][j] = '\0';
        k++;
    }

    for (i = 0; lines[i] != NULL; i++)
    {
        printf("%s\n", lines[i]);
    }

    for (i = 0; i < MAX; i++)
    {
        free(lines[i]);
    }

    free(lines);
}

int main()
{
    char **html = NULL;

    html = malloc(MAX * sizeof(char *));

    for (int i = 0; i < MAX; i++)
    {
        html[i] = malloc(MAX * sizeof(char));
    }

    html[0] = "<p>This is a sample HTML paragraph.</p>";
    html[1] = "<h3>Heading 3</h3>";
    html[2] = "<div>This is a div element.</div>";

    beautify_html(html);

    for (int i = 0; html[i] != NULL; i++)
    {
        free(html[i]);
    }

    free(html);

    return 0;
}