//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the C HTML Beautifier!\n");
    printf("Please provide me with a C HTML code snippet:\n");

    char code[1024];
    fgets(code, 1024, stdin);

    // Replace all comments with asterisks
    char* ptr = code;
    while (ptr = strstr(ptr, "//"))
    {
        ptr = strstr(ptr, "\n");
        memset(ptr, '*', ptr - code);
    }

    // Indent all blocks
    ptr = code;
    while (ptr = strstr(ptr, "{"))
    {
        int lines = 0;
        for (char* line = ptr; line && line < ptr + 1024 && line[0] != '}' && line[0] != '\0'; line++)
        {
            lines++;
        }
        ptr = strstr(ptr, "{") + 1;
        for (int i = 0; i < lines; i++)
        {
            fprintf(stdout, "    ");
        }
        fprintf(stdout, "%s\n", ptr);
    }

    // Add line numbers
    int line_num = 1;
    ptr = code;
    while (ptr)
    {
        fprintf(stdout, "%d. ", line_num++);
        fprintf(stdout, "%s\n", ptr);
        ptr = strstr(ptr, "\n");
    }

    printf("Here is your beautified C HTML code:\n\n");
    printf("%s", code);

    return 0;
}