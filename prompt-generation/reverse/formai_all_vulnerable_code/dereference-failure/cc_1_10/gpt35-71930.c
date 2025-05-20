//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESP_LEN (10 * 1024 * 1024) // 10 MB

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_LEN];
    char *resp = NULL;
    long resp_len = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s url\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(url, argv[1], MAX_URL_LEN);

    // Initialize CURL library
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        // Set CURL options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite); // Save response to memory
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resp);
        curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, 1024 * 1024L); // Limit download speed to 1 MB/s

        // Perform HTTP request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            goto cleanup;
        }

        // Get response length
        res = curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD_T, &resp_len);

        if (res == CURLE_OK) {
            printf("Received %ld bytes from %s\n", resp_len, url);
        } else {
            fprintf(stderr, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(res));
        }

        // Print response to stdout
        if (resp_len > 0) {
            printf("%.*s\n", (int) resp_len, resp);
        }

    cleanup:
        // Clean up CURL resources
        curl_easy_cleanup(curl);
        curl_global_cleanup();

        if (resp) {
            free(resp);
        }
    } else {
        fprintf(stderr, "Could not initialize CURL\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}