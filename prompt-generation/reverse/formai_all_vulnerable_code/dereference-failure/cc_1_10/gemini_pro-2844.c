//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sanitizes a URL by removing potentially dangerous characters.
char *sanitize_url(const char *url) {
    // Allocate memory for the sanitized URL.
    size_t url_length = strlen(url);
    char *sanitized_url = malloc(url_length + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Initialize the sanitized URL with the original URL.
    strcpy(sanitized_url, url);

    // Iterate over the characters in the sanitized URL.
    for (size_t i = 0; i < url_length; i++) {
        // Identify potentially dangerous characters.
        char c = sanitized_url[i];
        bool is_dangerous = strchr("<>&\"'", c) != NULL;

        // Replace dangerous characters with safe alternatives.
        if (is_dangerous) {
            sanitized_url[i] = '%';
            char hex_digits[3];
            snprintf(hex_digits, 3, "%02X", (unsigned char)c);
            strcat(sanitized_url, hex_digits);
        }
    }

    // Return the sanitized URL.
    return sanitized_url;
}

// Downloads and sanitizes a URL using cURL.
int main(int argc, char **argv) {
    // Ensure that a URL is provided as an argument.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the cURL library.
    CURL *curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Error: Unable to initialize cURL.\n");
        return EXIT_FAILURE;
    }

    // Set the URL to be downloaded.
    char *sanitized_url = sanitize_url(argv[1]);
    if (sanitized_url == NULL) {
        fprintf(stderr, "Error: Unable to sanitize URL.\n");
        return EXIT_FAILURE;
    }
    curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);

    // Set the output file to be written to.
    FILE *output_file = fopen("output.html", "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Unable to open output file.\n");
        return EXIT_FAILURE;
    }
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);

    // Perform the download.
    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
        return EXIT_FAILURE;
    }

    // Clean up.
    curl_easy_cleanup(curl);
    fclose(output_file);
    free(sanitized_url);

    return EXIT_SUCCESS;
}