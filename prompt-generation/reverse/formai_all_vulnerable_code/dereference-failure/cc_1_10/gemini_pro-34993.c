//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

static void indent(int level)
{
    for (int i = 0; i < level; i++)
        printf("    ");
}

static void print_tag(const char *tag, int level)
{
    indent(level);
    printf("<%s>", tag);
}

static void print_tag_with_attr(const char *tag, const char *attr, int level)
{
    indent(level);
    printf("<%s %s>", tag, attr);
}

static void print_closing_tag(const char *tag, int level)
{
    indent(level);
    printf("</%s>", tag);
}

static void print_text(const char *text, int level)
{
    indent(level);
    printf("%s", text);
}

static void beautify_html(const char *html)
{
    int level = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        // Trim leading and trailing whitespace.
        char *trimmed = strdup(line); // Hate this but too lazy for an alternative
        size_t trimmed_len = strlen(trimmed);
        while (trimmed_len > 0 && isspace(trimmed[trimmed_len - 1]))
            trimmed[--trimmed_len] = '\0';
        while (*trimmed && isspace(*trimmed))
            trimmed++;

        // Ignore empty lines.
        if (*trimmed == '\0')
            continue;

        // Handle comments.
        if (strncmp(trimmed, "<!--", 4) == 0)
        {
            print_text(trimmed, level);
            continue;
        }

        // Handle opening tags.
        if (trimmed[0] == '<')
        {
            char *tag = trimmed + 1;
            char *attr = strchr(tag, ' ');
            if (attr)
                *attr++ = '\0';

            print_tag_with_attr(tag, attr, level);
            level++;
            continue;
        }

        // Handle closing tags.
        if (trimmed[0] == '/')
        {
            char *tag = trimmed + 1;
            print_closing_tag(tag, level);
            level--;
            continue;
        }

        // Handle text.
        print_text(trimmed, level);
    }

    free(line);
}

int main()
{
    beautify_html(NULL);
    return 0;
}