//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void replace_tabs_with_spaces(char *line, char *updated_line, int tab_size) {
    int index = 0;
    int char_count = 0;
    
    while(line[index] != '\0') {
        if(line[index] == '\t') { // If it's a tab
            int spaces = tab_size - char_count;
            for(int i = 0; i < spaces; i++) {
                updated_line[i] = ' '; // Replace with spaces
            }
            char_count = 0;
            updated_line += spaces;
        }
        else {
            updated_line[0] = line[index]; // Copy over the character
            updated_line++;
            char_count++;
            
            if(line[index] == '>') {
                updated_line[0] = '\n'; // Add newline after close brackets
                updated_line++;
                char_count = 0;
            }
        }
        index++;
    }
    updated_line[0] = '\0'; // Don't forget to terminate the string!
}

void beautify_html(char *filename, int tab_size) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Cannot open file\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *out_fp = fopen("beautified_html.html", "w");
    if(out_fp == NULL) {
        printf("Cannot open output file\n");
        exit(EXIT_FAILURE);
    }
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&line, &len, fp)) != -1) {
        char updated_line[1000] = {0}; // Whatever fits your fancy
        replace_tabs_with_spaces(line, updated_line, tab_size); // Replace tabs with spaces
        fprintf(out_fp, "%s", updated_line); // Write it to file
    }
    
    free(line);
    fclose(fp);
    fclose(out_fp);
}

int main() {
    beautify_html("sample.html", 4); // Assuming you have a sample.html file in the same directory
    printf("File has been beautified and saved to beautified_html.html\n");
    return 0;
}