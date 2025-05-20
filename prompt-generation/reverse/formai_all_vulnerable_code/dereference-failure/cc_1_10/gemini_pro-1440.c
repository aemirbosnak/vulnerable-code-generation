//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <stdbool.h>

typedef struct {
    char *url;
    char *cleaned_url;
    bool valid;
} URL_INFO;

int url_compare(const void *a, const void *b) {
    URL_INFO *url1 = (URL_INFO *)a;
    URL_INFO *url2 = (URL_INFO *)b;
    return strcmp(url1->url, url2->url);
}

bool is_valid_url(const char *url) {
    CURLU *urlu;
    CURLUcode urlu_rc;

    urlu = curl_url();
    if (urlu == NULL)
        return false;

    urlu_rc = curl_url_set(urlu, CURLUPART_URL, url, 0);
    if (urlu_rc != CURLE_OK)
        return false;

    urlu_rc = curl_url_get(urlu, CURLUPART_URL, &url, 0);
    if (urlu_rc != CURLE_OK)
        return false;

    curl_url_cleanup(urlu);

    return true;
}

char *sanitize_url(const char *url) {
    CURLU *urlu;
    CURLUcode urlu_rc;
    char *cleaned_url = NULL;

    urlu = curl_url();
    if (urlu == NULL)
        return NULL;

    urlu_rc = curl_url_set(urlu, CURLUPART_URL, url, 0);
    if (urlu_rc != CURLE_OK)
        goto cleanup;

    urlu_rc = curl_url_set(urlu, CURLUPART_USER, NULL, 0);
    if (urlu_rc != CURLE_OK)
        goto cleanup;

    urlu_rc = curl_url_set(urlu, CURLUPART_PASSWORD, NULL, 0);
    if (urlu_rc != CURLE_OK)
        goto cleanup;

    urlu_rc = curl_url_set(urlu, CURLUPART_PORT, NULL, 0);
    if (urlu_rc != CURLE_OK)
        goto cleanup;

    urlu_rc = curl_url_get(urlu, CURLUPART_URL, &cleaned_url, 0);
    if (urlu_rc != CURLE_OK)
        goto cleanup;

cleanup:
    curl_url_cleanup(urlu);

    return cleaned_url;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    URL_INFO *urls = malloc(sizeof(URL_INFO) * argc);
    if (urls == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        URL_INFO url_info = {
            .url = argv[i],
            .cleaned_url = NULL,
            .valid = false
        };
        urls[i - 1] = url_info;
    }

    qsort(urls, argc - 1, sizeof(URL_INFO), url_compare);

    for (int i = 0; i < argc - 1; i++) {
        URL_INFO *url_info = &urls[i];
        url_info->valid = is_valid_url(url_info->url);
        if (url_info->valid) {
            url_info->cleaned_url = sanitize_url(url_info->url);
            if (url_info->cleaned_url == NULL) {
                fprintf(stderr, "Error: Out of memory.\n");
                return EXIT_FAILURE;
            }
        }
    }

    for (int i = 0; i < argc - 1; i++) {
        URL_INFO *url_info = &urls[i];
        if (url_info->valid) {
            printf("Original URL: %s\n", url_info->url);
            printf("Sanitized URL: %s\n\n", url_info->cleaned_url);
            free(url_info->cleaned_url);
        } else {
            printf("Invalid URL: %s\n\n", url_info->url);
        }
    }

    free(urls);

    return EXIT_SUCCESS;
}