//FormAI DATASET v1.0 Category: HTML beautifier ; Style: genious
#include <stdio.h>
#include <string.h>

void beautifyHtml(char *html) {
    char buffer[4096];
    char *index = buffer;

    int indent = 0;
    int length = strlen(html);
    int i, j;

    for (i = 0; i < length; i++) {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                indent -= 2;
            }

            for (j = 0; j < indent; j++) {
                *index++ = ' ';
            }
            *index++ = html[i];
            if (html[i+1] != '/') {
                indent += 2;
            }

            if (html[i+1] == ' ') { // Removing any extra whitespace
                i++;
                while (html[i] != '>') {
                    i++;
                }
                *index++ = '>';
                *index++ = '\n';
            }
            else {
                *index++ = '\n';
            }
        }
        else if (html[i] == '>') {
            *index++ = '>';
            *index++ = '\n';
        }
        else {
            *index++ = html[i];
        }
    }

    *index = '\0';
    strcpy(html, buffer);
}

int main() {
    char html[] = "<html><head><title>My Title</title></head><body><table border='1'><tr><th>Name</th><th>Age</th></tr><tr><td>John</td><td>25</td></tr><tr><td>Anne</td><td>19</td></tr></table></body></html>";

    beautifyHtml(html);

    printf("%s", html);

    return 0;
}