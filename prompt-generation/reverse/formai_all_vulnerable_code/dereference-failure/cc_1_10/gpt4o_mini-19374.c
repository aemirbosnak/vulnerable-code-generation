//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYWORDS 10
#define MAX_BUFFER 1024

// Function to highlight keywords in the HTML
void highlight_keywords(const char *keyword) {
    printf("<span style=\"background-color: yellow;\">%s</span>", keyword);
}

// Reads the HTML file, processes, and highlights the keywords
void process_html(const char *html_content, const char *keywords[], int keyword_count) {
    char buffer[MAX_BUFFER];
    const char *current_pos = html_content;
    
    while (*current_pos) {
        if (*current_pos == '<') {
            // Print the HTML tag directly
            while (*current_pos && *current_pos != '>') {
                putchar(*current_pos++);
            }
            putchar(*current_pos); // Print the closing '>'
            current_pos++;
        } else {
            // Buffer to read text content
            int i = 0;
            while (*current_pos && *current_pos != '<') {
                buffer[i++] = *current_pos++;
            }
            buffer[i] = '\0'; // Null-terminate the string

            // Highlight the keywords in the text
            for (int k = 0; k < keyword_count; k++) {
                char *pos = strstr(buffer, keywords[k]);
                while (pos != NULL) {
                    // Print text before keyword
                    fwrite(buffer, 1, pos - buffer, stdout);
                    highlight_keywords(keywords[k]);
                    
                    // Move buffer after the keyword
                    strncpy(buffer, pos + strlen(keywords[k]), MAX_BUFFER);
                    pos = strstr(buffer, keywords[k]); // Check for more keywords
                }
            }
            // Print any remaining buffer content
            printf("%s", buffer);
        }
    }
}

// Main function to simulate the plugin operation
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_file> [keywords...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *html_file = fopen(argv[1], "r");
    if (!html_file) {
        perror("Failed to open HTML file");
        return EXIT_FAILURE;
    }

    // Read the HTML file content into a buffer
    char *html_content = malloc(MAX_BUFFER);
    size_t content_length = fread(html_content, 1, MAX_BUFFER - 1, html_file);
    html_content[content_length] = '\0'; // Null-terminate

    // Close the HTML file
    fclose(html_file);

    // Gather keywords into an array
    const char *keywords[MAX_KEYWORDS];
    int keyword_count = argc - 2; // Exclude program name and html file path
    if (keyword_count > MAX_KEYWORDS) {
        keyword_count = MAX_KEYWORDS; // Limit to maximum keywords
    }

    for (int i = 0; i < keyword_count; i++) {
        keywords[i] = argv[i + 2];
    }

    // Process HTML file and highlight keywords
    process_html(html_content, keywords, keyword_count);

    // Clean up
    free(html_content);
    return EXIT_SUCCESS;
}