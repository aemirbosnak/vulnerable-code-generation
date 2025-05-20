//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 256

typedef struct {
    char **lines;
    size_t count;
    size_t capacity;
} TextBuffer;

// Function prototypes
TextBuffer* create_buffer(size_t initial_capacity);
void destroy_buffer(TextBuffer *buffer);
void add_line(TextBuffer *buffer, const char *line);
void process_text(TextBuffer *buffer);
char* to_uppercase(const char *line);
char* trim_whitespace(const char *line);
void print_lines(TextBuffer *buffer);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    TextBuffer *buffer = create_buffer(10);
    char line[MAX_LINE_LENGTH];

    // Read lines from the file and add them to the buffer
    while (fgets(line, sizeof(line), file)) {
        // Add the line to the buffer
        add_line(buffer, line);
    }

    fclose(file);

    // Process the text in the buffer
    process_text(buffer);

    // Output the processed lines
    print_lines(buffer);

    // Cleanup
    destroy_buffer(buffer);
    return EXIT_SUCCESS;
}

TextBuffer* create_buffer(size_t initial_capacity) {
    TextBuffer *buffer = (TextBuffer*)malloc(sizeof(TextBuffer));
    buffer->lines = (char**)malloc(initial_capacity * sizeof(char*));
    buffer->count = 0;
    buffer->capacity = initial_capacity;
    return buffer;
}

void destroy_buffer(TextBuffer *buffer) {
    for (size_t i = 0; i < buffer->count; i++) {
        free(buffer->lines[i]);
    }
    free(buffer->lines);
    free(buffer);
}

void add_line(TextBuffer *buffer, const char *line) {
    if (buffer->count >= buffer->capacity) {
        buffer->capacity *= 2;
        buffer->lines = (char**)realloc(buffer->lines, buffer->capacity * sizeof(char*));
    }
    buffer->lines[buffer->count] = strdup(line);
    buffer->count++;
}

void process_text(TextBuffer *buffer) {
    for (size_t i = 0; i < buffer->count; i++) {
        char *trimmed = trim_whitespace(buffer->lines[i]);
        char *uppercase = to_uppercase(trimmed);
        free(buffer->lines[i]);
        buffer->lines[i] = uppercase;
        free(trimmed);
    }
}

char* to_uppercase(const char *line) {
    size_t len = strlen(line);
    char *result = (char*)malloc((len + 1) * sizeof(char));
    for (size_t i = 0; i < len; i++) {
        result[i] = toupper((unsigned char)line[i]);
    }
    result[len] = '\0';
    return result;
}

char* trim_whitespace(const char *line) {
    const char *end;
    while (isspace(*line)) line++;
    if (*line == 0) return strdup(""); // Return a new empty string if line is all whitespace
    end = line + strlen(line) - 1;
    while (end > line && isspace(*end)) end--;
    size_t len = end - line + 1;
    char *trimmed = (char*)malloc((len + 1) * sizeof(char));
    strncpy(trimmed, line, len);
    trimmed[len] = '\0';
    return trimmed;
}

void print_lines(TextBuffer *buffer) {
    for (size_t i = 0; i < buffer->count; i++) {
        printf("%s", buffer->lines[i]);
    }
}