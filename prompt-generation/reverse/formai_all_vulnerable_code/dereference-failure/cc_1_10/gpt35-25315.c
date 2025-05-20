//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void parseXML(char *xmlString);

int main() {
    char xml[MAX_SIZE];
    printf("Enter XML string: ");
    fgets(xml, MAX_SIZE, stdin);

    parseXML(xml);

    return 0;
}

void parseXML(char *xmlString) {
    char *tagContent;
    char *currentTag = "";
    int paranoidLevel = 0;
    int tagStartPosition = 0;
    int tagEndPosition = 0;
    int i = 0;

    while (xmlString[i] != '\0') {

        // If the current character is the start of a tag
        if (xmlString[i] == '<') {
            // If the previous tag wasn't closed properly
            if (paranoidLevel > 0) {
                printf("Error: %s tag not closed properly.\n", currentTag);
                exit(1);
            }
            // Save the start position of the tag
            tagStartPosition = i;
            // Go to the end of the tag to get the tag name
            while (xmlString[i] != '>') {
                // Increment the i variable to move to the end of the tag
                i++;
            }
            // Add one to i to skip over the '>'
            i++;
            // Save the end position of the tag
            tagEndPosition = i;
            // Extract the tag name
            strncpy(currentTag, xmlString + tagStartPosition + 1, tagEndPosition - tagStartPosition - 2);
            currentTag[tagEndPosition - tagStartPosition - 2] = '\0';
        }

        // If the current character is the end of a tag
        if (xmlString[i] == '>' && xmlString[i-1] != '/') {
            paranoidLevel++;
        }

        // If the current character is the start of an end tag
        if (xmlString[i] == '<' && xmlString[i+1] == '/') {
            // Save the start position of the tag
            tagStartPosition = i;
            // Go to the end of the tag to get the tag name
            while (xmlString[i] != '>') {
                // Increment the i variable to move to the end of the tag
                i++;
            }
            // Add one to i to skip over the '>'
            i++;
            // Save the end position of the tag
            tagEndPosition = i;
            // Extract the tag name
            tagContent = strndup(xmlString + tagStartPosition + 2, tagEndPosition - tagStartPosition - 3);
            // Make sure the end tag matches the start tag
            if (strcmp(tagContent, currentTag) != 0) {
                printf("Error: end tag %s does not match start tag %s.\n", tagContent, currentTag);
                exit(1);
            }
            paranoidLevel--;
        }

        // Increment the i variable
        i++;
    }

    // Make sure all tags were closed properly
    if (paranoidLevel != 0) {
        printf("Error: not all tags were closed properly.\n");
        exit(1);
    }

    printf("XML string parsed successfully.\n");
}