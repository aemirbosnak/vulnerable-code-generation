//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_INDENTATION 100

typedef struct {
    char content[MAX_LINE_LENGTH];
    int indentation_level;
} CodeLine;

char* get_code_filename() {
    char* filename = (char*) malloc(sizeof(char) * MAX_LINE_LENGTH);
    printf("Enter the name of the code file: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    strtok(filename, "\n"); // remove the newline character from the end
    return filename;
}

char* read_file(char* filename) {
    char* file_contents = (char*) malloc(sizeof(char) * MAX_LINE_LENGTH * MAX_LINE_LENGTH);
    
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file could not be opened.\n");
        exit(1);
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        strcat(file_contents, line);
    }
    fclose(fp);
    
    return file_contents;
}

int write_file(char* filename, CodeLine* code_lines, int num_lines) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: file could not be opened.\n");
        exit(1);
    }
    
    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < code_lines[i].indentation_level; j++) {
            fprintf(fp, "\t");
        }
        fprintf(fp, "%s", code_lines[i].content);
    }
    fclose(fp);
    return 0;
}

CodeLine* beautify_code(char* code, int* num_lines) {
    CodeLine* code_lines = (CodeLine*) malloc(sizeof(CodeLine) * MAX_LINE_LENGTH);
    char* token = strtok(code, "\n");
    int indentation = 0;
    int i = 0;
    
    while (token != NULL) {
        CodeLine code_line;
        strcpy(code_line.content, token);
        code_line.indentation_level = indentation;
        
        if (strstr(token, "}") != NULL && indentation > 0) {
            indentation--;
        }
        
        code_lines[i] = code_line;
        i++;
        (*num_lines)++;
        
        if (strstr(token, "{") != NULL) {
            indentation++;
        }
        
        token = strtok(NULL, "\n");
    }
    
    return code_lines;
}

void print_code_lines(CodeLine* code_lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < code_lines[i].indentation_level; j++) {
            printf("\t");
        }
        printf("%s\n", code_lines[i].content);
    }
}

void async_beautify(char* filename) {
    char* code = read_file(filename);
    int num_lines = 0;
    CodeLine* code_lines = beautify_code(code, &num_lines);
    write_file(filename, code_lines, num_lines);
    
    printf("Code successfully beautified!\n");
    free(code_lines);
    free(code);
}

int main() {
    char* filename = get_code_filename();
    async_beautify(filename);
    free(filename);
    return 0;
}