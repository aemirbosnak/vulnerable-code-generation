//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_METADATA_SIZE 10000
#define MAX_DATA_SIZE 10000

int main(int argc, char **argv)
{
    char *metadata_file_name = argv[1];
    char *data_file_name = argv[2];

    char metadata[MAX_METADATA_SIZE];
    char data[MAX_DATA_SIZE];

    FILE *metadata_file = fopen(metadata_file_name, "r");
    FILE *data_file = fopen(data_file_name, "r");

    if(metadata_file == NULL)
    {
        printf("Error opening metadata file: %s", strerror(errno));
        return -1;
    }

    if(data_file == NULL)
    {
        printf("Error opening data file: %s", strerror(errno));
        return -1;
    }

    // Extract metadata
    fread(metadata, sizeof(metadata), 1, metadata_file);

    // Extract data
    fread(data, sizeof(data), 1, data_file);

    // Parse metadata
    char *metadata_ptr = strtok(metadata, ",");
    while(metadata_ptr != NULL)
    {
        // Check data type
        if(strcmp(metadata_ptr, "int") == 0)
        {
            // Extract next integer value from data
            char *data_ptr = strtok(data, ",");
            int value = atoi(data_ptr);

            // Do something with integer value
            printf("Integer value: %d\n", value);
        }
        else if(strcmp(metadata_ptr, "float") == 0)
        {
            // Extract next float value from data
            char *data_ptr = strtok(data, ",");
            float value = atof(data_ptr);

            // Do something with float value
            printf("Float value: %f\n", value);
        }
        else if(strcmp(metadata_ptr, "string") == 0)
        {
            // Extract next string value from data
            char *data_ptr = strtok(data, ",");
            char value[MAX_DATA_SIZE];
            strcpy(value, data_ptr);

            // Do something with string value
            printf("String value: %s\n", value);
        }

        // Move to next metadata element
        metadata_ptr = strtok(NULL, ",");
    }

    // Close files
    fclose(metadata_file);
    fclose(data_file);

    return 0;
}