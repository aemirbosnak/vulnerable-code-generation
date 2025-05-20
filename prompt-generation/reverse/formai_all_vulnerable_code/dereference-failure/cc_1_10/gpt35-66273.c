//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100

// Function to parse XML file
void parseXML(char *filename) {
    FILE *fp;
    char ch, buffer[MAX_STRING_LEN], *tag;
    int i = 0, depth = 0;

    // Open XML file
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Cannot open %s\n", filename);
        exit(1);
    }

    // Read file character by character
    while ((ch = fgetc(fp)) != EOF) {
        // Ignore white spaces and new lines
        if (ch == ' ' || ch == '\n')
            continue;
        
        // Handle start tag
        if (ch == '<') {
            // Read tag name
            i = 0;
            while ((ch = fgetc(fp)) != '>' && i < MAX_STRING_LEN - 1) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';

            // Create tag string
            tag = (char *)malloc(strlen(buffer) + 3);
            strcpy(tag, "<");
            strcat(tag, buffer);
            strcat(tag, ">");

            // Print tag
            for (i = 0; i < depth; i++) {
                printf("  ");
            }
            printf("%s\n", tag);
            depth++;

            // Free tag memory
            free(tag);
        }

        // Handle end tag
        if (ch == '/') {
            // Read tag name
            i = 0;
            while ((ch = fgetc(fp)) != '>' && i < MAX_STRING_LEN - 1) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';

            // Decrement depth and print tag
            depth--;
            for (i = 0; i < depth; i++) {
                printf("  ");
            }
            printf("</%s>\n", buffer);
        }

        // Handle tag content
        if (isalnum(ch)) {
            // Read tag content
            i = 0;
            buffer[i++] = ch;
            while ((ch = fgetc(fp)) != '<' && i < MAX_STRING_LEN - 1) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';

            // Print tag content
            for (i = 0; i < depth; i++) {
                printf("  ");
            }
            printf("%s\n", buffer);
        }
    }

    // Close XML file
    fclose(fp);
}

int main() {
    // Parse XML file
    parseXML("example.xml");

    return 0;
}