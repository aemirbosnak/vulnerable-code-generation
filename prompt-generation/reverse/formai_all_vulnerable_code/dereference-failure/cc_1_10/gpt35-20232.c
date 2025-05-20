//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to hold XML data
typedef struct {
    char *tag;
    char *value;
} xml_data;

// Function to parse XML file and extract data
xml_data* parse_xml(char *filename, char *tag) {
    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file '%s'\n", filename);
        return NULL;
    }

    // Create structure to hold XML data
    xml_data *data = (xml_data*) malloc(sizeof(xml_data));
    data->tag = NULL;
    data->value = NULL;

    // Parse file line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Find opening tag
        char *start = strstr(line, "<");
        if (start == NULL) continue;
        start++; // Skip opening bracket
        char *end = strstr(start, ">");
        if (end == NULL) continue;
        *end = '\0'; // Null-terminate tag name

        // Check if tag name matches desired tag
        if (strcmp(start, tag) == 0) {
            data->tag = strdup(start);
            start = end + 1; // Move pointer to tag value
            end = strstr(start, "<"); // Find closing tag
            if (end == NULL) continue;
            *end = '\0'; // Null-terminate value
            data->value = strdup(start);
            break;
        }
    }

    // Close file and return data
    fclose(file);
    return data;
}

int main() {
    // Parse XML file and extract data
    xml_data *data = parse_xml("example.xml", "title");

    // Print extracted data
    printf("Tag: %s\nValue: %s\n", data->tag, data->value);

    // Free memory allocated for data
    free(data->tag);
    free(data->value);
    free(data);

    return 0;
}