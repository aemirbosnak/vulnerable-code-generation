//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

// Function declarations
void async_beautifier(char *filename);
void print_usage();
bool is_html_file(char *filename);
char *read_file(char *filename);
char *beautify_html(char *html);
char *strip_whitespace(char *html);
void write_html_file(char *filename, char *html);

// Main
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    // Check if file is HTML
    if (!is_html_file(argv[1])) {
        printf("Error: File is not HTML\n");
        exit(EXIT_FAILURE);
    }

    // Run async as a child process
    pid_t pid = fork();
    if (pid == 0) {
        async_beautifier(argv[1]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}

// Asynchronous beautifier function
void async_beautifier(char *filename) {
    printf("Processing file %s...\n", filename);
    
    // Read HTML file into string variable
    char *html = read_file(filename);
    
    // Beautify HTML
    char *beautified_html = beautify_html(html);
    
    // Write HTML file
    write_html_file(filename, beautified_html);
    
    printf("File %s has been beautified!\n", filename);
}

// Print program usage
void print_usage() {
    printf("HTML Beautifier Program\n");
    printf("Usage: ./beautify [filename]\n");
}

// Check if file is HTML
bool is_html_file(char *filename) {
    int length = strlen(filename);
    char *extension = &filename[length - 4];
    if (strcmp(extension, ".html") == 0 || strcmp(extension, ".htm") == 0) {
        return true;
    } else {
        return false;
    }
}

// Read file into string variable
char *read_file(char *filename) {
    // Open file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Determine file size
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory for file contents
    char *file_contents = (char *) malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Read file into memory
    size_t bytes_read = fread(file_contents, sizeof(char), file_size, fp);
    if (bytes_read != file_size) {
        printf("Error: Unable to read file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Null-terminate string
    file_contents[file_size] = '\0';

    // Close file
    fclose(fp);

    return file_contents;
}

// Beautify HTML
char *beautify_html(char *html) {
    // Strip whitespace
    char *stripped_html = strip_whitespace(html);

    // Loop through HTML string and add indentation
    int indent_level = 0;
    int length = strlen(stripped_html);
    char *beautified_html = (char *) malloc(length * 2 + 1);
    int index = 0;
    for (int i = 0; i < length; i++) {
        char c = stripped_html[i];
        if (c == '<') {
            // Add indentation
            for (int j = 0; j < indent_level; j++) {
                beautified_html[index++] = '\t';
            }
            beautified_html[index++] = '<';

            // Check if closing tag
            if (stripped_html[i + 1] == '/') {
                indent_level--;
            } else {
                indent_level++;
            }
        } else if (c == '>') {
            beautified_html[index++] = '>';
            beautified_html[index++] = '\n';
        } else {
            beautified_html[index++] = c;
        }
    }

    return beautified_html;
}

// Strip whitespace from HTML
char *strip_whitespace(char *html) {
    int length = strlen(html);

    // Allocate memory for stripped HTML
    char *stripped_html = (char *) malloc(length + 1);
    if (stripped_html == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Loop through HTML and strip whitespace
    int index = 0;
    bool inside_tag = false;
    for (int i = 0; i < length; i++) {
        char c = html[i];
        if (c == '<') {
            inside_tag = true;
        } else if (c == '>') {
            inside_tag = false;
        }

        if (!isspace(c) || inside_tag) {
            stripped_html[index++] = c;
        }
    }

    stripped_html[index] = '\0';

    return stripped_html;
}

// Write HTML file
void write_html_file(char *filename, char *html) {
    // Open file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write HTML to file
    fputs(html, fp);

    // Close file
    fclose(fp);
}