//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to beautify HTML code
void beautify(char *filename) {
    FILE *fptr;
    fptr = fopen(filename, "r+");
    FILE *temp;
    temp = fopen("temp.html", "w");

    if (fptr == NULL) {
        printf("File not found");
        exit(1);
    }

    // Variables
    char c, next_c, prev_c;
    int indent_level = 0;
    int tag_level = 0;
    int line_num = 1;

    while ((c = fgetc(fptr)) != EOF) {
        next_c = fgetc(fptr);
        if (next_c == EOF) {
            break;
        }
        // Check if tag element is starting
        if (c == '<' && next_c != '/' && !isspace(prev_c)) {
            tag_level++;
            indent_level++;
            fprintf(temp, "\n");
            for (int i = 0; i < indent_level; ++i) {
                fprintf(temp, "    ");
            }
        }
        // Check if tag element is ending
        else if (c == '<' && next_c == '/') {
            tag_level--;
            indent_level--;
            fprintf(temp, "\n");
            for (int i = 0; i < indent_level; ++i) {
                fprintf(temp, "    ");
            }
        }
        // Check for new line character
        else if (c == '\n') {
            line_num++;
            for (int i = 0; i < indent_level; ++i) {
                fprintf(temp, "    ");
            }
        }
        // Check for tag attribute separator
        else if (c == '>') {
            fprintf(temp, "%c\n", c);
            for (int i = 0; i < indent_level; ++i) {
                fprintf(temp, "    ");
            }
        }
        // Maintain current character in temp file
        else {
            fprintf(temp, "%c", c);
        }

        prev_c = c;
    }

    // Close both files
    fclose(fptr);
    fclose(temp);

    // Replace original file with temp file
    remove(filename);
    rename("temp.html", filename);

    printf("HTML beautified successfully!");
}

int main() {
    beautify("index.html");
    return 0;
}