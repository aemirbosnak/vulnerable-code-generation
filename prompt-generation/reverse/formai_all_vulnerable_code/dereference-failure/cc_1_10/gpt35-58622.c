//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAG_LEN 100
#define MAX_ATTRIBS 10

// Structure to hold tag information
typedef struct {
    char name[MAX_TAG_LEN];
    char attribs[MAX_ATTRIBS][MAX_TAG_LEN];
    char values[MAX_ATTRIBS][MAX_TAG_LEN];
    int n_attribs;
} tag_info;

// Function to parse an XML tag and extract all its information
void parse_tag(char* tag_str, tag_info* info) {
    // Clear the info structure
    memset(info, 0, sizeof(tag_info));

    // Extract the tag name
    char* ptr = strchr(tag_str, '<') + 1;  // Skip the opening bracket
    char* end = strchr(ptr, ' ');
    if (end == NULL) {
        end = strchr(ptr, '>');
    }
    strncpy(info->name, ptr, end - ptr);

    // Extract all attributes
    while (*end != '>') {
        ptr = end + 1;
        end = strchr(ptr, '=');  // Attribute name ends at the = sign
        if (end == NULL) {
            break;
        }
        strncpy(info->attribs[info->n_attribs], ptr, end - ptr);
        ptr = end + 2;  // Attribute value starts after the = sign and the opening quote
        end = strchr(ptr, '"');  // Attribute value ends at the closing quote
        strncpy(info->values[info->n_attribs], ptr, end - ptr);
        info->n_attribs++;
    }
}

int main() {
    // Read the XML file into a buffer
    FILE* f = fopen("example.xml", "rb");
    if (f == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);  // Go to the end of the file
    long fsize = ftell(f);  // Get the file size
    fseek(f, 0, SEEK_SET);  // Go back to the beginning of the file
    char* buffer = (char*) malloc(fsize + 1);  // Allocate a buffer to hold the file contents
    fread(buffer, fsize, 1, f);  // Read the file into the buffer
    fclose(f);

    // Parse the XML string
    char* ptr = buffer;
    while (*ptr != '\0') {
        if (*ptr == '<') {
            tag_info info;
            parse_tag(ptr, &info);
            printf("Tag name: %s\n", info.name);
            printf("Attributes:\n");
            for (int i = 0; i < info.n_attribs; i++) {
                printf("%s=%s\n", info.attribs[i], info.values[i]);
            }
        }
        ptr++;
    }

    // Clean up
    free(buffer);
    return 0;
}