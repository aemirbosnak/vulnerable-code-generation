//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_URL_LENGTH 2083

// Function Prototypes
void sanitize_url(const char *input, char *output);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    char input_url[BUFFER_SIZE];
    char sanitized_url[MAX_URL_LENGTH];

    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(input_url, argv[1], BUFFER_SIZE - 1);
    input_url[BUFFER_SIZE - 1] = '\0';  // Ensuring null termination

    sanitize_url(input_url, sanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}

// Function to sanitize the URL
void sanitize_url(const char *input, char *output) {
    const char *reserved_chars = "!*'();:@&=+$,/?#[]";
    size_t output_index = 0;

    for (size_t i = 0; input[i] != '\0' && output_index < MAX_URL_LENGTH - 1; i++) {
        if (isalnum((unsigned char)input[i]) || strchr(reserved_chars, input[i])) {
            output[output_index++] = input[i];
        } else {
            // Encode special characters
            output_index += snprintf(output + output_index, MAX_URL_LENGTH - output_index, "%%%02X", (unsigned char)input[i]);
        }
    }

    output[output_index] = '\0';  // Null-terminate the output string
}

// Function to print usage instructions
void print_usage(const char *prog_name) {
    printf("Usage: %s <url>\n", prog_name);
    printf("Sanitizes the provided URL to ensure it conforms to standard URL encoding.\n");
}