//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct {
    char tagName[MAX_TAG_LENGTH];
    char tagValue[MAX_TAG_LENGTH];
} XmlNode;

// Function to trim whitespace from a string
void trim(char* str) {
    char *end;

    // Trim leading space
    while (isspace(*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = '\0';
}

// Function to parse a single XML line
int parseXmlLine(char* line, XmlNode* node) {
    char* startTag = strchr(line, '<');
    char* endTag = strchr(line, '>');
    
    if (!startTag || !endTag || startTag > endTag) {
        return 0; // Not a valid XML line or tag
    }

    // Extract tag name
    char* tagName = startTag + 1;
    char* closingTag = strchr(tagName, ' '); // In case of attributes
    if (!closingTag) closingTag = endTag;

    size_t tagNameLength = closingTag - tagName;
    strncpy(node->tagName, tagName, tagNameLength);
    node->tagName[tagNameLength] = '\0';
    
    // Extract tag value
    char* valueStart = endTag + 1;
    char* valueEnd = strchr(valueStart, '<');

    if (valueEnd) {
        size_t valueLength = valueEnd - valueStart;
        strncpy(node->tagValue, valueStart, valueLength);
        node->tagValue[valueLength] = '\0';
        return 1; // Successfully parsed the line
    }
    
    return 0; // No value found
}

// Function to read and parse the XML file
void parseXmlFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    XmlNode node;

    printf("Parsed XML Data:\n");
    while (fgets(line, sizeof(line), file)) {
        trim(line);
        
        if (parseXmlLine(line, &node)) {
            printf("Tag: %s, Value: %s\n", node.tagName, node.tagValue);
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.xml>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseXmlFile(argv[1]);

    return EXIT_SUCCESS;
}