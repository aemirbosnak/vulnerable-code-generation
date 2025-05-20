//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048
#define MAX_SANITIZED_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="

bool is_allowed_character(char ch) {
    return strchr(ALLOWED_CHARACTERS, ch) != NULL;
}

void sanitize_url(const char *input_url, char *output_url) {
    size_t output_index = 0;

    for (size_t i = 0; i < strlen(input_url); i++) {
        char current_char = input_url[i];

        if (is_allowed_character(current_char)) {
            if (output_index < MAX_SANITIZED_URL_LENGTH - 1) {
                output_url[output_index++] = current_char;
            }
        } else {
            if (output_index < MAX_SANITIZED_URL_LENGTH - 4) {
                // Convert character to its hexadecimal representation.
                output_index += sprintf(output_url + output_index, "%%%02X", (unsigned char)current_char);
            }
        }
    }

    output_url[output_index] = '\0'; // Null terminate the output string
}

void display_sanitized_url(const char *input_url) {
    char sanitized_url[MAX_SANITIZED_URL_LENGTH];

    sanitize_url(input_url, sanitized_url);
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
}

void process_urls(const char **urls, size_t url_count) {
    for (size_t i = 0; i < url_count; i++) {
        display_sanitized_url(urls[i]);
    }
}

void read_urls_from_file(const char *filename, const char ***urls_out, size_t *url_count_out) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char **urls = NULL;
    size_t url_count = 0;
    size_t buffer_size = 0;
    char *line = NULL;

    while (getline(&line, &buffer_size, file) != -1) {
        // Remove new line character if exists.
        line[strcspn(line, "\n")] = 0;

        // Reallocate memory for the new URL.
        urls = realloc(urls, (url_count + 1) * sizeof(char*));
        urls[url_count] = strdup(line);
        url_count++;
    }

    free(line);
    fclose(file);

    *urls_out = (const char **)urls;
    *url_count_out = url_count;
}

void free_urls(char **urls, size_t url_count) {
    for (size_t i = 0; i < url_count; i++) {
        free(urls[i]);
    }
    free(urls);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url_file.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char **urls = NULL;
    size_t url_count = 0;

    read_urls_from_file(argv[1], &urls, &url_count);
    process_urls(urls, url_count);
    free_urls((char **)urls, url_count);

    return EXIT_SUCCESS;
}