//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function for CURL
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

// Function to check website uptime
int check_website_uptime(char *url) {
    CURL *curl;
    CURLcode res;
    FILE *fp;

    // Initialize CURL
    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Error initializing CURL\n");
        return 1;
    }

    // Set CURL options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &fp);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Open file for writing
    fp = fopen("website_uptime.html", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return 1;
    }

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error performing the request: %s\n", curl_easy_strerror(res));
        return 1;
    }

    // Close the file
    fclose(fp);

    // Cleanup CURL
    curl_easy_cleanup(curl);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    int result = check_website_uptime(argv[1]);
    if (result == 0) {
        printf("Website is up and running!\n");
    } else {
        printf("Website is down or could not be reached.\n");
    }

    return 0;
}