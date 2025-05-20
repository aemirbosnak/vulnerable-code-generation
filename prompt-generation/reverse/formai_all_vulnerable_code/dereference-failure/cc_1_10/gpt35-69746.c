//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Struct to hold information about a tag
typedef struct tag_info {
    char *name;
    char **attributes;
    char **values;
    int num_attributes;
    int buffer_size;
} tag_info;

// Initialize a new tag_info struct
tag_info *new_tag_info() {
    tag_info *info = malloc(sizeof(tag_info));
    if (info == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    info->name = NULL;
    info->attributes = NULL;
    info->values = NULL;
    info->num_attributes = 0;
    info->buffer_size = 0;

    return info;
}

// Process a start tag
void process_start_tag(char *buffer, tag_info *info) {
    // Find the start of the tag name
    char *start = strchr(buffer, '<') + 1;
    char *end = strchr(buffer, ' ');
    if (end == NULL) {
        end = strchr(buffer, '>');
    }
    int len = end - start;

    // Extract the tag name
    info->name = malloc(len + 1);
    if (info->name == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    strncpy(info->name, start, len);
    info->name[len] = '\0';

    // Process the attributes
    char *attr_start = end + 1;
    while (*attr_start != '>') {
        // Make sure we have enough space for another attribute
        if (info->num_attributes == info->buffer_size) {
            // Double the buffer size
            info->buffer_size *= 2;
            info->attributes = realloc(info->attributes, info->buffer_size * sizeof(char *));
            info->values = realloc(info->values, info->buffer_size * sizeof(char *));
            if (info->attributes == NULL || info->values == NULL) {
                perror("Error reallocating memory");
                exit(1);
            }
        }

        // Find the attribute name
        start = attr_start;
        end = strchr(attr_start, '=');
        len = end - start;
        info->attributes[info->num_attributes] = malloc(len + 1);
        if (info->attributes[info->num_attributes] == NULL) {
            perror("Error allocating memory");
            exit(1);
        }
        strncpy(info->attributes[info->num_attributes], start, len);
        info->attributes[info->num_attributes][len] = '\0';

        // Find the attribute value
        start = end + 2;
        end = strchr(start, '"');
        if (end == NULL) {
            end = strchr(start, '\'');
        }
        len = end - start;
        info->values[info->num_attributes] = malloc(len + 1);
        if (info->values[info->num_attributes] == NULL) {
            perror("Error allocating memory");
            exit(1);
        }
        strncpy(info->values[info->num_attributes], start, len);
        info->values[info->num_attributes][len] = '\0';

        // Increment the number of attributes
        info->num_attributes++;

        // Move to the next attribute (if any)
        attr_start = end + 1;
    }
}

// Process an end tag
void process_end_tag(char *buffer, tag_info *info) {
    // Find the start of the tag name
    char *start = strchr(buffer, '<') + 2;
    char *end = strchr(buffer, '>') - 1;
    int len = end - start;

    // Make sure the end tag matches the start tag
    if (strncmp(start, info->name, len) != 0) {
        printf("Error: End tag does not match start tag\n");
        exit(1);
    }

    // Free the tag name and attribute information
    free(info->name);
    info->name = NULL;
    for (int i = 0; i < info->num_attributes; i++) {
        free(info->attributes[i]);
        free(info->values[i]);
    }
    free(info->attributes);
    free(info->values);
    info->attributes = NULL;
    info->values = NULL;
    info->num_attributes = 0;
    info->buffer_size = 0;
}

// Process the contents of a tag
void process_contents(char *buffer) {
    printf("%s", buffer);
}

// Main function
int main() {
    // Initialize variables
    FILE *fp;
    char buffer[BUFFER_SIZE];
    tag_info *info = new_tag_info();

    // Open the input file
    fp = fopen("input.xml", "r");
    if (fp == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Read the input file one line at a time
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Process start tags
        if (buffer[0] == '<' && buffer[1] != '/') {
            process_start_tag(buffer, info);
        }
        // Process end tags
        else if (buffer[0] == '<' && buffer[1] == '/') {
            process_end_tag(buffer, info);
        }
        // Process contents
        else {
            process_contents(buffer);
        }
    }

    // Close the input file and free memory
    fclose(fp);
    free(info->name);
    for (int i = 0; i < info->num_attributes; i++) {
        free(info->attributes[i]);
        free(info->values[i]);
    }
    free(info->attributes);
    free(info->values);
    free(info);

    return 0;
}