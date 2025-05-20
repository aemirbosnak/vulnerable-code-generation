//FormAI DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to beautify HTML code
char* beautifyHTML(char *html) {
    int len = strlen(html);
    int indent_level = 0;
    char *beautified = (char*)malloc(sizeof(char) * (len * 2)); // allocate memory to store beautified code
    int pos = 0;
    int start_tag = 0;
    int prev_char = -1;
    for (int i = 0; i < len; i++) {
        char curr_char = html[i];
        if (prev_char == '<' && curr_char != '/') { // start tag
            if (html[i+1] == '/') {
                indent_level--;
                start_tag--;
            }
            for (int j = 0; j < indent_level; j++) {
                beautified[pos++] = '\t'; // add tabs for indentation
            }
            indent_level++;
            start_tag++;
        }
        if (prev_char == '<' && curr_char == '/') { // end tag
            indent_level--;
            start_tag--;
            for (int j = 0; j < indent_level; j++) {
                beautified[pos++] = '\t'; // add tabs for indentation
            }
        }
        if (start_tag == 0) { // code outside HTML tags
            beautified[pos++] = curr_char;
        } else {
            if (prev_char == '>' && curr_char != '<') { // add space after tag
                beautified[pos++] = ' ';
            }
            beautified[pos++] = curr_char;
        }
        prev_char = curr_char;
    }
    beautified[pos] = '\0'; // terminate string with null character
    return beautified;
}

int main() {
    char html[] = "<html><head><title>My Website</title></head><body><h1>Hello World!</h1></body></html>";
    printf("Original HTML:\n%s\n", html);
    char *beautified = beautifyHTML(html);
    printf("\nBeautified HTML:\n%s\n", beautified);
    free(beautified); // free memory allocated
    return 0;
}