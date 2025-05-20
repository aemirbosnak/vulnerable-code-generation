//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SAFE_STRLEN 4096

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    char *escaped_url = curl_easy_escape(curl, url, 0);
    if (!escaped_url) {
        fprintf(stderr, "curl_easy_escape() failed\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    char *safe_url = malloc(SAFE_STRLEN);
    if (!safe_url) {
        fprintf(stderr, "malloc() failed\n");
        curl_free(escaped_url);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    strncpy(safe_url, escaped_url, SAFE_STRLEN - 1);
    safe_url[SAFE_STRLEN - 1] = '\0';

    curl_free(escaped_url);

    CURLcode res = curl_easy_setopt(curl, CURLOPT_URL, safe_url);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_setopt(CURLOPT_URL) failed: %s\n", curl_easy_strerror(res));
        free(safe_url);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        free(safe_url);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    long http_code;
    res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_getinfo(CURLINFO_RESPONSE_CODE) failed: %s\n", curl_easy_strerror(res));
        free(safe_url);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    if (http_code != 200) {
        fprintf(stderr, "HTTP error code: %ld\n", http_code);
        free(safe_url);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    free(safe_url);
    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}