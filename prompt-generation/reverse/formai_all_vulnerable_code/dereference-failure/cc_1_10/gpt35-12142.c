//FormAI DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char* argv[])
{
    FILE* log_file;
    char* log_file_path;
    char* search_string;
    char line[MAX_LINE_LENGTH];

    if (argc < 3)
    {
        printf("USAGE: %s <log_file_path> <search_string>\n", argv[0]);
        return 1;
    }

    log_file_path = argv[1];
    search_string = argv[2];

    log_file = fopen(log_file_path, "r");

    if (log_file == NULL)
    {
        perror("Failed to open log file");
        return 1;
    }

    printf("Searching log file %s for string '%s'\n", log_file_path, search_string);

    int line_number = 0;
    int string_found = 0;

    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL)
    {
        line_number++;

        if (strstr(line, search_string) != NULL)
        {
            printf("String found on line %d: %s", line_number, line);
            string_found = 1;
        }
    }

    if (!string_found)
    {
        printf("String not found in log file\n");
    }

    fclose(log_file);

    return 0;
}