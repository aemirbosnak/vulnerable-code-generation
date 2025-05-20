//Falcon-180B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv)
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int error_count = 0;
    char error_message[MAX_LINE_LENGTH];

    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        snprintf(error_message, MAX_LINE_LENGTH, "Error opening file \"%s\": %s", argv[1], strerror(errno));
        fprintf(stderr, "%s\n", error_message);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL)
    {
        line_number++;

        if (strlen(line) > MAX_LINE_LENGTH - 1)
        {
            snprintf(error_message, MAX_LINE_LENGTH, "Line %d is too long (max %d characters)", line_number, MAX_LINE_LENGTH - 1);
            fprintf(stderr, "%s\n", error_message);
            error_count++;
        }
    }

    if (ferror(file))
    {
        snprintf(error_message, MAX_LINE_LENGTH, "Error reading file \"%s\": %s", argv[1], strerror(errno));
        fprintf(stderr, "%s\n", error_message);
        error_count++;
    }

    fclose(file);

    if (error_count > 0)
    {
        return 1;
    }

    return 0;
}