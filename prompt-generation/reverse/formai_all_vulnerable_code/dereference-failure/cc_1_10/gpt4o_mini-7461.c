//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 128

// Function to get the value inside a tag
char* getTagValue(const char* line, const char* tag) {
    char* startTag = (char*)malloc(strlen(tag) + 3);
    sprintf(startTag, "<%s>", tag);
    char* endTag = (char*)malloc(strlen(tag) + 3);
    sprintf(endTag, "</%s>", tag);

    char* start = strstr(line, startTag);
    char* end = start ? strstr(line, endTag) : NULL;
    
    if (start && end) {
        start += strlen(startTag);
        size_t length = end - start;
        char* value = (char*)malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        free(startTag);
        free(endTag);
        return value;
    }

    free(startTag);
    free(endTag);
    return NULL;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    
    // Open the XML file
    file = fopen("example.xml", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file example.xml\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Process lines for tags we are interested in
        char* title = getTagValue(line, "title");
        char* author = getTagValue(line, "author");

        // Print the values if found
        if (title) {
            printf("Title: %s\n", title);
            free(title);
        }
        if (author) {
            printf("Author: %s\n", author);
            free(author);
        }
    }

    // Close the file
    fclose(file);
    return 0;
}