//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static char *sanitize_url(const char *url)
{
    char *sanitized_url = malloc(strlen(url) + 1);
    if (!sanitized_url)
        return NULL;

    char *p = sanitized_url;
    for (; *url; url++) {
        if (*url == '%') {
            if (sscanf(url, "%%%2X", &*p) == 1) {
                url += 2;
                p++;
                continue;
            }
        }
        if (*url == ' ' || *url == '\t' || *url == '\n' || *url == '\r')
            continue;
        *p++ = *url;
    }
    *p = '\0';

    return sanitized_url;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *sanitized_url = sanitize_url(argv[1]);
    if (!sanitized_url) {
        fprintf(stderr, "Error: Failed to sanitize URL\n");
        return EXIT_FAILURE;
    }

    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Failed to initialize CURL\n");
        free(sanitized_url);
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: Failed to perform CURL request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        free(sanitized_url);
        return EXIT_FAILURE;
    }

    curl_easy_cleanup(curl);
    free(sanitized_url);

    return EXIT_SUCCESS;
}