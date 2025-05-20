//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define the maximum length of a metadata field */
#define MAX_FIELD_LENGTH 50

/* Define the maximum number of metadata fields */
#define MAX_FIELDS 100

/* Define a structure to hold metadata fields */
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char value[MAX_FIELD_LENGTH];
} metadatafield;

/* Define a function to extract metadata from a string */
metadatafield* extract_metadata(char* str, int* size) {
    /* Initialize variables */
    metadatafield* fields = malloc(MAX_FIELDS * sizeof(metadatafield));
    char* field_start = NULL;
    char* field_end = NULL;
    char* value_start = NULL;
    char* value_end = NULL;
    int i = 0;
    int field_length = 0;
    int value_length = 0;
    int field_count = 0;
    /* Loop through the string, looking for metadata fields */
    while (*str != '\0') {
        if (*str == '[') {
            /* This is the start of a new metadata field */
            field_start = str + 1;
            /* Find the end of the field name */
            field_end = strchr(field_start, ']');
            if (field_end != NULL) {
                /* Calculate the length of the field name */
                field_length = field_end - field_start;
                if (field_length > MAX_FIELD_LENGTH - 1) {
                    /* This field name is too long */
                    printf("Error: metadata field name too long.\n");
                    free(fields);
                    return NULL;
                }
                /* Copy the field name into the metadata field */
                strncpy(fields[i].name, field_start, field_length);
                fields[i].name[field_length] = '\0';
                /* Find the start of the field value */
                value_start = field_end + 1;
                /* Find the end of the field value */
                value_end = strchr(value_start, '[');
                if (value_end == NULL) {
                    /* This is the last metadata field */
                    value_end = str + strlen(str) - 1;
                }
                /* Calculate the length of the field value */
                value_length = value_end - value_start;
                if (value_length > MAX_FIELD_LENGTH - 1) {
                    /* This field value is too long */
                    printf("Error: metadata field value too long.\n");
                    free(fields);
                    return NULL;
                }
                /* Copy the field value into the metadata field */
                strncpy(fields[i].value, value_start, value_length);
                fields[i].value[value_length] = '\0';
                /* Increment the field count and move to the next metadata field */
                i++;
                field_count++;
                /* Check if we have reached the maximum number of metadata fields */
                if (field_count > MAX_FIELDS - 1) {
                    /* Too many metadata fields */
                    printf("Error: too many metadata fields.\n");
                    free(fields);
                    return NULL;
                }
            }
        }
        /* Move to the next character */
        str++;
    }
    /* Set the output size */
    *size = field_count;
    /* Return the metadata fields */
    return fields;
}

/* Define a function to print metadata fields */
void print_fields(metadatafield* fields, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", fields[i].name, fields[i].value);
    }
}

/* Main function */
int main() {
    /* Example string with metadata */
    char str[] = "This is an example string with [author]John Smith[/author] and [date]2021-10-07[/date] metadata.";
    /* Extract metadata fields */
    int size = 0;
    metadatafield* fields = extract_metadata(str, &size);
    /* Print metadata fields */
    print_fields(fields, size);
    /* Free the metadata fields */
    free(fields);
    /* End the program */
    return 0;
}