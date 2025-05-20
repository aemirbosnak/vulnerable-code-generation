//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Helper function to check if a character is a delimiter
int is_delimiter(char c) {
    char delimiters[] = {' ', '\t', '\n', '\r'};
    int i;
    for(i=0; i<4; i++) {
        if(c == delimiters[i]) {
            return 1;
        }
    }
    return 0;
}

// Main function to beautify the HTML code
void beautify_html(char* input_file, char* output_file) {
    FILE* fin = fopen(input_file, "r");
    if(!fin) {
        printf("Could not open input file.\n");
        exit(1);
    }

    FILE* fout = fopen(output_file, "w");
    if(!fout) {
        printf("Could not open output file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    while(fgets(buffer, BUFFER_SIZE, fin)) {
        int len = strlen(buffer);
        int i;
        for(i=0; i<len; i++) {
            char c = buffer[i];
            if(c == '<') {
                if(is_delimiter(buffer[i+1])) {
                    // Closing tag
                    indent_level--;
                }
                for(int j=0; j<indent_level; j++) {
                    fprintf(fout, "  ");
                }
                fprintf(fout, "%c", c);
                if(!is_delimiter(buffer[i+1])) {
                    // Opening tag
                    indent_level++;
                }
            }
            else {
                fprintf(fout, "%c", c);
            }
        }
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Usage: ./beautify_html <input_file> <output_file>\n");
        exit(1);
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautified successfully.\n");
    return 0;
}