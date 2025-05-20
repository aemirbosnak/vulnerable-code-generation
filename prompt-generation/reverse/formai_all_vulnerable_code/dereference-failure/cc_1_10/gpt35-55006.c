//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
/* CLAUDE SHANNON STYLE C METADATA EXTRACTOR */
/* BY: YOUR NAME */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the metadata
#define MAX_METADATA_SIZE 1000

// Define the maximum size of each field
#define MAX_FIELD_SIZE 50

// Define the maximum number of fields allowed in the metadata
#define MAX_NUM_FIELDS 20

// Function to extract the metadata fields from a given string
void extract_metadata_fields(char *metadata_string, char **metadata_fields, int *num_metadata_fields)
{
    // Initialize variables
    int i = 0;
    int j = 0;
    int k = 0;
    int num_fields = 0;
    char temp_field[MAX_FIELD_SIZE];

    // Go through each character in the string
    for (i = 0; i < strlen(metadata_string); i++) {

        // If the current character is a comma, extract the previous field
        if (metadata_string[i] == ',') {

            // Copy the field into the temporary field string
            temp_field[k] = '\0';
            metadata_fields[num_fields] = strdup(temp_field);
            
            // Clear the temporary field string
            memset(temp_field, 0, sizeof(temp_field));
            
            // Reset the character count for the temporary field string
            k = 0;
            
            // Increment the field count
            num_fields++;

            // If the maximum number of fields has been reached, exit the loop
            if (num_fields >= MAX_NUM_FIELDS) {
                break;
            }
        }
        // Otherwise, add the current character to the temporary field string
        else {
            temp_field[k] = metadata_string[i];
            k++;
        }
    }

    // If the loop completed without reaching the maximum number of fields, extract the final field
    if (num_fields < MAX_NUM_FIELDS) {
        temp_field[k] = '\0';
        metadata_fields[num_fields] = strdup(temp_field);
        num_fields++;
    }

    // Set the number of metadata fields
    *num_metadata_fields = num_fields;
}

int main(void)
{
    // Initialize variables
    char metadata[MAX_METADATA_SIZE] = "Title,Artist,Album,Year"; // Sample metadata string
    char *metadata_fields[MAX_NUM_FIELDS];
    int num_metadata_fields = 0;
    int i = 0;

    // Extract the metadata fields from the metadata string
    extract_metadata_fields(metadata, metadata_fields, &num_metadata_fields);

    // Print out the metadata fields
    for (i = 0; i < num_metadata_fields; i++) {
        printf("Metadata Field %d: %s\n", i+1, metadata_fields[i]);
    }

    return 0;
}