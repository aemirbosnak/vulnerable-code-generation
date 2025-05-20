//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <string.h>

/* Functions to check whether a character is a whitespace character */
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

/* Function to beautify the HTML code */
void beautify_html(char* code) {
    char* result = "";
    int indent_level = 0;
    int i = 0;
    
    while (code[i] != '\0') {
        if (code[i] == '<') {
            if (code[i+1] == '/') {
                indent_level--;
            }
            for (int j = 0; j < indent_level; j++) {
                strcat(result, "\t");
            }
            strcat(result, "<");
            if (code[i+1] != '!') {
                indent_level++;
            }
            i++;
        }
        else if (code[i] == '>') {
            strcat(result, ">\n");
            i++;
        }
        else {
            if (is_whitespace(code[i])) {
                i++;
            }
            else {
                for (int j = 0; j < indent_level; j++) {
                    strcat(result, "\t");
                }
                while (code[i] != '<' && code[i] != ' ' && code[i] != '>' && code[i] != '\0') {
                    char* c = (char*)malloc(sizeof(char));
                    sprintf(c, "%c", code[i]);
                    strcat(result, c);
                    i++;
                }
                strcat(result, "\n");
            }
        }
    }
    code = result;
}

/* Main function to read the HTML code from a file and beautify it */
int main() {
    FILE* fp;
    char* filename = "input.html";
    char* buffer = "";
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    
    while (!feof(fp)) {
        char* line = NULL;
        size_t len = 0;
        ssize_t read = getline(&line, &len, fp);
        strcat(buffer, line);
    }
    
    fclose(fp);
    
    beautify_html(buffer);
    
    printf("%s", buffer);
    
    return 0;
}