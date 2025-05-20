//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAB_SIZE 4
#define MAX_LINE_SIZE 1024
#define MAX_DEPTH 10

typedef struct {
    char tag_name[MAX_LINE_SIZE];
    int indent_level;
} StackItem;

int indent_stack_size = 0;
StackItem indent_stack[MAX_DEPTH];

void push_indent(char* tag_name, int level) {
    if (indent_stack_size >= MAX_DEPTH) {
        fprintf(stderr, "Error: Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    StackItem item;
    strcpy(item.tag_name, tag_name);
    item.indent_level = level;
    indent_stack[indent_stack_size++] = item;
}

void pop_indent() {
    if (indent_stack_size <= 0) {
        fprintf(stderr, "Error: Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    indent_stack_size--;
}

bool is_self_closing_tag(char* tag_name) {
    char* self_closing_tags[] = {"img", "br", "hr", "input", "meta", "link", "area", "base", "col", "command", "embed", "keygen", "param", "source", "track", "wbr"};
    int num_tags = sizeof(self_closing_tags) / sizeof(char*);
    for (int i=0; i<num_tags; i++) {
        if (strcmp(tag_name, self_closing_tags[i]) == 0) {
            return true;
        }
    }
    return false;
}

void beautify_html(FILE* input_file, FILE* output_file) {
    char line[MAX_LINE_SIZE];
    int indentation_level = 0;
    
    while (fgets(line, MAX_LINE_SIZE, input_file) != NULL) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        if (strlen(line) == 0) {
            continue;
        }

        // Determine the tag name
        char* start_tag = strchr(line, '<');
        if (start_tag == NULL) {
            // Not a valid HTML tag
            continue;
        }
        start_tag++;
        char* end_tag = strchr(start_tag, '>');
        if (end_tag == NULL) {
            // Not a valid HTML tag
            continue;
        }
        int tag_name_len = end_tag - start_tag;
        if (tag_name_len <= 0 || tag_name_len >= MAX_LINE_SIZE) {
            // Not a valid tag name
            continue;
        }
        char tag_name[MAX_LINE_SIZE];
        strncpy(tag_name, start_tag, tag_name_len);
        tag_name[tag_name_len] = '\0';
        if (tag_name[0] == '/') {
            // This is an end tag
            indentation_level--;
            pop_indent();
        }
        else {
            // This is a start tag
            if (!is_self_closing_tag(tag_name)) {
                push_indent(tag_name, indentation_level++);
            }
        }
        // Add indentation before the line
        for (int i=0; i<indentation_level*TAB_SIZE; i++) {
            fputc(' ', output_file);
        }
        fputs(line, output_file);
        fputc('\n', output_file);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Cannot open input file!\n");
        exit(EXIT_FAILURE);
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Cannot open output file!\n");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}