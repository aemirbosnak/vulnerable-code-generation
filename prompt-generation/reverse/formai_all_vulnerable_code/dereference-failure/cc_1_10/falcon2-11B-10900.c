//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

void read_csv_file(const char *filename, const char *separator, FILE *output_file);

int main(int argc, char **argv)
{
    // Check if input file and output file are specified
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Parse command-line arguments
    static struct option long_options[] =
    {
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"separator", required_argument, 0,'s'},
        {0, 0, 0, 0}
    };

    char *input_file = NULL;
    char *output_file = NULL;
    char *separator = NULL;
    int c;

    while (1)
    {
        c = getopt_long(argc, argv, "i:o:s:", long_options, NULL);
        if (c == -1)
            break;

        switch (c)
        {
            case 'i':
                input_file = optarg;
                break;

            case 'o':
                output_file = optarg;
                break;

            case's':
                separator = optarg;
                break;

            default:
                abort();
        }
    }

    // Call function to read CSV file
    read_csv_file(input_file, separator, stdout);

    // Call function to write data to output file
    FILE *output_file_ptr = fopen(output_file, "w");
    if (output_file_ptr == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        exit(1);
    }

    read_csv_file(input_file, separator, output_file_ptr);

    fclose(output_file_ptr);

    return 0;
}

void read_csv_file(const char *filename, const char *separator, FILE *output_file)
{
    char line[1024];
    char *field;
    int field_count = 0;

    while (fgets(line, sizeof(line), stdin)!= NULL)
    {
        if (feof(stdin))
            break;

        field = strtok(line, separator);
        while (field!= NULL)
        {
            fprintf(output_file, "%s", field);

            field = strtok(NULL, separator);
            field_count++;
        }

        fprintf(output_file, "\n");
    }

    if (field_count!= 0)
    {
        fprintf(stderr, "Error: Not all fields were read from the input file.\n");
        exit(1);
    }
}