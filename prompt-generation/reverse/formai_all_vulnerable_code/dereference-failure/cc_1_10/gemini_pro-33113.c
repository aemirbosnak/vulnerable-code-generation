//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>

// Default configuration values
#define DEFAULT_URL_REGEX "^(http|https)://.*$"
#define DEFAULT_CHAR_TO_REPLACE '*'

// Configuration structure
typedef struct {
    regex_t url_regex;
    char char_to_replace;
} config_t;

// Function to compile the URL regex
int compile_url_regex(config_t *config, const char *regex) {
    int status = regcomp(&config->url_regex, regex, REG_EXTENDED);
    if (status != 0) {
        char error_buffer[256];
        regerror(status, &config->url_regex, error_buffer, sizeof(error_buffer));
        fprintf(stderr, "Error compiling URL regex: %s\n", error_buffer);
        return -1;
    }
    return 0;
}

// Function to set the character to replace
void set_char_to_replace(config_t *config, char c) {
    config->char_to_replace = c;
}

// Function to sanitize a URL
int sanitize_url(config_t *config, char *url) {
    // Match the URL against the regex
    regmatch_t match;
    int status = regexec(&config->url_regex, url, 1, &match, 0);
    if (status != 0) {
        return -1;
    }

    // Replace the matched characters with the specified character
    for (int i = match.rm_so; i < match.rm_eo; i++) {
        url[i] = config->char_to_replace;
    }

    return 0;
}

// Function to free the configuration structure
void free_config(config_t *config) {
    regfree(&config->url_regex);
}

int main(int argc, char **argv) {
    // Initialize the configuration structure
    config_t config;
    compile_url_regex(&config, DEFAULT_URL_REGEX);
    set_char_to_replace(&config, DEFAULT_CHAR_TO_REPLACE);

    // Parse the command-line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *url = argv[1];

    // Sanitize the URL
    if (sanitize_url(&config, url) != 0) {
        fprintf(stderr, "Error sanitizing URL: %s\n", url);
        return EXIT_FAILURE;
    }

    printf("Sanitized URL: %s\n", url);

    // Free the configuration structure
    free_config(&config);

    return EXIT_SUCCESS;
}