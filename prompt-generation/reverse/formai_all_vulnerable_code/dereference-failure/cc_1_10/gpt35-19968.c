//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototype */
void extract_metadata(char *);

/* Main function */
int main(int argc, char *argv[]) {
    /* Check if filename is provided */
    if (argc < 2) {
        printf("Oops! You forgot to provide the filename.\n");
        printf("Try running the program again with a filename.\n");
        return 0;
    }

    printf("Extracting metadata from %s...\n\n", argv[1]);

    /* Pass filename to metadata extraction function */
    extract_metadata(argv[1]);

    printf("All metadata extracted successfully!\n");

    return 0;
}

/* Function to extract metadata from file */
void extract_metadata(char *filename) {
    char buffer[1024];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    /* Open file */
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Oops! Could not open file for reading.\n");
        exit(EXIT_FAILURE);
    }
    
    /* Read file line by line */
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "//@" )) {
            /* Get metadata value */
            char *meta_value = strtok(line+3, "\n");
            /* Get metadata name */
            char *meta_name = strtok(line+3, ":");
            /* Print metadata */
            printf("%s: %s\n", meta_name, meta_value);
        }
    }
    
    /* Free memory */
    free(line);
    fclose(fp);
}