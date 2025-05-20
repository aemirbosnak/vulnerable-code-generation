//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
//This code demonstrates a C metadata extractor program that extracts metadata from a given file and displays it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Define a structure to hold metadata information
typedef struct
{
    char *key;
    char *value;
} metadata_record;

//Function prototypes
metadata_record *extract_metadata(char *filename, int *num_records);
void display_metadata(metadata_record *metadata, int num_records);

int main(int argc, char *argv[])
{
    //Check if the user provided a filename
    if(argc != 2)
    {
        printf("Error: please provide a filename as an argument.\n");
        return 1;
    }
    
    char *filename = argv[1];
    
    //Call the extract_metadata function to extract the metadata from the file
    int num_records;
    metadata_record *metadata = extract_metadata(filename, &num_records);
    
    //Display the metadata
    display_metadata(metadata, num_records);
    
    //Free allocated memory
    free(metadata);
    
    return 0;
}

//Function to extract metadata from a file
metadata_record *extract_metadata(char *filename, int *num_records)
{
    FILE *fp;
    char line[100];
    fp = fopen(filename, "r");
    
    //Check if the file is not null
    if(fp == NULL)
    {
        printf("Error: could not open file %s.\n", filename);
        return NULL;
    }
    
    //Count the number of metadata records in the file
    int count = 0;
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strstr(line, "//META:") != NULL)
            count++;
    }
    
    //Allocate memory for the metadata records
    metadata_record *records = malloc(count * sizeof(metadata_record));
    if(records == NULL)
    {
        printf("Error: memory allocation failed.\n");
        return NULL;
    }
    
    rewind(fp);
    
    //Extract the metadata from the file
    int i = 0;
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strstr(line, "//META:") != NULL)
        {
            char *key = strtok(line, ":");
            char *value = strtok(NULL, ":");
            
            //Allocate memory for the key and value strings
            records[i].key = malloc(strlen(key) * sizeof(char));
            records[i].value = malloc(strlen(value) * sizeof(char));
            
            if(records[i].key == NULL || records[i].value == NULL)
            {
                printf("Error: memory allocation failed.\n");
                return NULL;
            }
            
            //Remove any leading/trailing whitespace from the key and value strings
            strcpy(records[i].key, key);
            strcpy(records[i].value, value);
            
            for(int j = 0; j < strlen(records[i].key); j++)
            {
                if(isspace(records[i].key[j]))
                {
                    records[i].key[j] = '\0';
                    break;
                }
            }
            
            for(int j = strlen(records[i].value) - 1; j >= 0; j--)
            {
                if(isspace(records[i].value[j]))
                {
                    records[i].value[j] = '\0';
                    break;
                }
            }
            
            i++;
        }
    }
    
    *num_records = count;
    fclose(fp);
    return records;
}

//Function to display the extracted metadata
void display_metadata(metadata_record *metadata, int num_records)
{
    printf("Metadata:\n");
    for(int i = 0; i < num_records; i++)
    {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }
}