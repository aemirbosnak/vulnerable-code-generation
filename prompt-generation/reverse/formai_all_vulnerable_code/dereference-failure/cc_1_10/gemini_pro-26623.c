//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 512

/* Function to sanitize a URL by removing any illegal characters. */
char *sanitize_url(const char *url) {
    char *sanitized_url = NULL;
    int url_length = strlen(url);

    if (url_length == 0) {
        return NULL;
    }

    sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        return NULL;
    }

    int i = 0;
    int j = 0;
    while (i < url_length) {
        char c = url[i];
        if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
            i++;
            continue;
        }
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '/' || c == ':' || c == '@' || c == '&' || c == '=' || c == '?' || c == '#' || c == '~') {
            sanitized_url[j++] = c;
        } else {
            sanitized_url[j++] = '%';
            char hex[3];
            sprintf(hex, "%02X", (unsigned char)c);
            sanitized_url[j++] = hex[0];
            sanitized_url[j++] = hex[1];
        }
        i++;
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

/* Function to perform a GET request to a URL. */
CURLcode perform_get_request(const char *url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl == NULL) {
        return CURLE_FAILED_INIT;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    return res;
}

/* Main function. */
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *sanitized_url = sanitize_url(argv[1]);
    if (sanitized_url == NULL) {
        printf("Failed to sanitize URL.\n");
        return EXIT_FAILURE;
    }

    CURLcode res = perform_get_request(sanitized_url);
    if (res != CURLE_OK) {
        printf("Failed to perform GET request.\n");
        return EXIT_FAILURE;
    }

    printf("GET request performed successfully.\n");

    free(sanitized_url);

    return EXIT_SUCCESS;
}