//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

// Function to extract metadata from a file
int extract_metadata(char *filename)
{
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    char *line, *key, *value;
    int line_number = 0;

    // Open the file
    fp = fopen(filename, "r");

    // If the file is open, read the file line by line
    if (fp)
    {
        // While there is more data to read, read the next line
        while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL)
        {
            line_number++;

            // Remove whitespace from the line
            line = strtok(buffer, " \t\n");

            // If the line starts with a key-value pair, extract the key and value
            if (line[0] != '#')
            {
                key = strtok(line, ":");
                value = strtok(NULL, ":");

                // Print the key-value pair
                printf("%s: %s\n", key, value);
            }
        }

        // Close the file
        fclose(fp);
    }

    return 0;
}

int main()
{
    char *filename = "example.txt";

    extract_metadata(filename);

    return 0;
}