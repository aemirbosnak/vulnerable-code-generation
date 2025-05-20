//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SPACES 4

void add_indent(char *buffer, int level) {
    for (int i = 0; i < level * INDENT_SPACES; i++) {
        buffer[i] = ' ';
    }
    buffer[level * INDENT_SPACES] = '\0'; // Null-terminate the string
}

bool is_opening_tag(const char *tag) {
    const char *opening_tags[] = {"<html", "<body", "<div", "<span", "<head", "<title", "<p", "<h1", "<h2", "<h3", "<h4", "<h5", "<h6", "<ul", "<ol", "<li", "<table", "<tr", "<td", "<th", "<form", NULL};
    for (int i = 0; opening_tags[i] != NULL; i++) {
        if (strncmp(tag, opening_tags[i], strlen(opening_tags[i])) == 0) {
            return true;
        }
    }
    return false;
}

bool is_closing_tag(const char *tag) {
    const char *closing_tags[] = {"</html", "</body", "</div", "</span", "</head", "</title", "</p", "</h1", "</h2", "</h3", "</h4", "</h5", "</h6", "</ul", "</ol", "</li", "</table", "</tr", "</td", "</th", "</form", NULL};
    for (int i = 0; closing_tags[i] != NULL; i++) {
        if (strncmp(tag, closing_tags[i], strlen(closing_tags[i])) == 0) {
            return true;
        }
    }
    return false;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        fprintf(stderr, "Error opening files!\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    bool new_line = true;

    while (fgets(line, sizeof(line), in)) {
        char formatted_line[MAX_LINE_LENGTH];
        if (strlen(line) == 0) {
            continue; // Skip empty lines
        }

        // Check for opening and closing tags
        if (new_line) {
            add_indent(formatted_line, indent_level);
        } else {
            strcpy(formatted_line, "");
        }

        char *tag_start = strchr(line, '<');
        char *tag_end = strchr(line, '>');
        if (tag_start && tag_end) {
            *tag_end = '\0'; // Temporarily terminate the line
            strcat(formatted_line, line); // Add the line to the formatted output
            strcat(formatted_line, ">"); // Re-add the closing angle bracket

            if (is_opening_tag(tag_start)) {
                indent_level++;
            } else if (is_closing_tag(tag_start)) {
                indent_level--;
            }
        }

        fprintf(out, "%s\n", formatted_line);
        
        new_line = (tag_start != NULL);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification complete! Output written to %s\n", argv[2]);

    return 0;
}