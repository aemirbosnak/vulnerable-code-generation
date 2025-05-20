//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>
#include <regex.h>

#define TRUE 1
#define FALSE 0

struct curl_slist *headers;

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;

    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize cURL\n");
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 5);
    curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to perform cURL request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    curl_slist_free_all(headers);

    curl_easy_cleanup(curl);

    // Now, let's sanitize the URL

    char *sanitized_url = malloc(strlen(url) + 1);
    if (!sanitized_url) {
        fprintf(stderr, "Failed to allocate memory for sanitized URL\n");
        return EXIT_FAILURE;
    }

    strcpy(sanitized_url, url);

    regex_t regex;
    int reti;

    reti = regcomp(&regex, "https?://(www\\.)?[-a-zA-Z0-9@:%._~#=]+\\.[a-zA-Z0-9()\\-]+([-a-zA-Z0-9()&%_\/~#=]*\\.[a-zA-Z0-9()\\-]+)*", REG_EXTENDED);
    if (reti != 0) {
        fprintf(stderr, "Failed to compile regex\n");
        regfree(&regex);
        return EXIT_FAILURE;
    }

    regmatch_t match[1];
    reti = regexec(&regex, sanitized_url, 1, match, 0);
    if (reti == 0) {
        // URL is valid
        printf("Sanitized URL: %.*s\n", match[0].rm_eo - match[0].rm_so, sanitized_url + match[0].rm_so);
    } else if (reti == REG_NOMATCH) {
        // URL is invalid
        printf("Invalid URL\n");
    } else {
        // Error
        fprintf(stderr, "Error matching regex\n");
        regfree(&regex);
        return EXIT_FAILURE;
    }

    regfree(&regex);

    free(sanitized_url);

    return EXIT_SUCCESS;
}