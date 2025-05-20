//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is a recursive C HTML beautifier which accepts an input file
 * name and output file name as arguments. It reads the input file, formats
 * the HTML code and writes it to the output file. The following rules are
 * applied to beautify the HTML:
 *
 * 1. Indentation is applied to start and end tags, using a 4-space
 *    indentation.
 * 
 * 2. Self-closing tags are formatted on a single line.
 *
 * 3. Comments are formatted with a 2-space indentation.
 *
 * 4. Text nodes are formatted without indentation.
 */ 

// Token types
enum token_type {
    start_tag,
    end_tag,
    self_closing_tag,
    text_node,
    comment
};

// Tokens
struct token {
    enum token_type type;
    char* value;
    struct token* next;
};

// Add a token to the linked list
void add_token(struct token** head_ref, enum token_type type, char* value) {
    struct token* new_token = (struct token*)malloc(sizeof(struct token));
    new_token->type = type;
    new_token->value = value;
    new_token->next = (*head_ref);
    (*head_ref) = new_token;
}

// Free the linked list of tokens
void free_tokens(struct token* head) {
    struct token* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->value);
        free(temp);
    }
}

// Indentation level
int level = 0;

// Write a line to the output file, with appropriate indentation
void write_line(FILE* out_file, char* line) {
    for (int i = 0; i < level; i++) {
        fprintf(out_file, "    ");
    }
    fprintf(out_file, "%s\n", line);
}

// Recursive function to format the tokens and write to the output file
void format_tokens(struct token* current, FILE* out_file) {
    if (current == NULL) {
        return;
    }

    switch (current->type) {
        case start_tag:
            write_line(out_file, current->value);
            level++;
            format_tokens(current->next, out_file);
            level--;
            break;
        case end_tag:
            level--;
            write_line(out_file, current->value);
            format_tokens(current->next, out_file);
            break;
        case self_closing_tag:
            write_line(out_file, current->value);
            format_tokens(current->next, out_file);
            break;
        case text_node:
            write_line(out_file, current->value);
            format_tokens(current->next, out_file);
            break;
        case comment:
            write_line(out_file, current->value);
            format_tokens(current->next, out_file);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* in_file;
    if ((in_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", argv[1]);
        return 1;
    }

    char line[1024];
    struct token* token_list = NULL;

    while (fgets(line, sizeof(line), in_file) != NULL) {
        char* trimmed_line = strdup(line);
        // Strip leading and trailing spaces
        char* end = trimmed_line + strlen(trimmed_line) - 1;
        while (end > trimmed_line && isspace(*end)) {
            *end-- = '\0';
        }
        while (*trimmed_line && isspace(*trimmed_line)) {
            ++trimmed_line;
        }

        if (*trimmed_line == '\0') {
            // Empty line
            continue;
        }

        if (strncmp(trimmed_line, "<!--", 4) == 0) {
            // Comment
            add_token(&token_list, comment, strdup(trimmed_line));
        } else if (strncmp(trimmed_line, "</", 2) == 0) {
            // End tag
            add_token(&token_list, end_tag, strdup(trimmed_line));
        } else if (strncmp(trimmed_line, "<", 1) == 0) {
            // Start tag or self-closing tag
            char* end_char = strstr(trimmed_line, ">");
            if (end_char[-1] == '/') {
                // Self-closing tag
                add_token(&token_list, self_closing_tag, strdup(trimmed_line));
            } else {
                // Start tag
                add_token(&token_list, start_tag, strdup(trimmed_line));
            }
        } else {
            // Text node
            add_token(&token_list, text_node, strdup(trimmed_line));
        }

        free(trimmed_line);
    }

    fclose(in_file);

    FILE* out_file;
    if ((out_file = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", argv[2]);
        return 1;
    }

    format_tokens(token_list, out_file);

    fclose(out_file);

    free_tokens(token_list);

    return 0;
}