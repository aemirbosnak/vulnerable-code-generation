//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Function to beautify HTML code */
char *beautify_html(char *html_code)
{
    char *formatted_code = malloc(strlen(html_code) * 2);
    int indent_level = 0;
    int formatted_code_index = 0;

    for(int i = 0; i < strlen(html_code); i++) {
        if(html_code[i] == '<') {
            // Check if it is a closing tag
            if(html_code[i+1] == '/') {
                indent_level--;
            }

            // Indent the current line
            for(int n = 0; n < indent_level; n++) {
                formatted_code[formatted_code_index++] = ' ';
                formatted_code[formatted_code_index++] = ' ';
            }

            // Append the tag to the formatted code
            formatted_code[formatted_code_index++] = html_code[i];
            while(html_code[i] != '>') {
                formatted_code[formatted_code_index++] = html_code[i++];
            }
            formatted_code[formatted_code_index++] = html_code[i];

            // Check if it is an opening tag
            if(html_code[i+1] != '/') {
                indent_level++;
            }

            // Add line breaks
            formatted_code[formatted_code_index++] = '\n';
        } else {
            // Copy the character to the formatted code
            formatted_code[formatted_code_index++] = html_code[i];
        }
    }

    return formatted_code;
}

int main() {
    char *html_code = "<body><div><h1>HTML Beautifier</h1><p>This program beautifies HTML code.</p></div></body>";
    char *formatted_code = beautify_html(html_code);
    printf("Original HTML code:\n%s\n\n", html_code);
    printf("Beautified HTML code:\n%s\n", formatted_code);
    free(formatted_code);
    return 0;
}