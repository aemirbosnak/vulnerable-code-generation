//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10
#define TAB_SIZE 4

// Enum for different states of the HTML tag traversal process
typedef enum {
    STATE_TEXT,
    STATE_TAG_OPEN,
    STATE_TAG_CLOSE,
    STATE_TAG_SELF_CLOSING,
    STATE_TAG_NAME
} ParseState;

// Structure to hold HTML beautifier configuration
typedef struct {
    int indent_level;
    int current_length;
    char formatted_output[MAX_LINE_LENGTH];
} BeautifierConfig;

// Function to initialize the beautifier configuration
void init_beautifier(BeautifierConfig* config) {
    config->indent_level = 0;
    config->current_length = 0;
    memset(config->formatted_output, 0, sizeof(config->formatted_output));
}

// Function to add indentation based on current indent level
void add_indent(BeautifierConfig* config) {
    for (int i = 0; i < config->indent_level * TAB_SIZE; i++) {
        if (config->current_length < MAX_LINE_LENGTH - 1) {
            config->formatted_output[config->current_length++] = ' ';
        }
    }
}

// Function to process a single line of HTML
void beautify_line(BeautifierConfig* config, const char* line) {
    ParseState state = STATE_TEXT;
    int i = 0;

    while (line[i] != '\0') {
        switch (state) {
            case STATE_TEXT:
                if (line[i] == '<') {
                    // If we have text before a tag, add it to output
                    if (config->current_length > 0) {
                        config->formatted_output[config->current_length++] = '\n';
                    }
                    add_indent(config);
                    state = STATE_TAG_OPEN;
                } else {
                    if (config->current_length < MAX_LINE_LENGTH - 1) {
                        config->formatted_output[config->current_length++] = line[i];
                    }
                }
                break;

            case STATE_TAG_OPEN:
                if (line[i] == '/') {
                    state = STATE_TAG_CLOSE;
                    i++;
                } else if (line[i] == '>') {
                    // Close self-closing tag
                    state = STATE_TEXT;
                    if (++config->current_length < MAX_LINE_LENGTH) {
                        config->formatted_output[config->current_length++] = line[i];
                    }
                } else {
                    state = STATE_TAG_NAME;
                    if (config->current_length < MAX_LINE_LENGTH - 1) {
                        config->formatted_output[config->current_length++] = line[i];
                    }
                    config->indent_level++;
                }
                break;

            case STATE_TAG_CLOSE:
                while (line[i] != '>' && line[i] != '\0') {
                    if (config->current_length < MAX_LINE_LENGTH - 1) {
                        config->formatted_output[config->current_length++] = line[i++];
                    }
                }
                if (line[i] == '>') {
                    config->indent_level--;
                    if (config->current_length < MAX_LINE_LENGTH - 1) {
                        config->formatted_output[config->current_length++] = line[i];
                    }
                    state = STATE_TEXT;
                }
                break;

            case STATE_TAG_NAME:
                if (line[i] == '>') {
                    if (config->current_length < MAX_LINE_LENGTH - 1) {
                        config->formatted_output[config->current_length++] = line[i];
                    }
                    state = STATE_TEXT;
                } else {
                    if (config->current_length < MAX_LINE_LENGTH - 1) {
                        config->formatted_output[config->current_length++] = line[i];
                    }
                }
                break;

            default:
                break;
        }
        i++;
    }
}

// Function to beautify an entire HTML file
void beautify_html_file(const char* input_file, const char* output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    BeautifierConfig config;
    char line[MAX_LINE_LENGTH];

    if (!in) {
        fprintf(stderr, "Error: Unable to open input file: %s\n", input_file);
        return;
    }

    if (!out) {
        fprintf(stderr, "Error: Unable to open output file: %s\n", output_file);
        fclose(in);
        return;
    }

    init_beautifier(&config);

    while (fgets(line, sizeof(line), in)) {
        beautify_line(&config, line);
        if (config.current_length > 0) {
            config.formatted_output[config.current_length] = '\0';
            fprintf(out, "%s\n", config.formatted_output);
            config.current_length = 0;
            memset(config.formatted_output, 0, sizeof(config.formatted_output));
        }
    }

    fclose(in);
    fclose(out);
}

// Main function to execute the beautifier
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html_file(argv[1], argv[2]);
    return EXIT_SUCCESS;
}