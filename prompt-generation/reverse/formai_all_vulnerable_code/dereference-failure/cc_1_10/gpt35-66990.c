//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <string.h>

// define maximum length of file name
#define MAX_FILENAME_LENGTH 100

// define maximum length of metadata value
#define MAX_METADATA_LENGTH 1000

// define function to get metadata value from file
int get_metadata(char *filename, char *metadata_key, char *metadata_value) {
    // declare file pointer
    FILE *fp;

    // declare buffer to read data from file
    char buffer[MAX_METADATA_LENGTH];

    // open file in read mode
    fp = fopen(filename, "r");

    // check if file exists
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 0;
    }

    // read file line by line
    while (fgets(buffer, MAX_METADATA_LENGTH, fp)) {
        // check if line contains metadata key
        if (strstr(buffer, metadata_key) != NULL) {
            // copy metadata value to output parameter
            strcpy(metadata_value, buffer + strlen(metadata_key) + 1);
            // remove newline character from metadata value
            metadata_value[strlen(metadata_value) - 1] = '\0';
            // close file
            fclose(fp);
            // return success status
            return 1;
        }
    }

    // close file
    fclose(fp);

    // return failure status
    return 0;
}

// main function
int main() {
    // declare file name
    char filename[MAX_FILENAME_LENGTH];

    // declare metadata key and value
    char metadata_key[MAX_METADATA_LENGTH];
    char metadata_value[MAX_METADATA_LENGTH];

    // prompt user to enter file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // prompt user to enter metadata key
    printf("Enter metadata key: ");
    scanf("%s", metadata_key);

    // call function to get metadata value
    if (get_metadata(filename, metadata_key, metadata_value)) {
        // print metadata value
        printf("Metadata value: %s\n", metadata_value);
    } else {
        // print error message
        printf("Error: Metadata key not found!\n");
    }

    // return successful termination status
    return 0;
}