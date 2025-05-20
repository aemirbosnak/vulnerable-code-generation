//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input_file))
    {
        char *date_string = strtok(line, ",");
        if (date_string == NULL)
        {
            fprintf(stderr, "Error parsing line: %s\n", line);
            continue;
        }

        int year, month, day;
        if (sscanf(date_string, "%d-%d-%d", &year, &month, &day) != 3)
        {
            fprintf(stderr, "Error parsing date string: %s\n", date_string);
            continue;
        }

        fprintf(output_file, "%d/%d/%d\n", month, day, year);
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}