//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function beautifies a given HTML string
void beautify_html(char *html) {

    int count = 0, i;
    char temp[strlen(html)];
    char *p_temp = temp;

    // Remove all white spaces from the HTML string
    while (*html != '\0') {
        if (*html != ' ' && *html != '\t' && *html != '\n') {
            *p_temp++ = *html++;
            count = 0;
        } else {
            html++;
            count++;
        }

        // Ensure a maximum of one blank space is added to the HTML string after each '<'
        if (*html == '<') {
            *p_temp++ = '<';
            html++;
            if (*html != '/') {
                *p_temp++ = ' ';
            }
        }

        // Ensure a maximum of one blank space is added to the HTML string before each '>'
        if (*html == '>') {
            *p_temp++ = '>';
            html++;
            *p_temp++ = '\n';
        }

        // Add appropriate number of tabs after each '>' and before each '<'
        if (*html == '<' && *(html + 1) != '/') {
            for (i = 0; i < count; i++) {
                *p_temp++ = '\t';
            }
        }
    }

    *p_temp = '\0';
    strcpy(html, temp);
}

int main() {

    char html[1000] = "<html><head><title>Sample Title</title></head><body><h1>Sample Heading</h1><p>Sample Paragraph</p></body></html>";
    printf("Original HTML:\n%s\n\n", html);
    beautify_html(html);
    printf("Beautified HTML:\n%s\n", html);
    return 0;
}