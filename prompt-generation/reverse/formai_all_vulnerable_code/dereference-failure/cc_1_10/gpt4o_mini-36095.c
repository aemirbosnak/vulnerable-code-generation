//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TAG_LENGTH 64

void trim_whitespace(char *str) {
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;
    
    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    
    // Null terminate the string after the last non-whitespace character
    end[1] = '\0';
}

void parse_xml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char tag[MAX_TAG_LENGTH];
    char value[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        char *start_tag = strchr(line, '<');
        char *end_tag = strchr(line, '>');

        if (!start_tag || !end_tag || start_tag == end_tag) {
            continue; // Skip lines without valid tags
        }

        // Extract tag name
        size_t tag_length = end_tag - start_tag - 1;
        if (tag_length >= MAX_TAG_LENGTH) {
            fprintf(stderr, "Tag length exceeds maximum limit.\n");
            continue;
        }
        
        strncpy(tag, start_tag + 1, tag_length);
        tag[tag_length] = '\0'; // Null terminate the tag
        
        // Find value in the line
        char *value_start = end_tag + 1;
        char *value_end = strchr(value_start, '<');
        
        if (value_end) {
            size_t value_length = value_end - value_start;
            if (value_length >= MAX_LINE_LENGTH) {
                fprintf(stderr, "Value length exceeds maximum limit.\n");
                continue;
            }

            strncpy(value, value_start, value_length);
            value[value_length] = '\0'; // Null terminate the value
            
            trim_whitespace(value); // Trim whitespace around the value
            
            // Print out the extracted information
            printf("Tag: %s, Value: %s\n", tag, value);
        }
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_xml(argv[1]);
    
    return EXIT_SUCCESS;
}