//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *ptr = buffer;
    int i = 0;
    char c;

    // Read the input text from the user
    printf("Enter text: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Iterate over the input text and extract metadata
    while ((c = fgetc(stdin)) != EOF)
    {
        if (c == '#')
        {
            // Extract the metadata key-value pair
            ptr = strchr(buffer, '#') + 1;
            char key[MAX_BUFFER_SIZE] = "";
            char value[MAX_BUFFER_SIZE] = "";

            // Get the metadata key and value
            i = 0;
            while (*ptr && !isspace(*ptr))
            {
                key[i] = *ptr;
                ptr++;
                i++;
            }

            i = 0;
            while (*ptr && isspace(*ptr))
            {
                ptr++;
            }

            // Get the metadata value
            while (*ptr)
            {
                value[i] = *ptr;
                ptr++;
                i++;
            }

            // Print the extracted metadata
            printf("Key: %s, Value: %s\n", key, value);
        }
    }

    return 0;
}