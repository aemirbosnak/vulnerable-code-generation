//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024
#define INDENTATION_SPACES 4
#define NEW_LINE "\n"

typedef struct {
    char *data;       // Buffer to store the code
    size_t length;    // Length of the code
} HtmlContent;

HtmlContent* create_html_content() {
    HtmlContent* content = (HtmlContent*)malloc(sizeof(HtmlContent));
    content->data = (char*)malloc(MAX_BUFFER_SIZE);
    content->length = 0;
    return content;
}

void free_html_content(HtmlContent* content) {
    free(content->data);
    free(content);
}

void append_to_html_content(HtmlContent* content, const char* str) {
    size_t str_length = strlen(str);
    if (content->length + str_length < MAX_BUFFER_SIZE) {
        strcpy(content->data + content->length, str);
        content->length += str_length;
    } else {
        fprintf(stderr, "Buffer overflow prevented!\n");
    }
}

void add_indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("%*s", INDENTATION_SPACES, "");
    }
}

void beautify_html(const char* html, HtmlContent* beautified_html) {
    int indent_level = 0;
    bool in_tag = false;
    char current_char;
    
    for (size_t i = 0; i < strlen(html); i++) {
        current_char = html[i];
        
        if (current_char == '<') {
            if (i + 1 < strlen(html) && html[i + 1] == '/') {
                // Closing tag
                indent_level--;
                if (indent_level < 0) indent_level = 0; // Prevent negative indentation
            }
            
            append_to_html_content(beautified_html, NEW_LINE);
            add_indent(indent_level);
            in_tag = true;
            append_to_html_content(beautified_html, "<");
        } else if (current_char == '>') {
            append_to_html_content(beautified_html, ">");
            in_tag = false;

            if (html[i - 1] != '/') {
                indent_level++; // Change in indent level for opening tags
            }
        } else if (!in_tag) {
            append_to_html_content(beautified_html, &current_char);
        } else {
            append_to_html_content(beautified_html, &current_char);
        }
    }
}

void print_beautified_html(HtmlContent* content) {
    printf("%s\n", content->data);
}

int main() {
    const char* html_example = 
        "<html><head><title>Title</title></head><body><div><h1>Hello, World!</h1></div></body></html>";

    HtmlContent* beautified_html = create_html_content();
    beautify_html(html_example, beautified_html);
    print_beautified_html(beautified_html);
    
    free_html_content(beautified_html);
    return 0;
}