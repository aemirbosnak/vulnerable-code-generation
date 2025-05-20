//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 4

void beautify(char *input_file, char *output_file);
void add_indent(FILE *output, int depth);
void print_token(FILE *output, char *token);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *input_file = argv[1];
    char *output_file = argv[2];
    
    beautify(input_file, output_file);
    
    printf("HTML file beautified successfully.\n");
    
    return 0;
}

void beautify(char *input_file, char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    
    if (input == NULL) {
        printf("Error: Cannot open input file %s\n", input_file);
        exit(EXIT_FAILURE);
    }
    
    if (output == NULL) {
        printf("Error: Cannot open output file %s\n", output_file);
        exit(EXIT_FAILURE);
    }
    
    int indent_depth = 0;
    int inside_tag = 0;
    int inside_comment = 0;
    char buffer[1024];
    
    while (fgets(buffer, sizeof(buffer), input)) {
        char *token = strtok(buffer, " \t\n\r");
        
        while (token != NULL) {
            if (strcmp(token, "<") == 0) {
                print_token(output, token);
                token = strtok(NULL, " \t\n\r");
                
                if (strcmp(token, "/") == 0) {
                    indent_depth -= INDENT_SIZE;
                    add_indent(output, indent_depth);
                    inside_tag = 1;
                } else {
                    add_indent(output, indent_depth);
                    indent_depth += INDENT_SIZE;
                    inside_tag = 1;
                }
            } else if (strcmp(token, "/>") == 0) {
                print_token(output, token);
                inside_tag = 0;
            } else if (strcmp(token, ">") == 0) {
                print_token(output, token);
                inside_tag = 0;
            } else if (strcmp(token, "<!") == 0) {
                print_token(output, token);
                token = strtok(NULL, "\n\r");
                
                if (token != NULL && strcmp(token, "--") == 0) {
                    print_token(output, token);
                    inside_comment = 1;
                }
            } else if (strcmp(token, "-->") == 0) {
                print_token(output, token);
                inside_comment = 0;
            } else if (inside_tag == 1) {
                print_token(output, token);
            } else if (inside_comment == 1) {
                print_token(output, token);
            } else {
                add_indent(output, indent_depth);
                print_token(output, token);
            }
            
            token = strtok(NULL, " \t\n\r");
        }
        
        fprintf(output, "\n");
    }
    
    fclose(input);
    fclose(output);
}

void add_indent(FILE *output, int depth) {
    int i;
    
    for (i = 0; i < depth; i++) {
        fprintf(output, " ");
    }
}

void print_token(FILE *output, char *token) {
    fprintf(output, "%s ", token);
}