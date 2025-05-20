//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <color>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color = argv[1];

    if (strcmp(color, "red") == 0)
    {
        printf(ANSI_COLOR_RED "This is red text!" ANSI_COLOR_RESET "\n");
    }
    else if (strcmp(color, "green") == 0)
    {
        printf(ANSI_COLOR_GREEN "This is green text!" ANSI_COLOR_RESET "\n");
    }
    else if (strcmp(color, "yellow") == 0)
    {
        printf(ANSI_COLOR_YELLOW "This is yellow text!" ANSI_COLOR_RESET "\n");
    }
    else if (strcmp(color, "blue") == 0)
    {
        printf(ANSI_COLOR_BLUE "This is blue text!" ANSI_COLOR_RESET "\n");
    }
    else if (strcmp(color, "magenta") == 0)
    {
        printf(ANSI_COLOR_MAGENTA "This is magenta text!" ANSI_COLOR_RESET "\n");
    }
    else if (strcmp(color, "cyan") == 0)
    {
        printf(ANSI_COLOR_CYAN "This is cyan text!" ANSI_COLOR_RESET "\n");
    }
    else if (strcmp(color, "white") == 0)
    {
        printf(ANSI_COLOR_WHITE "This is white text!" ANSI_COLOR_RESET "\n");
    }
    else
    {
        printf("Invalid color: %s\n", color);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}