//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>
#include <time.h>

#define MAX_URL_SIZE 1024
#define SAFE_CHARSET "abcdefghijklmnopqrstuvwxyz0123456789-_~."

// Custom function to encode URL
char *encode_url(const char *url) {
    char *encoded_url = malloc(strlen(url) * 4 + 1);
    if (!encoded_url) return NULL;

    char *encoded_ptr = encoded_url;
    const char *url_ptr = url;

    while (*url_ptr) {
        if (strchr(SAFE_CHARSET, *url_ptr)) {
            *encoded_ptr++ = *url_ptr++;
        } else {
            sprintf(encoded_ptr, "%%%02X", *url_ptr++);
            encoded_ptr += 3;
        }
    }

    *encoded_ptr++ = '\0';

    return encoded_url;
}

// Custom function to sanitize URL
char *sanitize_url(char *url) {
    char *sanitized_url = strdup(url);
    if (!sanitized_url) return NULL;

    // Remove whitespace and leading/trailing slashes
    while (*sanitized_url == ' ' || *sanitized_url == '\t' || *sanitized_url == '\n' || *sanitized_url == '\r')
        sanitized_url++;

    size_t len = strlen(sanitized_url);
    while (len > 0 && (sanitized_url[len - 1] == ' ' || sanitized_url[len - 1] == '\t' || sanitized_url[len - 1] == '\n' || sanitized_url[len - 1] == '\r' || sanitized_url[len - 1] == '/'))
        sanitized_url[--len] = '\0';

    // Remove invalid characters
    regex_t regex;
    int ret = regcomp(&regex, "[^a-zA-Z0-9_~-.]", REG_EXTENDED | REG_NOSUB);
    if (ret != 0) {
        regfree(&regex);
        free(sanitized_url);
        return NULL;
    }

    char *sanitized_ptr = sanitized_url;
    while (*sanitized_ptr) {
        if (regexec(&regex, sanitized_ptr, 0, NULL, 0) != 0)
            *sanitized_ptr = '_';
        sanitized_ptr++;
    }

    regfree(&regex);
    return sanitized_url;
}

// Custom function to validate URL
int validate_url(const char *url) {
    if (!url) return 0;

    if (strlen(url) > MAX_URL_SIZE) return 0;

    if (strstr(url, " ") != NULL) return 0;

    if (url[0] == '/' || url[strlen(url) - 1] == '/') return 0;

    if (!strncmp(url, "http://", 7) || !strncmp(url, "https://", 8)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Initialize CURL
    CURL *curl = curl_easy_init();
    if (!curl) return EXIT_FAILURE;

    // Set URL
    char url[MAX_URL_SIZE];
    printf("Enter URL: ");
    scanf("%s", url);

    // Validate URL
    if (!validate_url(url)) {
        printf("Invalid URL.\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    // Sanitize URL
    char *sanitized_url = sanitize_url(url);
    if (!sanitized_url) {
        printf("Failed to sanitize URL.\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    // Encode URL
    char *encoded_url = encode_url(sanitized_url);
    if (!encoded_url) {
        printf("Failed to encode URL.\n");
        free(sanitized_url);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    // Use CURL to fetch and display the webpage
    curl_easy_setopt(curl, CURLOPT_URL, encoded_url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_perform(curl);

    // Cleanup
    free(encoded_url);
    free(sanitized_url);
    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}