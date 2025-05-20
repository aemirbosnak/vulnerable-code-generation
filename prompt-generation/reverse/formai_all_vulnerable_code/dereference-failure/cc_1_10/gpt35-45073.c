//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void beautify(char *file_name);

int main() {
    char *file_name = "index.html";  // name of the HTML file to beautify
    beautify(file_name);
    return 0;
}

void beautify(char *file_name) {
    FILE *fp, *fq;
    char ch;
    fp = fopen(file_name, "r");  // read mode
    fq = fopen("beautified.html", "w");  // write mode
    
    // if file pointers are null, print error message and exit
    if(fp == NULL || fq == NULL) {
        printf("Error in file handling!\n");
        exit(1);
    }
    
    int indent_level = 0;
    while ((ch = fgetc(fp)) != EOF) {
        // write character to output file
        fputc(ch, fq);
        
        // check for tags and update indent level accordingly
        if (ch == '<') {
            if (fgetc(fp) != '/') {
                indent_level++;
            }
            else {
                indent_level--;
            }
        }
        // add new line character and indentation after closing tag
        else if (ch == '>') {
            if (fgetc(fp) != '<') {
                fputc('\n', fq);
                for (int i = 0; i < indent_level; i++) {
                    fputc('\t', fq);
                }
            }
        }
    }
    fclose(fp);
    fclose(fq);
}