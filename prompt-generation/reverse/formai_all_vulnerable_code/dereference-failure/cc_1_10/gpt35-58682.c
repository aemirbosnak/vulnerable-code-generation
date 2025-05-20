//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// This is the main function that will run the metadata extractor program
int main()
{
    int size;
    char *metadata;
    char *filename;

    printf("Please enter the name of the file to extract metadata from: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Cannot open file\n");
        return 0;
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    metadata = (char *)malloc(sizeof(char) * size);

    if(metadata == NULL)
    {
        printf("Error allocating memory\n");
        return 0;
    }

    fread(metadata, sizeof(char), size, fp);
    fclose(fp);

    // Metadata extraction code goes here
    int i;
    int metadata_found = 0;
    for(i = 0; i < size; i++)
    {
        if(metadata[i] == '@')
        {
            char *metadata_start = &metadata[i];
            char *metadata_end = strchr(metadata_start+1, '@');
            if(metadata_end != NULL)
            {
                int metadata_size = metadata_end - metadata_start;
                char *metadata_string = (char *)malloc(sizeof(char) * metadata_size);
                strncpy(metadata_string, metadata_start, metadata_size);
                printf("Metadata found: %s\n", metadata_string);
                free(metadata_string);
                metadata_found = 1;
                i += metadata_size;
            }
        }
    }

    if(!metadata_found)
    {
        printf("No metadata found in file\n");
    }
    
    free(metadata);
    return 0;
}