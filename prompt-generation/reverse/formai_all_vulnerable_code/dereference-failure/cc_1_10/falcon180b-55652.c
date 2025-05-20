//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_usage()
{
    printf("Usage:./cyberhex [input_file] [output_file]\n");
}

void cyberhex_convert(FILE* input_file, FILE* output_file)
{
    char input_buffer[1024];
    char output_buffer[1024];
    int input_length = 0;
    int output_length = 0;

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL)
    {
        input_length += strlen(input_buffer);
        output_length = input_length * 2;
        output_buffer[0] = '\0';

        for (int i = 0; i < input_length; i++)
        {
            if (isxdigit(input_buffer[i]))
            {
                sprintf(output_buffer + output_length - 2, "%02X", input_buffer[i]);
            }
            else
            {
                sprintf(output_buffer + output_length - 2, ".");
            }
            output_length -= 2;
        }

        fprintf(output_file, "%s\n", output_buffer);
    }
}

int main(int argc, char** argv)
{
    if (argc!= 3)
    {
        print_usage();
        exit(1);
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    cyberhex_convert(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}