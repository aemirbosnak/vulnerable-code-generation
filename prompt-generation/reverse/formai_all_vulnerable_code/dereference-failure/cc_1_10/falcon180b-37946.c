//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the URL
void sanitize_url(char* url) {
    // Remove leading/trailing whitespace
    char* sanitized_url = strdup(url);
    sanitized_url[strcspn(sanitized_url, " ")] = '\0';
    sanitized_url[strcspn(sanitized_url, "\n")] = '\0';

    // Remove any non-ASCII characters
    char* ascii_url = (char*)malloc(MAX_URL_LENGTH);
    int ascii_url_len = 0;

    for (int i = 0; i < strlen(sanitized_url); i++) {
        if (isascii(sanitized_url[i])) {
            ascii_url[ascii_url_len] = sanitized_url[i];
            ascii_url_len++;
        }
    }

    ascii_url[ascii_url_len] = '\0';
    strcpy(sanitized_url, ascii_url);

    free(ascii_url);
}

// Function to download the contents of a URL
size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp) {
    FILE* file = (FILE*)userp;
    return fwrite(buffer, size, nmemb, file);
}

// Function to display usage instructions
void usage() {
    printf("Usage:./url_sanitizer <URL>\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        usage();
        exit(1);
    }

    // Sanitize the URL
    char* url = argv[1];
    sanitize_url(url);

    // Download the contents of the URL
    CURL* curl;
    FILE* file;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        file = fopen("output.txt", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(file);
    }

    curl_global_cleanup();

    return 0;
}