//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256
#define MAX_ATTR_LENGTH 256

// Structure to hold information about XML tags
typedef struct {
    char tag[MAX_TAG_LENGTH];
    char attributes[MAX_ATTR_LENGTH];
} XmlTag;

// Function to trim whitespace from both ends of a string
char* trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ')) end--;

    *(end + 1) = '\0';
    return str;
}

// Function to parse a line and extract XML tag and attributes
int parse_xml_line(const char* line, XmlTag* xmlTag) {
    const char* start = strchr(line, '<');
    const char* end = strchr(line, '>');

    if (start && end && start < end) {
        size_t tag_length = end - start - 1;
        strncpy(xmlTag->tag, start + 1, tag_length);
        xmlTag->tag[tag_length] = '\0';

        // Look for attributes
        char* space_pos = strchr(xmlTag->tag, ' ');
        if (space_pos) {
            size_t attr_length = space_pos - xmlTag->tag;
            strncpy(xmlTag->attributes, space_pos + 1, MAX_ATTR_LENGTH - 1);
            xmlTag->attributes[MAX_ATTR_LENGTH - 1] = '\0';
            xmlTag->tag[attr_length] = '\0';  // remove attributes from tag name
        } else {
            xmlTag->attributes[0] = '\0'; // No attributes
        }
        return 1; // Successfully parsed
    }
    return 0; // Parsing failed
}

// Main function to read an XML file and parse its contents
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <XML_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    XmlTag xmlTag;

    printf("Parsed XML Tags:\n");
    while (fgets(line, sizeof(line), file)) {
        // Trim whitespace from the line
        char* trimmed_line = trim_whitespace(line);
        // Parse the line for XML tags
        if (parse_xml_line(trimmed_line, &xmlTag)) {
            printf("Tag: <%s> - Attributes: %s\n", xmlTag.tag, xmlTag.attributes);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}