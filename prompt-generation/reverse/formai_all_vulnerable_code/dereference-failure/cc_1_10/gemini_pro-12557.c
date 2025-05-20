//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_url(char *url) {
    size_t len = strlen(url);
    for (size_t i = 0; i < len; i++) {
        switch (url[i]) {
            case '%':
                if (i + 2 < len && isxdigit(url[i + 1]) && isxdigit(url[i + 2])) {
                    // Decode the hex escape sequence
                    char hex[3] = {url[i + 1], url[i + 2], '\0'};
                    url[i] = (char)strtol(hex, NULL, 16);
                    memmove(url + i + 1, url + i + 3, len - i - 2);
                    len -= 2;
                }
                break;
            case '+':
                url[i] = ' ';
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    sanitize_url(url);

    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}