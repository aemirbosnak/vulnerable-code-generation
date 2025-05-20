//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

// Callback function to handle HTTP response data
size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    FILE *file = (FILE*)userp;
    return fwrite(ptr, size, nmemb, file);
}

// Function to perform HTTP GET request
void http_get(const char* url, const char* output_file) {
    CURL *curl;
    FILE *file;
    CURLcode res;

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set output file
        file = fopen(output_file, "wb");
        if (!file) {
            fprintf(stderr, "Failed to open output file: %s\n", output_file);
            exit(1);
        }
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        // Perform request
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "HTTP request failed: %s\n", curl_easy_strerror(res));
            exit(1);
        }

        // Cleanup
        curl_easy_cleanup(curl);
        fclose(file);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
        exit(1);
    }
}

int main() {
    http_get("https://jsonplaceholder.typicode.com/posts/1", "output.json");
    return 0;
}