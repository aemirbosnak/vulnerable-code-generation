//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom configuration structure
typedef struct {
    int font_size;
    int line_spacing;
    int margin_left;
    int margin_right;
    int margin_top;
    int margin_bottom;
} Config;

// Default configuration values
Config default_config = {
    .font_size = 12,
    .line_spacing = 1,
    .margin_left = 5,
    .margin_right = 5,
    .margin_top = 5,
    .margin_bottom = 5
};

// Load configuration from a file
void load_config(Config *config, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening config file: %s\n", filename);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse each line of the config file
        char *key, *value;
        key = strtok(line, "=");
        value = strtok(NULL, "\n");

        // Set the corresponding configuration value
        if (strcmp(key, "font_size") == 0) {
            config->font_size = atoi(value);
        } else if (strcmp(key, "line_spacing") == 0) {
            config->line_spacing = atoi(value);
        } else if (strcmp(key, "margin_left") == 0) {
            config->margin_left = atoi(value);
        } else if (strcmp(key, "margin_right") == 0) {
            config->margin_right = atoi(value);
        } else if (strcmp(key, "margin_top") == 0) {
            config->margin_top = atoi(value);
        } else if (strcmp(key, "margin_bottom") == 0) {
            config->margin_bottom = atoi(value);
        }
    }

    fclose(file);
}

// Render the ebook page
void render_page(const char *text, Config *config) {
    // Calculate the number of characters that fit on a line
    int line_width = 80 - config->margin_left - config->margin_right;

    // Split the text into lines
    char *line_start = text;
    char *line_end;
    while ((line_end = strchr(line_start, '\n')) != NULL) {
        // Trim trailing whitespace from the line
        while (line_end > line_start && isspace(line_end[-1])) {
            line_end--;
        }

        // Render the line
        for (int i = 0; i < config->margin_left; i++) {
            putchar(' ');
        }
        fwrite(line_start, 1, line_end - line_start, stdout);
        putchar('\n');

        // Advance to the next line
        line_start = line_end + 1;
    }

    // Render the remaining text
    if (*line_start != '\0') {
        // Trim trailing whitespace from the line
        while (*line_start != '\0' && isspace(*line_start)) {
            line_start++;
        }

        // Render the line
        for (int i = 0; i < config->margin_left; i++) {
            putchar(' ');
        }
        puts(line_start);
    }
}

int main(int argc, char **argv) {
    // Load the configuration
    Config config = default_config;
    if (argc > 1) {
        load_config(&config, argv[1]);
    }

    // Read the ebook text from stdin
    char buffer[1024];
    FILE *file = stdin;
    while (fgets(buffer, sizeof(buffer), file)) {
        render_page(buffer, &config);
    }

    return 0;
}