//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract metadata from a file
int extract_metadata(char *filename, char *metadata) {
    // open the file in read mode
    FILE *fp = fopen(filename, "r");
    
    // if unable to open the file, return error
    if(fp == NULL) {
        printf("Error: Unable to open file!\n");
        return -1;
    }
    
    // read the first line of the file
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);
    
    // check if the first line starts with "Metadata:"
    if(strncmp(buffer, "Metadata:", 9) != 0) {
        printf("Error: Metadata not found!\n");
        return -1;
    }
    
    // copy the metadata string and remove the newline character
    strcpy(metadata, buffer + 9);
    metadata[strlen(metadata) - 1] = '\0';
    
    // close the file
    fclose(fp);
    
    // return success
    return 0;
}

// main function
int main() {
    // declare variables
    char filename[100], metadata[100];
    int result;
    
    // prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    // extract metadata from the file
    result = extract_metadata(filename, metadata);
    
    // check if the function returned success
    if(result == 0) {
        // print the extracted metadata
        printf("Metadata: %s\n", metadata);
        
        // exit the program
        return 0;
    } else {
        // exit the program with error
        return -1;
    }
}