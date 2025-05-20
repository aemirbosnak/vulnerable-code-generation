//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define MAX_FILE_PATH_LENGTH 256
#define MAX_TIMEOUT_SECONDS 10

int check_url(const char* url, const char* file_path) {
    CURL* curl;
    CURLcode res;
    FILE* fp;

    curl = curl_easy_init();
    if (curl) {
        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set timeout
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, MAX_TIMEOUT_SECONDS);

        // Disable output on stdout
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

        // Open file to write response data
        fp = fopen(file_path, "w");
        if (fp) {
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

            // Execute the request and capture the response
            res = curl_easy_perform(curl);

            // Cleanup
            fclose(fp);
            curl_easy_cleanup(curl);

            // Return status
            return (res == CURLE_OK) ? 1 : 0;
        } else {
            // Failed to open file
            curl_easy_cleanup(curl);
            return 0;
        }
    } else {
        // Failed to initialize curl
        return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <url> <file_path>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    char file_path[MAX_FILE_PATH_LENGTH];

    // Copy url and file_path from arguments
    strncpy(url, argv[1], MAX_URL_LENGTH);
    strncpy(file_path, argv[2], MAX_FILE_PATH_LENGTH);

    int status = check_url(url, file_path);

    if (status == 1) {
        printf("SUCCESS: URL is up\n");
    } else {
        printf("ERROR: URL is down or file path is invalid\n");
    }

    return 0;
}