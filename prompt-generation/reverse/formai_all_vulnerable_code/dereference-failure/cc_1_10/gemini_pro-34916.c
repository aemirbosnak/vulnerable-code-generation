//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>

#define URL_SIZE 2048

// Function to validate the URL format
int validate_url(char *url) {
    regex_t regex;

    if (regcomp(&regex, "^(https?://)?(www\\.)?([a-zA-Z0-9._-]+\\.[a-zA-Z]{2,6})(/[a-zA-Z0-9._-]+/?)*", REG_NOSUB) != 0) {
        return 0;
    }

    if (regexec(&regex, url, 0, NULL, 0) != 0) {
        return 0;
    }

    regfree(&regex);
    return 1;
}

// Function to encode special characters in the URL
char *encode_url(char *url) {
    char *encoded_url = malloc(URL_SIZE);

    CURL *curl = curl_easy_init();

    if (!curl) {
        perror("curl_easy_init");
        return NULL;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, encoded_url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform error: %s\n", curl_easy_strerror(res));
        return NULL;
    }

    return encoded_url;
}

// Function to sanitize the URL
char *sanitize_url(char *url) {
    if (!validate_url(url)) {
        printf("Invalid URL: %s\n", url);
        return NULL;
    }

    char *encoded_url = encode_url(url);

    if (!encoded_url) {
        fprintf(stderr, "Could not encode URL: %s\n", url);
        return NULL;
    }

    size_t url_length = strlen(encoded_url);

    // Remove trailing slash if present
    if (encoded_url[url_length - 1] == '/') {
        encoded_url[url_length - 1] = '\0';
    }

    // Remove any leading "www." if present
    if (strncmp(encoded_url, "www.", 4) == 0) {
        memmove(encoded_url, encoded_url + 4, strlen(encoded_url) - 3);
    }

    // Remove any leading "http://" or "https://" if present
    if (strncmp(encoded_url, "http://", 7) == 0) {
        memmove(encoded_url, encoded_url + 7, strlen(encoded_url) - 6);
    } else if (strncmp(encoded_url, "https://", 8) == 0) {
        memmove(encoded_url, encoded_url + 8, strlen(encoded_url) - 7);
    }

    return encoded_url;
}

int main() {
    char url[URL_SIZE];

    printf("Enter the URL you want to sanitize: ");
    scanf("%s", url);

    char *sanitized_url = sanitize_url(url);

    if (sanitized_url) {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    } else {
        printf("Could not sanitize URL.\n");
    }

    return 0;
}