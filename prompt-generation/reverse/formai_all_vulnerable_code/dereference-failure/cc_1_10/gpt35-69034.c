//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_indent(int level) {
    // Prints correct number of spaces for indentation
    int i;
    for(i = 0; i < level; i++) {
        printf("    ");
    }
}

void print_opening_tag(char *tag_name, int level) {
    // Prints opening tag with appropriate indentation
    print_indent(level);
    printf("<%s>\n", tag_name);
}

void print_closing_tag(char *tag_name, int level) {
    // Prints closing tag with appropriate indentation
    print_indent(level);
    printf("</%s>\n", tag_name);
}

void beautify_html(char *html, int level) {
    // Parses and beautifies given HTML string with recursive calls
    char *token;
    char *rest = html;
    int line_count = 0; // Track line count for printing newline before closing tag

    // strtok() will break up string by '<' and '>'
    // If first token does not start with '<', it will print the text outside of markup tags
    while((token = strtok_r(rest, "<>", &rest))) {
        if(token[0] == '/') {
            level--;
        } else {
            print_indent(level);
            printf("%s", token);
            if(token[strlen(token)-1] == '\n') {
                line_count++;
            } else {
                line_count = 0;
            }

            if(strtok_r(rest, "<>", &rest)) {
                // Recursive call if there is markup tag and to close the tag after child tags are processed
                printf("\n");
                beautify_html(rest, level+1);
                print_closing_tag(token, level);
            }
        }

        if(line_count > 0) {
            printf("\n");
        }
    }
}

int main() {
    char *html = "<html>\n<head>\n<title>This is the title</title>\n</head>\n<body>\n<p>This is some text.</p>\n<ul>\n<li>This is a list item.</li>\n<li>This is another list item.</li>\n</ul>\n</body>\n</html>\n";
    beautify_html(html, 0);

    return 0;
}