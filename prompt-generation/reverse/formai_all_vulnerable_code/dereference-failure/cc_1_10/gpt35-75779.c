//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for holding metadata */
typedef struct metadata {
    char* title;
    char* artist;
    char* album;
    int year;
} Metadata;

/* Function to extract metadata */
Metadata* extract_metadata(char* input_file) {
    
    /* Allocate memory for the metadata struct */
    Metadata* metadata = (Metadata*) malloc(sizeof(Metadata));
    
    /* Read file to extract metadata */
    FILE *fp = fopen(input_file, "r");
    if ( !fp ) {
        printf("Error opening file.");
        return NULL;
    }
    
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* delimiter = ":";
    int line_num = 0;
    
    /* Iterate through each line in the file */
    while ((read = getline(&line, &len, fp)) != -1) {
        
        /* Split the line into key and value */
        char* key = strtok(line, delimiter);
        char* value = strtok(NULL, delimiter);
        
        /* Remove any leading or trailing white space from value */
        char* trimmed_value = NULL;
        if (value) {
            trimmed_value = calloc(strlen(value) + 1, sizeof(char));
            int i = 0;
            while (isspace(value[i])) {
                i++;
            }
            int j = strlen(value) - 1;
            while (isspace(value[j])) {
                j--;
            }
            strncpy(trimmed_value, value + i, j - i + 1);
        }
        
        /* Fill metadata struct with extracted information */
        if (strcmp(key, "Title") == 0) {
            metadata->title = trimmed_value;
        } else if (strcmp(key, "Artist") == 0) {
            metadata->artist = trimmed_value;
        } else if (strcmp(key, "Album") == 0) {
            metadata->album = trimmed_value;
        } else if (strcmp(key, "Year") == 0) {
            metadata->year = atoi(trimmed_value);
        }
        
        /* Free allocated memory */
        free(trimmed_value);
        
        /* Increment line number */
        line_num++;
    }
    
    /* Close file and free allocated memory */
    fclose(fp);
    if (line) {
        free(line);
    }
    
    /* Return the metadata struct */
    return metadata;
}

/* Example usage */
int main() {
    
    /* Extract metadata from sample file */
    Metadata* metadata = extract_metadata("sample.txt");
    
    /* Check if metadata was extracted successfully */
    if (metadata) {
        
        /* Print extracted metadata */
        printf("Title: %s\n", metadata->title);
        printf("Artist: %s\n", metadata->artist);
        printf("Album: %s\n", metadata->album);
        printf("Year: %d\n", metadata->year);
        
        /* Free allocated memory */
        free(metadata->title);
        free(metadata->artist);
        free(metadata->album);
        free(metadata);
        
    } else {
        printf("Error extracting metadata.\n");
    }
    
    return 0;
}