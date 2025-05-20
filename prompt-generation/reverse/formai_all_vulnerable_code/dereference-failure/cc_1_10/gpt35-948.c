//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html) {
    int indent_level = 0;
    int i = 0, j = 0, k = 0, l = 0;
    int len = strlen(html);
    char *buf = malloc((len + 1) * sizeof(char));
    if (buf == NULL) {
        printf("Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }

    while (i < len) {
        if (html[i] == '<') {
            if (html[i + 1] == '/') {
                indent_level--;
            }
            for (j = 0; j < indent_level; j++) {
                buf[k++] = '\t';
            }
            buf[k++] = html[i++];
            if (html[i] == '!') {
                l = i;
                while (html[i] != '>') {
                    i++;
                }
                i++;
                for (j = l; j < i; j++) {
                    buf[k++] = html[j];
                }
            } else {
                while (html[i] != '>' && html[i] != '/') {
                    buf[k++] = html[i++];
                }
                if (html[i] == '/') {
                    buf[k++] = '/';
                }
                buf[k++] = html[i++];
                buf[k++] = '\n';
            }
            if (html[i] != '<') {
                for (j = 0; j < indent_level; j++) {
                    buf[k++] = '\t';
                }
                while (html[i] != '<' && html[i] != '\0') {
                    buf[k++] = html[i++];
                }
                buf[k++] = '\n';
            }
            if (html[i] == '<') {
                indent_level++;
            }
        } else {
            buf[k++] = html[i++];
        }
    }
    buf[k] = '\0';
    printf("%s", buf);
    free(buf);
}

int main() {
    char *html = "<html><head><title>Hello World</title></head><body><h1>Hello World</h1><p>This is a test paragraph.</p></body></html>";
    beautify_html(html);
    return 0;
}