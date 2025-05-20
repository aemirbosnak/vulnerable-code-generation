//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_WIDTH 4

void beautify_html(const char *html_content) {
    int len = strlen(html_content);
    int indent_level = 0;
    char output[MAX_LINE_LENGTH] = {0};

    for (int i = 0; i < len; i++) {
        if (html_content[i] == '<') {
            // Check if it's a closing tag
            if (html_content[i + 1] == '/') {
                indent_level--;
            }

            // Print indentation
            for (int j = 0; j < indent_level * INDENT_WIDTH; j++) {
                strcat(output, " ");
            }

            // Print the current tag
            while (html_content[i] != '>' && i < len) {
                char temp[2] = {html_content[i], '\0'};
                strcat(output, temp);
                i++;
            }
            strcat(output, ">");
            strcat(output, "\n");

            // Check if it's an opening tag (not self-closing)
            if (html_content[i - 1] != '/' && html_content[i - 2] != '/') {
                indent_level++;
            }
        } else {
            // Print text content
            if (html_content[i] != '\n' && html_content[i] != '\r') {
                char temp[2] = {html_content[i], '\0'};
                strcat(output, temp);
            }
        }
    }
    
    printf("%s\n", output);
}

int main() {
    FILE *file = fopen("index.html", "r");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    char *html_buffer = (char *)malloc(MAX_LINE_LENGTH * 100); // Allocate memory for the HTML content
    if (!html_buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    size_t bytes_read;
    size_t total_bytes = 0;
    while ((bytes_read = fread(html_buffer + total_bytes, sizeof(char), MAX_LINE_LENGTH - total_bytes, file)) > 0) {
        total_bytes += bytes_read;
    }
    fclose(file);

    // Null terminate the buffer
    html_buffer[total_bytes] = '\0';

    printf("Beautified HTML Output:\n");
    beautify_html(html_buffer);

    free(html_buffer);
    
    return EXIT_SUCCESS;
}