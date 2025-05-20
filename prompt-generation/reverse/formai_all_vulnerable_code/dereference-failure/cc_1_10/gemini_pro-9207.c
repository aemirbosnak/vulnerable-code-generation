//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 2048

// A custom error function that prints a more detailed error message
void curl_error_cb(CURL *handle, int err, const char *msg, void *userdata) {
    (void)handle;
    (void)userdata;

    fprintf(stderr, "cURL error (%d): %s\n", err, msg);
}

// A custom write function that performs URL sanitization
size_t curl_write_cb(char *data, size_t size, size_t nmemb, void *userdata) {
    FILE *fp = (FILE *)userdata;
    size_t total_size = size * nmemb;
    char *sanitized_data = NULL;
    char *p = data;

    // Allocate memory for the sanitized data
    sanitized_data = (char *)malloc(total_size + 1);
    if (!sanitized_data) {
        return 0;
    }

    // Copy the data to the sanitized buffer
    memcpy(sanitized_data, data, total_size);
    sanitized_data[total_size] = '\0';

    // Perform URL sanitization
    for (p = sanitized_data; *p; p++) {
        if (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t') {
            *p = '_';
        }
    }

    // Write the sanitized data to the file
    fwrite(sanitized_data, 1, total_size, fp);

    // Free the sanitized buffer
    free(sanitized_data);

    // Return the original size of the data
    return total_size;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char url[MAX_URL_LEN];
    char output_file[MAX_URL_LEN];

    // Check if the URL was provided as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Copy the URL to a local buffer
    strncpy(url, argv[1], MAX_URL_LEN - 1);
    url[MAX_URL_LEN - 1] = '\0';

    // Create a unique output file name based on the URL
    snprintf(output_file, MAX_URL_LEN, "%s.sanitized", url);

    // Initialize the cURL library
    curl = curl_easy_init();
    if (!curl) {
        return EXIT_FAILURE;
    }

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the error callback function
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_error_cb);

    // Set the write callback function
    fp = fopen(output_file, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Perform the HTTP request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "cURL error: %s\n", curl_easy_strerror(res));
        fclose(fp);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    // Close the output file
    fclose(fp);

    // Cleanup the cURL library
    curl_easy_cleanup(curl);

    // Print a success message
    printf("URL sanitized and saved to: %s\n", output_file);

    return EXIT_SUCCESS;
}