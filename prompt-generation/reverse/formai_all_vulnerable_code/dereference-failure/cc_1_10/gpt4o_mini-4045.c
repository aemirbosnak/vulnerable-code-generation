//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_SIZE 1024

// Function prototypes
void load_html(const char *filename, char *html);
void modify_text(char *html, const char *old_text, const char *new_text);
void display_html(const char *html);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <html_file> <old_text> <new_text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char html[MAX_HTML_SIZE] = "";
    load_html(argv[1], html);
    modify_text(html, argv[2], argv[3]);
    display_html(html);

    return EXIT_SUCCESS;
}

// Load HTML content from a file
void load_html(const char *filename, char *html) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fread(html, sizeof(char), MAX_HTML_SIZE, file);
    fclose(file);
}

// Modify the HTML by replacing old_text with new_text
void modify_text(char *html, const char *old_text, const char *new_text) {
    char *pos, temp[MAX_HTML_SIZE];
    int index = 0;
    int old_text_len = strlen(old_text);
    int new_text_len = strlen(new_text);
    
    // Use a loop to find and replace all occurrences of old_text with new_text
    while ((pos = strstr(html + index, old_text)) != NULL) {
        strncpy(temp, html, pos - html);
        temp[pos - html] = '\0';
        sprintf(temp + (pos - html), "%s%s", new_text, pos + old_text_len);
        strcpy(html, temp);
        index = pos - html + new_text_len; // Move index after new_text
    }
}

// Display the modified HTML content
void display_html(const char *html) {
    printf("Modified HTML:\n%s\n", html);
}