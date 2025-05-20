//FormAI DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_HTML_SIZE 10000

void beautify_html(char html[]) {

    int indent_level = 0;
    int inside_tag = 0; 
    int inside_comment = 0; // inside <!-- comment --> block
    char buf[MAX_HTML_SIZE];
    int bufp = 0; // buffer pointer

    for (int p = 0; p < strlen(html); p++) {

        if (html[p] == '<') {
            inside_tag = 1;
            buf[bufp++] = html[p];
            if (html[p+1] == '/') { 
                // closing tag, reduce indent
                indent_level--;
            } else {
                // opening tag, increase indent
                indent_level++;
            }
        } else if (html[p] == '>') {
            inside_tag = 0;
            buf[bufp++] = html[p];
            if (buf[bufp-2] == '-') { 
                // end of <!-- comment --> block, reset inside_comment flag
                inside_comment = 0;
            }
            buf[bufp++] = '\n';
            for (int i = 0; i < indent_level; i++) {
                buf[bufp++] = '\t';
            }
        } else if (html[p] == '-') {
            buf[bufp++] = html[p];
            if (buf[bufp-2] == '<' && buf[bufp-1] == '!' && html[p+1] == '-' && html[p+2] == ' ') { 
                // start of <!-- comment --> block
                inside_comment = 1;
            }
        } else if (!inside_comment && !inside_tag) {
            // not inside <!-- comment --> block or tag, add newline and indentation
            if (html[p] == '\n') {
                buf[bufp++] = html[p];
                for (int i = 0; i < indent_level; i++) {
                    buf[bufp++] = '\t';
                }
            } else {
                buf[bufp++] = html[p];
            }
        } else if (inside_comment) {
            // inside <!-- comment --> block, buffer the characters as-is
            buf[bufp++] = html[p];
        } else {
            buf[bufp++] = html[p];
        }
    }
    buf[bufp] = '\0';

    strcpy(html, buf); // replace original HTML with beautified version
}

int main() {
    char html[] = "<html><head><title>Test</title></head>\n<body>\n<div>\n<h1>Heading</h1>\n<p>Paragraph</p>\n</div>\n</body>\n</html>\n";
    printf("Original:\n%s", html);

    beautify_html(html);
    printf("\nBeautified:\n%s", html);

    return 0;
}