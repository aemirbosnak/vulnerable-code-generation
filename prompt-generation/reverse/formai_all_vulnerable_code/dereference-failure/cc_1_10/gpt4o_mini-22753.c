//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 128
#define MAX_ATTRIBUTE_LENGTH 128

// Structure to hold XML tag information
typedef struct {
    char tagName[MAX_TAG_LENGTH];
    char attributes[10][MAX_ATTRIBUTE_LENGTH];
    int attrCount;
} XmlTag;

// Function to read a line from the file
char* readLine(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        return line;
    }
    free(line);
    return NULL;
}

// Function to parse a single XML tag
XmlTag parseXmlTag(const char* line) {
    XmlTag tag;
    memset(&tag, 0, sizeof(XmlTag));

    // Find the tag name (the first word in the string)
    sscanf(line, "<%s", tag.tagName);

    // Extract attributes if any
    char* attrStart = strchr(line, ' ');
    if (attrStart) {
        attrStart++; // Move past the space
        char* attrEnd = strchr(attrStart, '>');
        if (attrEnd) {
            *attrEnd = '\0'; // Null-terminate the attribute string
            char* attr = strtok(attrStart, " ");
            while (attr != NULL && tag.attrCount < 10) {
                strcpy(tag.attributes[tag.attrCount++], attr);
                attr = strtok(NULL, " ");
            }
        }
    }

    return tag;
}

// Function to print an XML tag
void printXmlTag(XmlTag tag) {
    printf("Tag Name: %s\n", tag.tagName);
    printf("Attributes (%d):\n", tag.attrCount);
    for (int i = 0; i < tag.attrCount; i++) {
        printf(" - %s\n", tag.attributes[i]);
    }
}

// The main XML parser function
void parseXmlFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char* line;
    while ((line = readLine(file)) != NULL) {
        if (line[0] == '<' && line[1] != '/') { // Only parse opening tags
            XmlTag tag = parseXmlTag(line);
            printXmlTag(tag);
        }
        free(line);
    }

    fclose(file);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <xml-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting XML parser for file: %s\n", argv[1]);
    parseXmlFile(argv[1]);
    printf("XML parsing finished!\n");

    return EXIT_SUCCESS;
}