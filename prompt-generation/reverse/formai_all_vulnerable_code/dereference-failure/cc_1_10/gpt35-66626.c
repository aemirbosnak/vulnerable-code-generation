//FormAI DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <string.h>

void indent(int indent_level) {
    for (int i=0; i<indent_level; i++) {
        printf("\t");
    }
}

void beautify(char* html, int indent_level) {
    int len = strlen(html);
    // special characters to track if inside an HTML tag
    int in_tag = 0;
    int in_double_quotes = 0;
    int in_single_quotes = 0;
    // loop through each character
    for (int i=0; i<len; i++) {
        char current_char = html[i];
        char next_char = html[i + 1];
        char prev_char = html[i - 1];
        // check if inside tag
        if (current_char == '<') {
            in_tag = 1;
            printf("\n");
            indent(indent_level);
        }
        else if (current_char == '>') {
            in_tag = 0;
        }
        // print current character
        printf("%c", current_char);
        // indenting for multiline HTML
        if (!in_tag && current_char == '\n') {
            indent(indent_level);
        }
        // handle quotes inside tag
        if (in_tag) {
            if (current_char == '"' && prev_char != '\\') {
                in_double_quotes = !in_double_quotes;
            }
            else if (current_char == '\'' && prev_char != '\\') {
                in_single_quotes = !in_single_quotes;
            }
            // indent inside quotes
            if (in_double_quotes || in_single_quotes) {
                if (next_char == '\n') {
                    printf("\n");
                    indent(indent_level + 1);
                }
                else if (next_char == ' ' && prev_char != '\\' && !in_tag) {
                    indent(indent_level + 1);
                }
            }
        }
        // handling closing tags
        if (current_char == '/' && prev_char == '<') {
            indent_level--;
            printf("\n");
            indent(indent_level);
            printf("%c", current_char);
            if (next_char != '>') {
                printf("\n");
                indent(indent_level);
            }
            else {
                in_tag = 0;
            }
        }
        // handling opening tags
        else if (current_char == '<' && next_char != '/') {
            printf("\n");
            indent_level++;
            indent(indent_level);
        }
    }
}

int main() {
    char html[] = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<h1>Heading</h1>\n<p>Paragraph</p>\n</body>\n</html>";
    beautify(html, 0);
    return 0;
}