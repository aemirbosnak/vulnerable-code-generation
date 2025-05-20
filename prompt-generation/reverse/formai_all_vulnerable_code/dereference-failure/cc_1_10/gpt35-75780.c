//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_METADATA_VALUES 10

// function to extract metadata from the input buffer
void extract_metadata(char *input_buffer, char *metadata[MAX_METADATA_VALUES], int *num_metadata_values)
{
    int buffer_length = strlen(input_buffer);
    int metadata_count = 0;

    // loop through each character of the input buffer to find the meta data enclosed with double braces
    for (int i = 0; i < buffer_length; i++)
    {
        if (input_buffer[i] == '{' && input_buffer[i+1] == '{')
        {
            int start_index = i+2;
            int end_index = i+2;

            while (input_buffer[end_index] != '}' && input_buffer[end_index+1] != '}')
            {
                end_index++;
            }

            end_index++;

            int metadata_length = end_index - start_index;
            char *metadata_value = (char *)malloc(metadata_length + 1);

            strncpy(metadata_value, &input_buffer[start_index], metadata_length);
            metadata_value[metadata_length] = '\0';

            metadata[metadata_count] = metadata_value;
            metadata_count++;

            i = end_index;
        }
    }

    *num_metadata_values = metadata_count;
}

int main(int argc, char const *argv[])
{
    char input_buffer[MAX_BUFFER_SIZE];

    printf("Enter the input string: ");
    if (fgets(input_buffer, MAX_BUFFER_SIZE, stdin) != NULL)
    {
        // remove the newline character from the input buffer
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // declare variables to hold metadata information
        char *metadata[MAX_METADATA_VALUES];
        int num_metadata_values = 0;

        // call extract_metadata function to get metadata values from the input buffer
        extract_metadata(input_buffer, metadata, &num_metadata_values);

        // print the extracted metadata values
        printf("Metadata values extracted from input: \n");

        for (int i=0; i<num_metadata_values; i++)
        {
            printf("%s\n", metadata[i]);
        }

        // free the metadata memory block
        for (int i=0; i<num_metadata_values; i++)
        {
            free(metadata[i]);
        }
    }

    return 0;
}