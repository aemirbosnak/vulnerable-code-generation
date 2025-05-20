//FormAI DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

char *read_file(char *path) {
    FILE *file;
    char *buffer;
    long file_size;
    
    file = fopen(path, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", path);
        exit(1);
    }
    
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    buffer = calloc(file_size + 1, sizeof(char));
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for file %s\n", path);
        exit(1);
    }
    
    fread(buffer, sizeof(char), file_size, file);
    
    fclose(file);
    
    return buffer;
}

void write_file(char *path, char *content) {
    FILE *file;
    
    file = fopen(path, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", path);
        exit(1);
    }
    
    fprintf(file, "%s", content);
    
    fclose(file);
}

char *indent_html(char *content) {
    char *indented_content;
    char *line;
    char *token;
    int indent_level = 0;
    int line_number = 1;
    
    indented_content = calloc(strlen(content) + 1, sizeof(char));
    if (indented_content == NULL) {
        printf("Error: Could not allocate memory for indented content\n");
        exit(1);
    }
    
    line = strtok(content, "\n");
    while (line != NULL) {
        token = strtok(line, " ");
        while (token != NULL) {
            if (strcmp(token, "<html>") == 0 || strcmp(token, "<head>") == 0 || strcmp(token, "<body>") == 0) {
                for (int i = 0; i < indent_level; i++) {
                    strcat(indented_content, " ");
                }
                strcat(indented_content, token);
                strcat(indented_content, "\n");
                indent_level += TAB_SIZE;
            } else if (strcmp(token, "</html>") == 0 || strcmp(token, "</head>") == 0 || strcmp(token, "</body>") == 0) {
                indent_level -= TAB_SIZE;
                for (int i = 0; i < indent_level; i++) {
                    strcat(indented_content, " ");
                }
                strcat(indented_content, token);
                strcat(indented_content, "\n");
            } else {
                for (int i = 0; i < indent_level; i++) {
                    strcat(indented_content, " ");
                }
                strcat(indented_content, token);
                strcat(indented_content, " ");
            }
            token = strtok(NULL, " ");
        }
        strcat(indented_content, "\n");
        line = strtok(NULL, "\n");
        line_number++;
    }
    
    return indented_content;
}

int main() {
    char *input_path = "input.html";
    char *output_path = "output.html";
    char *input_content;
    char *indented_content;
    
    input_content = read_file(input_path);
    indented_content = indent_html(input_content);
    write_file(output_path, indented_content);
    
    printf("Indentation of %s complete! Check %s for output.\n", input_path, output_path);
    
    free(input_content);
    free(indented_content);
    
    return 0;
}