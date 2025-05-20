//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    
    char *input_file = argv[1];
    FILE *input_file_ptr = fopen(input_file, "r");
    if (input_file_ptr == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", input_file);
        exit(1);
    }
    
    char *output_file = strdup(input_file);
    strcat(output_file, ".beautified");
    
    FILE *output_file_ptr = fopen(output_file, "w");
    if (output_file_ptr == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", output_file);
        exit(1);
    }
    
    char line[4096];
    while (fgets(line, sizeof(line), input_file_ptr)!= NULL) {
        char *start = strchr(line, '<');
        char *end = strchr(line, '>');
        if (start == NULL || end == NULL) {
            fprintf(output_file_ptr, "%s", line);
            continue;
        }
        
        int length = (int)(end - start);
        if (length < 0) {
            fprintf(stderr, "Error parsing HTML tag '%s'\n", line);
            exit(1);
        }
        
        char *tag = strndup(start, length);
        char *attrs = strdup(start + length);
        char *value = strndup(end, strlen(end) - 1);
        
        printf("Parsing tag: %s\n", tag);
        printf("Parsing attributes: %s\n", attrs);
        printf("Parsing value: %s\n", value);
        
        // Do some beautification here
        
        // Output the beautified tag
        fprintf(output_file_ptr, "<%s", tag);
        
        // Output the beautified attributes
        char *attribute_name = strtok(attrs, " \t\n\r");
        while (attribute_name!= NULL) {
            fprintf(output_file_ptr, " %s=\"%s\"", attribute_name, value);
            attribute_name = strtok(NULL, " \t\n\r");
        }
        
        // Output the closing tag
        fprintf(output_file_ptr, ">");
        
        // Free the memory
        free(start);
        free(end);
        free(tag);
        free(attrs);
        free(value);
    }
    
    fclose(input_file_ptr);
    fclose(output_file_ptr);
    free(output_file);
    
    return 0;
}