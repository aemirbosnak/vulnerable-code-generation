//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 100
#define MAX_TAG_VALUE_LENGTH 256

// Function to trim whitespace from both ends of a string
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;

    end[1] = '\0'; // Null-terminate the trimmed string
    return str;
}

// Function to parse a single XML tag
void parse_tag(char *line) {
    char tag_name[MAX_TAG_NAME_LENGTH];
    char tag_value[MAX_TAG_VALUE_LENGTH];
    
    // Check for opening tag
    if (sscanf(line, "<%s>%[^<</%s>", tag_name, tag_value, tag_name) == 3) {
        printf("Tag: <%s>, Value: \"%s\"\n", trim_whitespace(tag_name), trim_whitespace(tag_value));
    }
    else {
        fprintf(stderr, "Error parsing the line: %s\n", line);
    }
}

// Main function to read XML file and parse it
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        // Check for lines containing tags
        if (strstr(line, "<") != NULL && strstr(line, ">") != NULL) {
            parse_tag(line);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}