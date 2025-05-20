//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    FILE* file = fopen("sample.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read file contents into the buffer
    size_t read_size = fread(buffer, 1, MAX_BUFFER_SIZE, file);
    if (read_size == 0)
    {
        perror("Error reading file");
        exit(1);
    }

    // Close the file
    fclose(file);

    // Search for metadata tags in the buffer
    char* metadata_start = strstr(buffer, "Metadata:");
    if (metadata_start != NULL)
    {
        // Extract metadata key-value pairs
        char* key_value_pairs = strstr(metadata_start, ":");
        if (key_value_pairs != NULL)
        {
            // Iterate over key-value pairs
            while (key_value_pairs)
            {
                // Extract key and value
                char* key = strchr(key_value_pairs, ":") + 1;
                char* value = strchr(key, ";") - key;

                // Print key-value pair
                printf("%s: %s\n", key, value);
            }
        }
    }

    return 0;
}