//FormAI DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void print_beautified_code(char* filename);
void write_to_file(char* filename, char* content);

int main(int argc, char** argv) {
    char* filename = argv[1];
    printf("Beautifying code in %s...\n", filename);
    print_beautified_code(filename);
    printf("Finished beautifying code!\n");
    return 0;
}

void print_beautified_code(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: file not found!");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char* indentation = "";
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char* trimmed_line = strtok(line, "\r\n");
        char* token = strtok(trimmed_line, " \t");

        // Skip empty lines
        if (!token) {
            continue;
        }

        // Check if opening tag
        if (strstr(trimmed_line, "<") && strstr(trimmed_line, ">")) {
            printf("%s%s\n", indentation, trimmed_line);
            indentation = strcat(indentation, "  ");
        }
        // Check if closing tag
        else if (strstr(trimmed_line, "</")) {
            indentation[strlen(indentation)-2] = '\0';
            printf("%s%s\n", indentation, trimmed_line);
        }
        // Regular code
        else {
            printf("%s%s\n", indentation, trimmed_line);
        }
    }

    fclose(fp);
}

void write_to_file(char* filename, char* content) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: could not write to file!");
        exit(1);
    }

    fputs(content, fp);
    fclose(fp);
}